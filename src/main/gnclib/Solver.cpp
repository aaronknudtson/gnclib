#include <Eigen/Dense>
#include <functional>
#include <gnclib/OrbitSim.hpp>

using Eigen::VectorXd;

class Solver {

// TODO: Add more numerical solvers and expose them as algorithm selections
private:
  VectorXd rk4(std::function<VectorXd(float, VectorXd)> f, VectorXd xi, float t,
               float h) {
    VectorXd k1 = f(t, xi);
    VectorXd k2 = f(t + h / 2, xi + h * k1 / 2);
    VectorXd k3 = f(t + h / 2, xi + h * k2 / 2);
    VectorXd k4 = f(t + h, xi + h * k3);
    return xi + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
  };

public:
  std::function<VectorXd(float, VectorXd)> f; // function
  VectorXd x;                                 // state vector
  float h;                                    // timestemp
  float t;                                    // start time
  Solver(std::function<VectorXd(float, VectorXd)> func, VectorXd state_vec,
         float timestep, float starttime) {
    f = func;
    x = state_vec;
    h = timestep;
    t = starttime;
  };

  VectorXd *propogate() {
    x = rk4(f, x, t, h);
    t = t + h;
    return &x;
  };
};
