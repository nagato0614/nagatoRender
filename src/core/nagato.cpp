//
// Created by 長井亨 on 2019-08-11.
//

#include "nagato.hpp"
#include <tuple>

namespace nagato {

std::tuple<Vector3f, Vector3f, Vector3f>
OrthonormalBasis(const Vector3f &v) {
    Vector3f v1 = Normalize(v);
    Vector3f v2;
    if (std::abs(v1[0]) > 0.9)
        v2 = {0, 1, 0};
    else
        v2 = {1, 0, 0};

    v2 = Normalize(v2 - Dot(v1, v2) * v1);
    Vector3f v3 = Cross(v1, v2);
    return std::make_tuple(v1, v2, v3);
}
}