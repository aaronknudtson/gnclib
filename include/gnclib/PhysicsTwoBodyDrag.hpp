#ifndef PHYSICS_TWOBODY_DRAG_H
#define PHYSICS_TWOBODY_DRAG_H

#include "gnclib/PhysicsTwoBody.hpp"
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::VectorXf;

class PhysicsTwoBodyDrag : public PhysicsTwoBody {
public:
  void eom(float t, const VectorXf *x, VectorXf *xdot);
  PhysicsTwoBodyDrag(float C_D, float A, float m);
  void eom_drag(const VectorXf *x, Vector3f *a);

private:
  float atmospheric_density(const VectorXf *x);
  float w = 7.272e-5;
  float C_D;
  float A;
  float m;
};

#endif // PHYSICS_TWOBODY_DRAG_H
