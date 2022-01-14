
#include "gtest/gtest.h"
#include "math.h"
#include <cmath>

TEST (Math, CircleArea)
{
    float pi = M_PI;
    EXPECT_FLOAT_EQ(circle_area_asm(1.0f), pi);
}