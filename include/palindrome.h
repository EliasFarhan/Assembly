#pragma once

#include <cstdlib>

bool is_palindrome(const char*, size_t);

#ifdef __cplusplus
extern "C"
{
#endif
bool is_palindrome_asm(const char*, size_t);
#ifdef __cplusplus
}
#endif