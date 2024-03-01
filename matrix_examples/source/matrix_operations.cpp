#include "matrix_maths.h"
#include <random>
#include <vector>
#include <iostream>
#include <chrono>

using std::vector;
typedef std::chrono::high_resolution_clock myClock;

template<typename T, size_t N>
void print_matrix(vector<vector<T>> mat){
    for (int i = 0; i < N; i++){
        std::cout << "Row " << i << std::endl;
        for(int j = 0; j < N; j++){
            std::cout << mat[i][j] << std::endl;
        }
    }
}

double t_seconds(std::chrono::time_point<myClock> t1, std::chrono::time_point<myClock> t2)
{
    return (t2 - t1).count() / 1e9;
}

int main()
{
    std::mt19937_64 rng;
    std::uniform_real_distribution<double> dist(0,1);

    myClock *clock = new myClock();

    //make three empty vectors


    vector<vector<double>> A = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};
    vector<vector<double>> B = {{3.0, 2.0, 1.0}, {3.0, 2.0, 1.0}, {3.0, 2.0, 1.0}};
    vector<vector<double>> C = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};




    const int N = 3;

    auto t1 = clock->now();

    rowMajor_by_rowMajor(A, B, C, N);

    auto t2 = clock->now();

    //print_matrix<double, N>(C);

    std::cout << "---- Time taken for rowMajor_by_rowMajor ----" << std::endl;
    std::cout << t_seconds(t1, t2) << std::endl;

    auto t3 = clock->now();

    rowMajor_by_colMajor(A, B, C, N);

    auto t4 = clock->now();

    std::cout << "---- Time taken for rowMajor_by_colMajor ----" << std::endl;
    std::cout << t_seconds(t3, t4) << std::endl;


    //create a new matrix 

    // Some options for matrix representations!
    // double *X = new double[N*N];
    // vector<double> X(N*N)
    // double **X = new double *X[N];
    // vector<vector<double>> X(N);   


    delete clock;
    return 0;
}