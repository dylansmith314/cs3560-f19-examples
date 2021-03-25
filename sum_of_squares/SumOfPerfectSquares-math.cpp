//Math-based solution
#include <cmath>
#include <chrono>
#include <iostream>
#include <string>
using namespace std;

/**
 * Calculates the smallest possible sum of perfect squares that add
 * up to a given number 'n'
 * 
 * @return int
 */
int sum_of_squares(int n)
{


    if( sqrt(n) == int( sqrt(n) )  ){ //n itself is a perfect square
        return 1;
    }
    int c1 = 0;
    int m = n;
    while (floor(m/4) * 4 == m){
        m /= 4;
        c1++;
    }
    if( m % 8 == 7){
        return 4;
    }
    for(int i = 1; i <= int( pow(n,1.2) ) + 1 ;  ++i){
        if( sqrt((n - i*i)) == int( sqrt((n-i*i))  ) ){
            return 2;
        }
    }

    return 3;
}

int main()
{
    //get time duration:
    auto start = chrono::high_resolution_clock::now();
    int max = 1000001;
    int max_digits = floor(log10(max))+1;
    double last_duration = 0;
    double last_elapsed = 0;
    for(int i = 1; i < max ; ++i){
        auto t1 = chrono::high_resolution_clock::now();
        int s = sum_of_squares(i);
        auto t2 = chrono::high_resolution_clock::now();
        // auto Runduration = chrono::duration_cast<chrono::seconds>(t2-start);
        // auto Localduration = chrono::duration_cast<chrono::seconds>(t2-t1);
        if(   chrono::duration_cast<chrono::seconds>(t2-t1).count() > last_duration *2 
            ||   chrono::duration_cast<chrono::seconds>(t2-start).count()  > last_elapsed*2  )
            {
                string s = to_string(i);
                cout << "\nSum of Perfect Squares " << s << ": computed in " << chrono::duration_cast<chrono::duration<double>>(t2-t1).count()
                    << " sec. Elapsed Time: " << chrono::duration_cast<chrono::duration<double>>(t2-start).count();
                last_duration = chrono::duration_cast<chrono::seconds>(t2-t1).count();
                last_elapsed = chrono::duration_cast<chrono::seconds>(t2-start).count();

            }

    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(stop-start);
    cout << "\nTotal elapsed time to compute sum of squares up to " << max 
         << " " << duration.count() << " seconds.";
    return 0;
}

