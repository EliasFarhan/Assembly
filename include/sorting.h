#pragma once

#include <cstdlib>

void bubble_sort(int*, size_t);

void insertion_sort(int*, size_t);

#ifdef __cplusplus
extern "C" 
{
#endif
void bubble_sort_asm(int*, size_t);
void insertion_sort_asm(int*, size_t);
#ifdef __cplusplus
}
#endif