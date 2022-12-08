#ifndef SOLVER_H
#define SOLVER_H

#include <Eigen/Dense>


using Eigen::VectorXd;

class Solver {
private:
  VectorXd rk4(std::function<VectorXd(float, VectorXd)> f, VectorXd xi, float t,
               float h);
public:
  std::function<VectorXd(float, VectorXd)> f; // function
  VectorXd x;                                 // state vector
  float h;                                    // timestemp
  float t;                                    // start time
  Solver(std::function<VectorXd(float, VectorXd)> func, VectorXd state_vec,
         float timestep, float starttime);
  VectorXd *propogate();
  void dispState();
};

#endif // SOLVER_H
