#ifndef SOLVER_H
#define SOLVER_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>

using Eigen::VectorXf;

class Solver {

public:
  Solver(Physics *physics, VectorXf state_vec, float timestep,
         float starttime); // constructor
  Physics *physics;        // object to access eom function
  VectorXf x;              // state vector
  float h;                 // timestemp
  float t;                 // start time
  void propogate();        // move forward in time
  void dispState();

private:
  void rk4(Physics *physics, VectorXf *x, float t, float h);
};

#endif // SOLVER_H
