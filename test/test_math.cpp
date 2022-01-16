
#include "gtest/gtest.h"
#include "math.h"
#include <cmath>

TEST (Math, CircleArea)
{
    constexpr float pi = M_PI;
    EXPECT_FLOAT_EQ(circle_area_asm(1.0f), pi);
    EXPECT_FLOAT_EQ(circle_area_cpp(1.0f), pi);
}