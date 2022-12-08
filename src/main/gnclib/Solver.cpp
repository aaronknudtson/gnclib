#include <Eigen/Dense>
#include <gnclib/Solver.hpp>

using Eigen::VectorXd;

// constructor
Solver::Solver(std::function<VectorXd(float, VectorXd)> func, VectorXd state_vec,
       float timestep, float starttime) {
  f = func;
  x = state_vec;
  h = timestep;
  t = starttime;
};

// TODO: Add more numerical solvers and expose them as algorithm selections
VectorXd Solver::rk4(std::function<VectorXd(float, VectorXd)> f, VectorXd xi,
                     float t, float h) {
  VectorXd k1 = f(t, xi);
  VectorXd k2 = f(t + h / 2, xi + h * k1 / 2);
  VectorXd k3 = f(t + h / 2, xi + h * k2 / 2);
  VectorXd k4 = f(t + h, xi + h * k3);
  return xi + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
};

// public method to propogate solver
VectorXd *Solver::propogate() {
  x = rk4(f, x, t, h);
  t = t + h;
  return &x;
};

void Solver::dispState() {}
