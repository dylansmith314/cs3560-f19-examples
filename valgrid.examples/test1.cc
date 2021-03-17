/**
 * @file          test1.cc
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering
 * @brief         Simple function named foo
 */ 
#include <iostream>
using namespace std;
/**
 * @brief - function that will either be true or false and 
 *          print a function
 * 
 * @param x - a true or false that will print if the function
 *            works or not
 */

void foo(bool x) 
{
  if (x) 
  {
    cout << "This worked" << endl;
  } 
  else 
  {
    cout << "Oops this didn't work "<< endl;
  }
}
/// Main Program
int main() 
{
  bool test;
  foo(test);
  /// End of the main program
  return 0;
}
