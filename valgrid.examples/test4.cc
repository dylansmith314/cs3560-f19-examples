/**
 * @file          test4.cc
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering
 * @brief        
 * 
 * Useful for showing data-races
 * Compile g++ -g -fopenmp test4.cc
 * Test:
 * valgrind --tool=helgrind a.out 
 *
 */ 
#include <iostream>

/// Main Program
int main() 
{
  int sum = 0;
  #pragma omp parallel for
  /// For loop that will add the sum from 0 to 100
  for (int i = 0; i < 100 ; i++) 
  {
    sum += i;
  }

  /// End of Main
  return 0;
}
