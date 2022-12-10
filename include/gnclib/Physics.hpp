#ifndef PHYSICS_H
#define PHYSICS_H

#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::VectorXf;

class Physics {
public:
  virtual void eom(float t, const VectorXf *x, VectorXf *xdot) = 0; // {}
};

#endif // PHYSICS_H
