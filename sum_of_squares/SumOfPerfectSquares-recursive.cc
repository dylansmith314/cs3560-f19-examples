#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/**
 * Determines the smallest sqaure sum of a given number and returns true or false
 * when a perfect square reaches it's smallest possible value 
 *
 * @return bool
 */
bool sos(unsigned long n, long long k){
    if(k == 1){
        return pow(floor(sqrt(n)), 2) == n;
    }
    for(unsigned long i = floor(sqrt(n))+1; i >= 1; i--){
        unsigned long t = n - i*i;
        if(sos(t, k-1)){
            return true;
        }
    }
    return false;
}

/**
 * Iterates through number i linearly until the conditions for the sum of squares function are met
 * 
 * @return unsigned long
 */
unsigned long sum_of_squares(unsigned long n){
    unsigned long  i = 1;
    while(!sos(n,i)){
        i += 1;
    }
    return i;
}

int main(){
    time_t start = time(NULL);
    unsigned long max = 100001;
    unsigned long max_digits = floor(log10(max))+1;
    time_t last_duration = 0;
    time_t last_elapsed = 0;
    for(unsigned long i = 1; i < max; i++){
        time_t t1 = time(NULL);
        unsigned long s = sum_of_squares(i);
        time_t t2 = time(NULL);
        if(t2 - t1 > last_duration*2 || t2-start > last_elapsed * 2){
            string istr = "" + i;
            cout << right << setw(max_digits) << istr << ": sum of " << s << " perfect squares: computed in " << t2 - t1 << " sec. Elapsed time: " << t2 - start << " sec." << endl;
            last_duration = t2-t1;
            last_elapsed = t2-start;
        }
    }
    time_t end = time(NULL);
    cout << "Total elased time to compute sum of squares up to " << max << ": " << end - start << " seconds" << endl;
}
