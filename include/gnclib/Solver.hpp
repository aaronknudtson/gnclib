#ifndef SOLVER_H
#define SOLVER_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>
#include <iostream>

template <int rows> class Solver {

public:
  typedef Matrix<double, rows, 1> StateVector;
  // FIELDS
  Physics<rows> *physics; // object to access eom function
  StateVector x;          // state vector
  double h;               // timestemp
  double t;               // start time

  // CONSTRUCTOR
  Solver(Physics<rows> *physics, StateVector state_vec, double timestep,
         double starttime) {
    this->physics = physics;
    this->x = state_vec;
    this->h = timestep;
    this->t = starttime;
  }

  // METHODS
  void propogate() {
    x = rk4(this->physics, x, t, h); // update state x
    t = t + h;                       // update state t
  }
  void dispState() { std::cout << "State at t=" << t << ":\n" << x << "\n"; }

private:
  // TODO: Add more numerical solvers and expose them as algorithm selections
  StateVector rk4(Physics<rows> *physics, const StateVector &x, double t,
                  double h) {
    StateVector tmp;
    StateVector k1 = physics->eom(t, x);
    tmp = x + h * k1 / 2;
    StateVector k2 = physics->eom(t + h / 2, tmp);
    tmp = x + h * k2 / 2;
    StateVector k3 = physics->eom(t + h / 2, tmp);
    tmp = x + h * k3;
    StateVector k4 = physics->eom(t + h, tmp);
    return x + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
  }
};

#endif // SOLVER_H
