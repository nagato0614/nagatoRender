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
	ASSERT_NEAR(a[0], b[0], 10e-5);
	ASSERT_NEAR(a[1], b[1], 10e-5);
	ASSERT_NEAR(a[2], b[2], 10e-5);
}

}

#endif //NAGATO_RENDER_SRC_TEST_TEST_UTIL_HPP_
