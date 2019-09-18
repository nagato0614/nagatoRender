//
// Created by 長井亨 on 2019-08-18.
//

#ifndef NAGATO_RENDER_SRC_TEST_TEST_UTIL_HPP_
#define NAGATO_RENDER_SRC_TEST_TEST_UTIL_HPP_

#include <gtest/gtest.h>

#include "nagato.hpp"

namespace nagato {
Vector3f MakeRandomVector(Float from = -1.0, Float to = 1.0) {
    static Random rnd;
    return Vector3f(
        rnd.uniform_real_distribution<Float>(from, to),
        rnd.uniform_real_distribution<Float>(from, to),
        rnd.uniform_real_distribution<Float>(from, to)
        );
}

void AssertFloatEQVector3f(const Vector3f &a, const Vector3f &b) {
    ASSERT_FLOAT_EQ(a[0], b[0]);
    ASSERT_FLOAT_EQ(a[1], b[1]);
    ASSERT_FLOAT_EQ(a[2], b[2]);
}

}

#endif //NAGATO_RENDER_SRC_TEST_TEST_UTIL_HPP_
