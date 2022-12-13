#ifndef PHYSICSTWOBODY_H
#define PHYSICSTWOBODY_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>
#include <iostream>

using Eigen::Matrix;
using Eigen::Vector3d;

template <int rows = 6> class PhysicsTwoBody : public Physics<rows> {
public:
  const double DU = 6378.245;        // km / DU
  const double R_e = DU;             // km
  const double TU = 13.45 * 60;      // sec / TU
  const double M_e = 5.972e24;       // kg
  const double Mu_e = 3.986004418e5; // km^3 / s^2 3.986004418e14 in m

  typedef Matrix<double, rows, 1> StateVector;

  StateVector eom(double t, const StateVector &x) override {
    // more readable version:
    // Vector3d a_twobody = eom_twobody(x);
    // StateVector xdot;
    // xdot.block(0, 0, 3, 1) = x.block(3, 0, 3, 1);
    // xdot.block(3, 0, 3, 1) = eom_twobody(x);

    // oneline (I think no copies?)
    return (StateVector() << x.block(3, 0, 3, 1), eom_twobody(x)).finished();
  }

  Vector3d eom_twobody(const StateVector &x) {
    return -Mu_e * x.block(0, 0, 3, 1) / pow(x.block(0, 0, 3, 1).norm(), 3);
  }
};

#endif // PHYSICSTWOBODY_H
