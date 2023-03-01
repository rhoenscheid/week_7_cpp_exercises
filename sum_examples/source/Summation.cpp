#include "Summing.h"
#include <iostream>
#include <vector> 
#include <chrono>

using std::vector;

typedef std::chrono::high_resolution_clock myClock;

double t_seconds(std::chrono::time_point<myClock> t1, std::chrono::time_point<myClock> t2)
{
    return (t2 - t1).count() / 1e9;
}

int main()
{

    return 0;
}