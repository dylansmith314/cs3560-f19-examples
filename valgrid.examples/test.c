/**
 * @file          test.c
 * @author        Dr. Chang Liu
 * @editor:       Nathaniel Buchanan
 * @date          November 7, 2019
 *                Last Updated: March 15, 2021
 * @university:   Ohio University
 * @college:      Russ College of Engineering 
 * @brief
 * from: http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
 * */

#include <stdio.h>

/// The main function/Program
int main()
{
  ///declare a pointer p
  char *p;

  /// Allocation #1 of 19 bytes
  p = (char *) malloc(19);

  /// Allocation #2 of 12 bytes
  p = (char *) malloc(12);
  free(p);

  /// Allocation #3 of 16 bytes
  p = (char *) malloc(16);

  /// end of the main program
  return 0;
}