#ifndef SOLVER_H
#define SOLVER_H

#include "gnclib/Physics.hpp"
#include <Eigen/Dense>
#include <iostream>

template <int rows> class Solver {

public:
  typedef Matrix<float, rows, 1> StateVector;
  // FIELDS
  Physics<rows> *physics; // object to access eom function
  StateVector x;             // state vector
  float h;                // timestemp
  float t;                // start time

  // CONSTRUCTOR
  Solver(Physics<rows> *physics, StateVector state_vec, float timestep,
         float starttime) {
    this->physics = physics;
    this->x = state_vec;
    this->h = timestep;
    this->t = starttime;
  }

  // METHODS
  void propogate() {
    rk4(this->physics, &x, t, h); // update state x
    t = t + h;                    // update state t
  }
  void dispState() { std::cout << x; }

private:
  // TODO: Add more numerical solvers and expose them as algorithm selections
  void rk4(Physics<rows> *physics, StateVector *x, float t, float h) {
    StateVector k1, k2, k3, k4, tmp;
    physics->eom(t, x, &k1);
    tmp = *x + h * k1 / 2;
    physics->eom(t + h / 2, &tmp, &k2);
    tmp = *x + h * k2 / 2;
    physics->eom(t + h / 2, &tmp, &k3);
    tmp = *x + h * k3;
    physics->eom(t + h, &tmp, &k4);
    *x = *x + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
  }
};

#endif // SOLVER_H
