#ifndef PHYSICS_H
#define PHYSICS_H

#include <Eigen/Dense>

using Eigen::Matrix;

template <int svRows> class Physics {
public:
  typedef Matrix<double, svRows, 1> StateVector;
  virtual StateVector eom(double t, const StateVector &x) = 0;
};

#endif // PHYSICS_H
