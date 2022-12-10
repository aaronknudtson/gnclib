#include <Eigen/Dense>
#include <gnclib/Solver.hpp>
#include <iostream>

using Eigen::VectorXf;

// constructor
Solver::Solver(Physics *physics, VectorXf state_vec, float timestep,
               float starttime) {
    this->physics = physics;
    this->x = state_vec;
    this->h = timestep;
    this->t = starttime;
};

// TODO: Add more numerical solvers and expose them as algorithm selections
void Solver::rk4(Physics *physics, VectorXf *x, float t, float h) {
  VectorXf k1, k2, k3, k4, tmp;
  physics->eom(t, x, &k1);
  tmp = *x + h * k1 / 2;
  physics->eom(t + h / 2, &tmp, &k2);
  tmp = *x + h * k2 / 2;
  physics->eom(t + h / 2, &tmp, &k3);
  tmp = *x + h * k3;
  physics->eom(t + h, &tmp, &k4);
  *x = *x + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
};

void Solver::propogate() {
  rk4(this->physics, &x, t, h); // update state x
  t = t + h; // update state t
};

void Solver::dispState() {
    std::cout << x;
}
