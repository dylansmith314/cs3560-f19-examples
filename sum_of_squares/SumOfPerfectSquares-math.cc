#include <iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int sum_of_squares(int n) {
    if(pow(n,0.5) == int(pow(n,0.5)))
        return 1;
    int c1 = 0;
    int N = n;
    while (n&3==0)
    {
        n>>=2;
        c1++;
    }
    if (n&7 == 7)
    {
        return 4;
    }
    for (size_t i = 1; i < int(pow(n,0.5)+1); i++)
    {
        if (pow((n-i*i),0.5) == int(pow((n-i*i),0.5)))
        {
            return 2;
        }
    }
    return 3;
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
            cout << fixed << setprecision(6) <<  istr << ": sum of " << s << " perfect squares: computed in " << t2_t1 << " sec. Elapsed time: " << t2_start << " sec." << endl;
            last_duration = t2_t1;
            last_elapsed = t2_start;
        }
    }
    auto end = high_resolution_clock::now();
    long double end_start = (end-start).count()/pow(10,9);
    cout << fixed << setprecision(6) << "Total elapsed time to compute sum of squares up to " << max << ": " << end_start << " seconds" << endl;

    return 0;
}