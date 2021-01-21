//
// Created by efarhan on 1/21/21.
//
#include "sorting.h"
#include <benchmark/benchmark.h>
#include <vector>
#include <numeric>
#include <random>
#include <iostream>

const size_t min_value = 8;
const size_t max_value = 8<<10;


static void BM_BubbleSortAsm(benchmark::State& state) 
{
    std::vector<int> numbers(state.range(0));
    std::iota(numbers.begin(), numbers.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto _ : state) 
    {
        state.PauseTiming();
        auto shuffle_vector = numbers;
        
        do
        {
            std::shuffle(shuffle_vector.begin(), shuffle_vector.end(), g);
        } while(std::equal(shuffle_vector.begin(), shuffle_vector.end(), numbers.begin(), numbers.end()));
        state.ResumeTiming();
        bubble_sort_asm(shuffle_vector.data(), shuffle_vector.size());

    }
}
BENCHMARK(BM_BubbleSortAsm)->Range(min_value, max_value);

static void BM_BubbleSortCpp(benchmark::State& state)
{
    std::vector<int> numbers(state.range(0));
    std::iota(numbers.begin(), numbers.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto _ : state)
    {
        state.PauseTiming();
        auto shuffle_vector = numbers;

        do
        {
            std::shuffle(shuffle_vector.begin(), shuffle_vector.end(), g);
        } while(std::equal(shuffle_vector.begin(), shuffle_vector.end(), numbers.begin(), numbers.end()));
        state.ResumeTiming();
        bubble_sort(shuffle_vector.data(), shuffle_vector.size());

    }
}
BENCHMARK(BM_BubbleSortCpp)->Range(min_value, max_value);


static void BM_InsertionSortAsm(benchmark::State& state)
{
    std::vector<int> numbers(state.range(0));
    std::iota(numbers.begin(), numbers.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto _ : state)
    {
        state.PauseTiming();
        auto shuffle_vector = numbers;

        do
        {
            std::shuffle(shuffle_vector.begin(), shuffle_vector.end(), g);
        } while(std::equal(shuffle_vector.begin(), shuffle_vector.end(), numbers.begin(), numbers.end()));
        state.ResumeTiming();
        insertion_sort_asm(shuffle_vector.data(), shuffle_vector.size());

    }
}
BENCHMARK(BM_InsertionSortAsm)->Range(min_value, max_value);

static void BM_InsertionSortCpp(benchmark::State& state)
{
    std::vector<int> numbers(state.range(0));
    std::iota(numbers.begin(), numbers.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto _ : state)
    {
        state.PauseTiming();
        auto shuffle_vector = numbers;

        do
        {
            std::shuffle(shuffle_vector.begin(), shuffle_vector.end(), g);
        } while(std::equal(shuffle_vector.begin(), shuffle_vector.end(), numbers.begin(), numbers.end()));
        state.ResumeTiming();
        insertion_sort(shuffle_vector.data(), shuffle_vector.size());

    }
}
BENCHMARK(BM_InsertionSortCpp)->Range(min_value, max_value);

static void BM_SortCpp(benchmark::State& state)
{
    std::vector<int> numbers(state.range(0));
    std::iota(numbers.begin(), numbers.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto _ : state)
    {
        state.PauseTiming();
        auto shuffle_vector = numbers;

        do
        {
            std::shuffle(shuffle_vector.begin(), shuffle_vector.end(), g);
        } while(std::equal(shuffle_vector.begin(), shuffle_vector.end(), numbers.begin(), numbers.end()));
        state.ResumeTiming();
        std::sort(shuffle_vector.begin(), shuffle_vector.end());

    }
}
BENCHMARK(BM_SortCpp)->Range(min_value, max_value);
// Run the benchmark
BENCHMARK_MAIN();