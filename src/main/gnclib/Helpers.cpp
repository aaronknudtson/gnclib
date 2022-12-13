#include "gnclib/Helpers.hpp"
#include <Eigen/Dense>

using Eigen::Matrix;
using Eigen::Vector3d;

typedef Matrix<double, 6, 1> Vector6d;

void Convert::rv2coe(const Vector3d *rv, const Vector3d *vv, Vector6d *orb) {
    double r = rv->norm(), v = vv->norm();
    Vector3d hv = rv->cross(*vv);
    double h = hv.norm();
    // n = K x hv?
    // Vector3d ev = 
}

void Convert::rv2coe(const Vector6d *x, Vector6d *orb) {
  const Vector3d r = x->block(0, 0, 3, 1);
  const Vector3d v = x->block(3, 0, 3, 1);
  return rv2coe(&r, &v, orb);
}
