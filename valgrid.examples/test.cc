
/**
 * @file          test.cc
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering
 * @brief
 * A simple C++ program with several bugs.
 * The bugs are easy to find with valgrind (Linux/Mac) or DISCOVER (Solaris).
 *
 * Compile as follows:
 * g++ -g -O2 test.cc
 * valgrind ./a.out
 * discover -o test.disc a.out
 * ./test.disc
 * 
 * */

#include <vector>
#include <iostream>
using namespace std;

/// The main program
int main()
{
   /// Declare a vector of integers
   vector<int> vec;
   /// The size of the vector is 10
   vec.resize(10);

   /// For loop that goes through the indicies
   for (int i = 0;i <= 10; i++) 
   {
      vec[i] = i;
   }
   int sum;
   /// For loop that adds up the sum of the vector
   for (int i = 0; i <= 10; i++) 
   {
       sum += vec[i];
   }
   cout << sum << endl;
}
