#ifndef EOM_H
#define EOM_H

#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::VectorXf;

class EOM {
public:
  void eom(float t, const VectorXf *x, VectorXf *xdot); //
  void eom_drag(const VectorXf *x, Vector3f *a);
  void eom_twobody(const VectorXf *x, Vector3f *a);

private:
  float atmospheric_density(const VectorXf *x);
  float w = 7.272e-5;
  float R_e = 6378.245;
  float C_D;
  float A;
  float m;
};

#endif // EOM_H
