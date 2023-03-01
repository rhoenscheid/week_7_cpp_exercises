#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <chrono>

using std::vector;

typedef std::chrono::high_resolution_clock hrClock;

double getTime(std::chrono::time_point<hrClock> t1, std::chrono::time_point<hrClock> t2)
{
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1);
    return (double)(duration.count())/1e6;
}


struct vec
{
    double x;
    double y;
    double z;
};

struct pointMass
{
    double m;
    vec r;  // position
    vec v;  // velocity
};

// Define this as a class just to make sure all the vectors are the same size.
class PointMassCollection
{
    public:
    PointMassCollection(int N)
    {
        m = vector<double>(N);
        x = vector<double>(N);
        y = vector<double>(N);
        z = vector<double>(N);
        vx = vector<double>(N);
        vy = vector<double>(N);
        vz = vector<double>(N);
    }

    vector<double> m, x, y, z, vx, vy, vz;
};

int main()
{
    const long N = 10*1000*1000;

    hrClock timerClock;

    // RNG
    std::uniform_real_distribution<> pos_dist(-10, 10);
    std::normal_distribution<> mass_dist(1, 0.2);
    std::mt19937 rng_mt;
    auto ran_pos = std::bind(pos_dist, rng_mt);
    auto ran_mass = std::bind(mass_dist, rng_mt);

    // Array of structs
    vector<pointMass> pm_array(N);
    for(auto &pm : pm_array)
    {
        pm.r.x = ran_pos();
        pm.r.y = ran_pos();
        pm.r.z = ran_pos();
        pm.m = std::abs(ran_mass());
    }

    // Struct of arrays
    PointMassCollection pmc(N);
    for(long i = 0; i < N; i++)
    {
        pmc.m[i] = pm_array[i].m;
        pmc.x[i] = pm_array[i].r.x;
        pmc.y[i] = pm_array[i].r.y;
        pmc.z[i] = pm_array[i].r.z;
    }

    return 0;
}