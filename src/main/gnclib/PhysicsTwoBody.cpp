#include "gnclib/PhysicsTwoBody.hpp"

using Eigen::seq;
using Eigen::Vector3f;
using Eigen::VectorXf;

PhysicsTwoBody::PhysicsTwoBody() = default;
PhysicsTwoBody::~PhysicsTwoBody() = default;
void PhysicsTwoBody::eom(float t, const VectorXf *x, VectorXf *xdot) {
  Vector3f a_twobody;
  eom_twobody(x, &a_twobody);
  xdot->block<3, 1>(0, 0) = (*xdot)(seq(3, 6));
  xdot->block<3, 1>(0, 0) = a_twobody;
}

void PhysicsTwoBody::eom_twobody(const VectorXf *x, Vector3f *a) {
  *a = -Mu_e * (*x)(seq(0, 3)) / pow((*x)(seq(0, 2)).norm(), 3);
}
