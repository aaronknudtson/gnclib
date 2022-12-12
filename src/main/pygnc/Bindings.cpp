#include <Eigen/Core>
#include <pybind11/eigen.h>

#include "gnclib/PhysicsTwoBody.hpp"
#include "gnclib/Solver.hpp"

namespace py = pybind11;

using Eigen::MatrixXd;
using Eigen::VectorXd;

const int svRows = 6;
typedef Matrix<double, 6, 1> StateVector;

constexpr int getSteps(double h, double t0, double t_max) {
  return (t_max - t0) / h;
}

MatrixXd orbitSim(Eigen::Ref<const StateVector> x0, double h, double t0,
                  double t_max) {
  // initialize physics
  PhysicsTwoBody<svRows> physics;

  // initialize state vector
  std::cout << x0 << "\n\n";
  const int steps = getSteps(h, t0, t_max);
  VectorXd t = VectorXd::LinSpaced(steps, t0, t_max);
  MatrixXd x;

  // initialize solver
  Solver<svRows> solver(&physics, x0, h, t0);

  for (int i = 0; i < t.rows(); i++) {
    // create orbit in here
    solver.propogate();
    x.col(i) = solver.x;
  }

  solver.dispState();
  return x;
}

PYBIND11_MODULE(pygnc, handle) {
  handle.doc() = "Hey!";
  handle.def("orbit_sim", &orbitSim,
             py::return_value_policy::reference_internal);
}
