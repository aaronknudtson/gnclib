#ifndef PHYSICS_H
#define PHYSICS_H

#include <Eigen/Dense>

using Eigen::Matrix;

template <int svRows> class Physics {
public:
  typedef Matrix<float, svRows, 1> StateVector;
  virtual void eom(float t, const StateVector *x, StateVector *xdot) = 0; // {}
};

#endif // PHYSICS_H
