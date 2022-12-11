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
  using Eigen::VectorXd;
  // initialize physics
  // double C_D = 2.2, A = 10, m = 800; // nondim, m^2, kg
  const int svRows = 6;
  typedef Matrix<double, svRows, 1> StateVector;
  PhysicsTwoBody<svRows> physics;

  // initialize state vector
  StateVector x;
  x << 0., -0.1, 1.2, 1.1, 0.1, 0.2;
  x = x * physics.R_e;
  x.block(3, 0, 3, 1) = x.block(3, 0, 3, 1) / physics.TU;

  std::cout << x << "\n\n";
  double h = 10, t0 = 0, t_max = 1000;
  VectorXd t = VectorXd::LinSpaced((t_max - t0) / h, t0, t_max);

  // initialize solver
  Solver<svRows> solver(&physics, x, h, t0);

  for (int i = 0; i < t.rows(); i++) {
    // create orbit in here
    solver.propogate();
    solver.dispState();
  }
  solver.dispState();
}
