#include "gnclib/PhysicsTwoBodyDrag.hpp"

using Eigen::seq;
using Eigen::Vector3f;
using Eigen::VectorXf;

PhysicsTwoBodyDrag::PhysicsTwoBodyDrag(float C_D, float A, float m) {
  this->C_D = C_D;
  this->A = A;
  this->m = m;
}

void PhysicsTwoBodyDrag::eom(float t, const VectorXf *x, VectorXf *xdot) {
  Vector3f a_drag, a_twobody;
  eom_twobody(x, &a_twobody);
  eom_drag(x, &a_drag);
  xdot->block<3, 1>(0, 0) = (*xdot)(seq(3, 6));
  xdot->block<3, 1>(3, 0) = a_twobody + a_drag;
}

void PhysicsTwoBodyDrag::eom_drag(const VectorXf *x, Vector3f *a) {
  float gamma = atmospheric_density(x);
  VectorXf v_vec = (*x)(seq(3, 6));
  Vector3f v_rel = v_vec + Vector3f(w * (*x)(1), w * (*x)(0), 0);
  *a = -1. / 2. * C_D * A / m * gamma * v_vec.norm() * v_rel;
}

float PhysicsTwoBodyDrag::atmospheric_density(const VectorXf *x) {
  float gamma0 = 3.019e-15;                                    // kg / m^3
  float h0 = 1000;                                             // m
  return gamma0 * exp(-((*x)(seq(0, 3)).norm() - R_e) / 1000); // kg / m^3
}
