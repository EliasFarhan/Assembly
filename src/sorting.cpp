#include "sorting.h"

void bubble_sort(int* begin, size_t length)
{
    for(size_t n = 0; n < length; n++)
    {
        size_t swap_count = 0;
        for(size_t i = 0; i < length-1; i++)
        {
            if(begin[i]>begin[i+1])
            {
                int tmp = begin[i];
                begin[i] = begin[i+1];
                begin[i+1] = tmp;
                swap_count++;
            }
        }
        if(swap_count == 0)
            return;
    }
}

void insertion_sort(int* begin, size_t length)
{
    for(size_t n = 1; n < length; n++)
    {
        for(size_t j = n; j > 0; j--)
        {
            if(begin[j-1] > begin[j])
            {
                int tmp = begin[j-1];
                begin[j-1] = begin[j];
                begin[j] = tmp;
            }
            else
            {
                break;
            }
        }
    }
}