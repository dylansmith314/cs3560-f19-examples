/**
 * @file          test3a.cc
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering
 * @brief         Simple function named foo that works slightly
 *                different from test3 (with an additional line)
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
int foo(bool x) 
{
  if (x) 
  {
    cout << "This worked" << endl;  
  } 
  else 
  {
    cout << "Oops this didn't work "<< endl;
    /// Notice this change from test3.cc?
    return false;
  }

}

/// Main Program
int main() 
{

  bool test = true;

  cout << foo(test) << endl;

  /// End of Main
  return 0;
}
