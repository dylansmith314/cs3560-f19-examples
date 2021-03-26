/**
 * @file          testa.cc
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering
 * @brief Compile as follows:
 * g++ -g -O2 test.cc
 * valgrind ./a.out
 * discover -o test.disc a.out
 * ./test.disc
 * */
#include <vector>
#include <iostream>
using namespace std;

/// Main Program
int main(int argc, char** argv) 
{
  /// declare a vector of integers
  vector<int> vec;
  /// argc is equal to whatever is shown
  cout << "argc = " << argc << endl;

  /// conditional statement determined based off of
  /// argc
  if (argc > 1) 
  {
    /// if argc is above 1, then resize vector to 10
    vec.resize(11);
  } 
  else
  {
    /// if argc is 1 or below, then resize vector to 10
    vec.resize(10);
  }
  /// for loop that goes through the vector
  for (int i = 0; i <= 10; i++) 
  {
      vec[i] = i;
  }
  ///integer declaring the sum (will be wrong due to not initializing to 0)
  int sum;
  /// for loop that goes from index 0 to index 10
  for (int i = 0; i <= 10; i++) 
  {
    sum += vec[i];
  }
  /// print the sum
  cout << sum << endl;
  /// End of Main
  return 0;
}
