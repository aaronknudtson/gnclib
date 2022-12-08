#ifndef SOLVER_H
#define SOLVER_H

#include <Eigen/Dense>

using Eigen::VectorXf;

class Solver {

public:
  typedef std::function<void(float, const VectorXf *, VectorXf *)> SolverFn;
  SolverFn f; // function
  VectorXf x; // state vector
  float h;    // timestemp
  float t;    // start time
  Solver(SolverFn func, VectorXf state_vec, float timestep, float starttime);
  void propogate();
  void dispState();

private:
  void rk4(SolverFn f, VectorXf *xi, float t, float h);
};

#endif // SOLVER_H
