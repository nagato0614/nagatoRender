//
// Created by 長井亨 on 2019-08-18.
//

#ifndef NAGATO_RENDER_SRC_CORE_SAMPLE_HPP_
#define NAGATO_RENDER_SRC_CORE_SAMPLE_HPP_

#include "nagato.hpp"

namespace nagato {
inline Vector3f CosineHemisphereSampling(const Vector2f &uv) {
    const Float z = std::sqrt(1.0f - uv[1]);
    const Float phi = 2.0f * Pi<Float> * uv[0];
    const Float x = std::cos(phi) * std::sqrt(uv[1]);
    const Float y = std::sin(phi) * std::sqrt(uv[1]);
    return Vector3f(x, y, z);
}
}
#endif //NAGATO_RENDER_SRC_CORE_SAMPLE_HPP_
