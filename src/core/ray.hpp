//
// Created by 長井亨 on 2019-08-10.
//

#ifndef NAGATO_RENDER_SRC_CORE_RAY_HPP_
#define NAGATO_RENDER_SRC_CORE_RAY_HPP_

#include "nagato.hpp"

namespace nagato {
class Ray {
 public:
  Ray(const Vector3f &origin, const Vector3f &direction,
      Float tmin = std::numeric_limits<Float>::max(),
      Float tmax_ = std::numeric_limits<Float>::min());
  Vector3f origin_;
  Vector3f direction_;
  Float tmin_;
  Float tmax_;
};
}

#endif //NAGATO_RENDER_SRC_CORE_RAY_HPP_
