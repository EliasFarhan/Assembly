
#include "gtest/gtest.h"
#include "sorting.h"
#include <numeric>
#include <random>

TEST (Sorting, BubbleSortCpp)
{
    std::vector<int> numbers(11);
    std::iota(numbers.begin(), numbers.end(), -5);
    auto numbers2 = numbers;
    bubble_sort(numbers2.data(), numbers2.size());
    EXPECT_TRUE(std::is_sorted(numbers2.begin(), numbers2.end()));
    EXPECT_TRUE(std::is_permutation(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end()));
    std::random_device rd;
    std::mt19937 g(rd());

    do
    {
        std::shuffle(numbers2.begin(), numbers2.end(), g);
    } while(std::equal(numbers.begin(), numbers.end(), numbers2.begin()));
    bubble_sort(numbers2.data(), numbers2.size());
    EXPECT_TRUE(std::is_sorted(numbers2.begin(), numbers2.end()));
    EXPECT_TRUE(std::is_permutation(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end()));
}

TEST (Sorting, InsertionSortCpp)
{
    std::vector<int> numbers(11);
    std::iota(numbers.begin(), numbers.end(), -5);
    auto numbers2 = numbers;
    insertion_sort(numbers2.data(), numbers2.size());
    EXPECT_TRUE(std::is_sorted(numbers2.begin(), numbers2.end()));
    EXPECT_TRUE(std::is_permutation(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end()));
    std::random_device rd;
    std::mt19937 g(rd());
    do
    {
        std::shuffle(numbers2.begin(), numbers2.end(), g);
    } while(std::equal(numbers.begin(), numbers.end(), numbers2.begin()));
    insertion_sort(numbers2.data(), numbers2.size());
    EXPECT_TRUE(std::is_sorted(numbers2.begin(), numbers2.end()));
    EXPECT_TRUE(std::is_permutation(numbers.begin(), numbers.end(), numbers2.begin(), numbers2.end()));
}