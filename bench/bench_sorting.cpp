//
// Created by efarhan on 1/21/21.
//
#include "sorting.h"
#include <benchmark/benchmark.h>
#include <vector>
#include <numeric>
#include <random>
#include <iostream>

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
        
        std::cout << "Value\n";
    }
}
BENCHMARK(BM_BubbleSortAsm)->Range(8, 128);
// Run the benchmark
BENCHMARK_MAIN();