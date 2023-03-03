#ifndef SUMMING_H
#define SUMMING_H

#include <vector>
using std::vector;

template<typename FPtype>
FPtype Kahan_sum(const vector<FPtype> &vals)
{
    FPtype sum = 0;
    FPtype c = 0;
    FPtype y, t;
    for (auto &x : vals)
    {
        y = x - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return sum;
}

template<typename T>
T trivial_sum(const vector<T> &vals)
{
    T sum = 0;
    for(auto &x : vals)
    {
        sum = sum + x;
    }
    return sum;
}

#endif