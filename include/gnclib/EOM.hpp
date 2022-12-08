#ifndef EOM_H
#define EOM_H

#include <Eigen/Dense>
#include <gnclib/Solver.hpp>

using Eigen::Vector3f;
using Eigen::VectorXf;

class EOM {
public:
  // Solver::SolverFn eom;
  void eom(float t, const VectorXf *x, VectorXf* xdot); //
  Vector3f a_drag(VectorXf x);
  Vector3f a_twobody(VectorXf x);

private:
  float atmospheric_density();
};

#endif // EOM_H
