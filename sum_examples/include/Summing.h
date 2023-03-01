#ifndef SUMMING_H
#define SUMMING_H

#include <vector>
using std::vector;

template<typename T>
T Kahan_sum(const vector<T> &vals, const long N)
{
    T sum = 0;
    T c = 0;
    T y, t;
    for (long i = 0; i < N; i++)
    {
        y = vals[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }

    return sum;
}

template<typename T>
T trivial_sum(const vector<T> &vals, const long N)
{
    T sum = 0;
    for(long i = 0; i < N; i++)
    {
        sum = sum + vals[i];
    }
    return sum;
}

#endif