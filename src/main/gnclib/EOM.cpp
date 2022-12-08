#include "gnclib/EOM.hpp"

using Eigen::seq;
using Eigen::Vector3f;
using Eigen::VectorXf;

// is there any way to declare this as the type SolverFn?
void EOM::eom(float t, const VectorXf *x, VectorXf *xdot) {
  // 0, 1, 2 are ri, rj, rk
  // 3, 4, 5 are vi, vj, vk
  Vector3f a = a_drag(*x) + a_twobody(*x);
  *xdot << (*xdot)(seq(3, 6)), a; // overwrite x with new state
}

Vector3f EOM::a_drag(VectorXf x) {}
Vector3f EOM::a_twobody(VectorXf x) {}

float EOM::atmospheric_density() {}
