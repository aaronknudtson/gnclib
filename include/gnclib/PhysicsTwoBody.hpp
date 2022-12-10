#ifndef PHYSICSTWOBODY_H
#define PHYSICSTWOBODY_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::VectorXf;

class PhysicsTwoBody : public Physics {
public:
  PhysicsTwoBody();
  ~PhysicsTwoBody();
  void eom(float t, const VectorXf *x, VectorXf *xdot) override;
  void eom_twobody(const VectorXf *x, Vector3f *a);
  float R_e = 6378.245; // float R_e = 6378.245;
  static const constexpr float M_e = 5.972e24; // float M_d = 5.972e24;
  static const constexpr float Mu_e = 3.986004418e14; // float Mu_e = 3.986004418e14
};

#endif // PHYSICSTWOBODY_H
