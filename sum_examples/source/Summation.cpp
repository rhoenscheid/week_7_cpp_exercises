#include "Summing.h"
#include <iostream>
#include <vector> 
#include <chrono>
#include <random>
#include <algorithm>

using std::vector;

typedef std::chrono::high_resolution_clock myClock;

double t_seconds(std::chrono::time_point<myClock> t1, std::chrono::time_point<myClock> t2)
{
    return (t2 - t1).count() / 1e9;
}

int main()
{

    //create clock
    myClock *clock = new myClock();

    std::mt19937_64 rng;
    std::uniform_real_distribution<float> dist(0,1);
    
    const int N = 1000000;
    vector<float> numbers;

    for (int i = 0; i < N ; i++){

        numbers.push_back(pow(10, -6));

    }

    auto t1 = clock->now();
    float result = Kahan_sum<float>(numbers);
    auto t2 = clock->now();
    std::cout << "Result for Kahan Sum" << std::endl;
    std::cout << "sum = " << result << std::endl;
    std::cout << "time = " << t_seconds(t1,t2) << std::endl;

    auto t3 = clock->now();
    float result2 = trivial_sum<float>(numbers);
    auto t4 = clock->now();
    std::cout << "Result for Trivial Sum" << std::endl;
    std::cout << "sum = " << result2 << std::endl;
    std::cout << "time = " << t_seconds(t3,t4) << std::endl;

    delete clock;

    return 0;
}