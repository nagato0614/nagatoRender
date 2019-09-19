//
// Created by 長井亨 on 2019-08-18.
//
#include <gtest/gtest.h>
#include "nagato.hpp"
#include "lambert.hpp"
#include "test_util.hpp"

constexpr int TEST_CASE = 10000;

TEST(BXDF, WORLD_TO_LOCAL) {
    using namespace nagato;

	Lambert lambert(Normalize(MakeRandomVector()), RGB(0));

    for (int i = 0; i < TEST_CASE; i++) {
			auto world_vector = Normalize(MakeRandomVector());
			auto local_vector = lambert.WorldToLocal(world_vector);
        auto converted_vector = lambert.LoacalToWorld(local_vector);
        AssertFloatEQVector3f(world_vector, converted_vector);
    }
}