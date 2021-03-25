// Sum-of-Squares solution using dynamic programming
// Nathan Bennett

/**
 * @file SumOfPerfectSquares-dp.cpp
 * @author Nathan Bennet
 * @brief Provides a solution for the sum of perfect squares kata on codewars using dynamic programming
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

unsigned long sum_of_squares(unsigned long long n){
    vector<unsigned long long> count(n+1,ULLONG_MAX);
    count[0] = 0;
    for(size_t i = 0;i < n+1;++i)
    { 
        for (size_t j = 1;j*j <= i;j++)
        {
            count[i] = min(count[i], count[i-j*j]+1);
        }
    }
    return count[n];
}

int main(){
    time_t start = time(NULL);
    unsigned long max = 100001;
    unsigned long max_digits = floor(log10(max)) + 1;
    time_t last_duration = 0;
    time_t last_elapsed = 0;
    for(unsigned long i = 1;i < max; i++){
        time_t t1 = time(NULL);
        unsigned long s = sum_of_squares(i);
        time_t t2 = time(NULL);
        if(t2 - t1 > last_duration*2 || t2-start > last_elapsed * 2){
            cout << right << setw(max_digits) << to_string(i) << ": sum of " << s << " perfect squares: computed in " << t2 - t1 << " sec. Elapsed time: " << t2 - start << " sec." << endl;
            last_duration = t2-t1;
            last_elapsed = t2-start;
        }
    }
    time_t end = time(NULL);
    cout << "Total elapsed time to compute sum of squares up to " << max << ": " << end - start << " seconds" << endl;
}
