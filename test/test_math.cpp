
#include "gtest/gtest.h"
#define _USE_MATH_DEFINES
#include <cmath>
#ifdef _MSC_VER
#include <corecrt_math_defines.h>
#endif
#include "my_math.h"

TEST (Math, CircleArea)
{
    constexpr float pi = M_PI;
    EXPECT_FLOAT_EQ(circle_area_asm(1.0f), pi);
    EXPECT_FLOAT_EQ(circle_area_cpp(1.0f), pi);
}