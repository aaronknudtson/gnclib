#include "gnclib/Physics.hpp"

using Eigen::seq;
using Eigen::Vector3f;
using Eigen::VectorXf;

// is there any way to declare this as the type SolverFn?
void EOM::eom(float t, const VectorXf *x, VectorXf *xdot) {
  // 0, 1, 2 are ri, rj, rk
  // 3, 4, 5 are vi, vj, vk
  Vector3f a_drag, a_twobody;
  eom_drag(x, &a_drag);
  eom_twobody(x, &a_twobody);
  *xdot << (*xdot)(seq(3, 6)),
      (a_drag +
       a_twobody); // overwrite x with new state and compute acceleration
}

void EOM::eom_drag(const VectorXf *x, Vector3f *a) {
  float gamma = atmospheric_density(x);
  VectorXf v_vec = (*x)(seq(3, 6));
  Vector3f v_rel = v_vec + Vector3f(w * (*x)(1), w * (*x)(0), 0);
  *a = -1. / 2. * C_D * A / m * gamma * v_vec.norm() * v_rel;
}

void EOM::eom_twobody(const VectorXf *x, Vector3f *a) {
  *a = -(*x)(seq(0, 3)) / pow((*x)(seq(0, 2)).norm(), 3);
}

float EOM::atmospheric_density(const VectorXf *x) {
  float gamma0 = 3.019e-15; // kg / m^3
  float h0 = 1000; // m
  return gamma0 * exp(-((*x)(seq(0, 3)).norm() - R_e) / 1000); // kg / m^3
}
