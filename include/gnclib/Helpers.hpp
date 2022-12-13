#include <Eigen/Core>

namespace Convert {

using Eigen::Matrix;
using Eigen::Vector3d;

typedef Matrix<double, 6, 1> Vector6d;

void rv2coe(const Vector3d *r, const Vector3d *v, Vector6d *orb);
void rv2coe(const Vector6d *x, Vector6d *orb);
} // namespace Convert
