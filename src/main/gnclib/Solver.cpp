#include <Eigen/Dense>
#include <gnclib/Solver.hpp>

using Eigen::VectorXf;

// constructor
Solver::Solver(SolverFn func, VectorXf state_vec, float timestep,
               float starttime) {
  f = func;
  x = state_vec;
  h = timestep;
  t = starttime;
};

// TODO: Add more numerical solvers and expose them as algorithm selections
void Solver::rk4(SolverFn f, VectorXf *x, float t, float h) {
  VectorXf k1, k2, k3, k4, tmp;
  f(t, x, &k1);
  tmp = *x + h * k1 / 2;
  f(t + h / 2, &tmp, &k2);
  tmp = *x + h * k2 / 2;
  f(t + h / 2, &tmp, &k3);
  tmp = *x + h * k3;
  f(t + h, &tmp, &k4);
  *x = *x + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
};

void Solver::propogate() {
  rk4(f, &x, t, h); // update state x
  t = t + h; // update state t
};

void Solver::dispState() {}
