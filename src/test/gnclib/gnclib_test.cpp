#include <Eigen/Dense>
#include <gtest/gtest.h>
#include <iostream>

#include "gnclib/PhysicsTwoBody.hpp"
#include <gnclib/Solver.hpp>

TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(OrbitTest, BasicAssertions) {
  // initialize physics
  // float C_D = 2.2, A = 10, m = 800; // nondim, m^2, kg
  PhysicsTwoBody physics;

  // initialize state vector
  Eigen::Matrix<float, 6, 1> x;
  x << 0., -0.1, 1.2, 1.1, 0.1, 0.2;
  std::cout << "Hello world!\n\n\n\n\n"; // currently works
  x = x * physics.R_e;
  float h = 10, t0 = 0, t_max = 10000;
  VectorXf t = VectorXf::LinSpaced(h, t0, t_max);

  // initialize solver
  Solver solver(&physics, x, h, t0);

  for (int i = 0; i < t.rows(); i++) {
    // create orbit in here
    solver.propogate();
  }
  solver.dispState();
}
