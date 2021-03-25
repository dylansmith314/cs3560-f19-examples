/* **************************************************
    A function that, given an integer n (3 < n < 109), 
    finds the length of the smallest list of perfect 
    squares which add up to n.
   **************************************************
*/
#include <iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

vector<int> g_count = {0};

int sum_of_squares(int n) {
    int existing_count = g_count.size();
    if (n < existing_count)
    {
        return g_count[n];
    }
    for (size_t i = existing_count; i < n+1; i++)
    {
        g_count.push_back(INT8_MAX);
    }
    for (size_t i = existing_count; i < n+1; i++)
    {
        int j = 1;
        while ((j*j) <= i)
        {
            g_count[i] = min(g_count[i], g_count[i-j*j]+1);
            j++;
        }
    }
    return g_count[n];
}

int main()
{
    using namespace chrono;

    auto start = high_resolution_clock::now();
    int max = 1000001;
    int max_digits = floor(log10(max))+1;
    auto last_duration = 0;
    auto last_elapsed = 0;
    for (size_t i = 1; i < max; i++)
    {
        auto t1 = high_resolution_clock::now();
        int s = sum_of_squares(i);
        auto t2 = high_resolution_clock::now();
        long double t2_t1 = (t2-t1).count()/pow(10,9);      //pow(10,9) converts it from nanosec to sec
        long double t2_start = (t2-start).count()/pow(10,9);

        if (t2_t1 > last_duration*2 || t2_start > last_elapsed*2)
        {
            string istr = to_string(i);
            cout << fixed << setprecision(6) << istr << ": sum of " << s << " perfect squares: computed in " << t2_t1 << " sec. Elapsed time: " << t2_start << " sec." << endl;
            last_duration = t2_t1;
            last_elapsed = t2_start;
        }
    }
    auto end = high_resolution_clock::now();
    long double end_start = (end-start).count()/pow(10,9);
    cout << fixed << setprecision(6) << "Total elapsed time to compute sum of squares up to " << max << ": " << end_start << " seconds" << endl;

    return 0;
}
