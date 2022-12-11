#ifndef PHYSICSTWOBODY_H
#define PHYSICSTWOBODY_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>
#include <iostream>

using Eigen::Matrix;
using Eigen::seq;
using Eigen::Vector3f;

template <int rows = 6> class PhysicsTwoBody : public Physics<rows> {
public:
  float R_e = 6378.245;                        // float R_e = 6378.245;
  static const constexpr float M_e = 5.972e24; // float M_d = 5.972e24;
  static const constexpr float Mu_e =
      3.986004418e14; // float Mu_e = 3.986004418e14

  typedef Matrix<float, rows, 1> StateVector;

  void eom(float t, const StateVector *x, StateVector *xdot) override {
    Vector3f a_twobody;
    eom_twobody(x, &a_twobody);
    std::cout << "first" << *xdot << "\nthen\n";
    xdot->block(0, 0, 3, 1) = (*xdot)(seq(3, 5));
    xdot->block(3, 0, 3, 1) = a_twobody;
    std::cout << *xdot << "\n";
  }

  void eom_twobody(const StateVector *x, Vector3f *a) {
    *a = -Mu_e * (*x)(seq(0, 2)) / pow((*x)(seq(0, 2)).norm(), 3);
  }
};

#endif // PHYSICSTWOBODY_H
