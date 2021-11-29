//
// Created by efarhan on 11/29/21.
//
#include "palindrome.h"

bool is_palindrome(const char* data, size_t size)
{
    for(size_t i = 0; i < size/2; i++)
    {
        if(data[i] != data[size-i-1])
        {
            return false;
        }
    }
    return true;
}