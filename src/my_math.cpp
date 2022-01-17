#include "my_math.h"
#define _USE_MATH_DEFINES
#include <cmath>

static constexpr float pi = M_PI;
float circle_area_cpp(float radius)
{
    return pi * radius * radius;
}