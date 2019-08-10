//
// Created by 長井亨 on 2019-08-10.
//

#include "ray.hpp"

namespace nagato {

Ray::Ray(const Vector3f &origin, const Vector3f &direction, Float tmin, Float tmax)
    : origin_(origin), direction_(direction), tmin_(tmin), tmax_(tmax) {}
}
