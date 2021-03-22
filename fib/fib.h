/**
 * @file fib.h
 * @brief Define functions to calculate fibonacci.
 * 
 * This is the include file for the fibonacci library.
 * It contains various functions to calculate the fibonacci
 * number.
 * 
 * @author Krerkkiat Chusap
 */
#ifndef FIB_H
#define FIB_H
#include <iostream>

/**
 * @brief Calculate Fibonacci recursively
 * 
 * This function will calculate the n-th Fibonacci recursively.
 * The base cases for the calculation are:
 * - n == 1 -> 1
 * - n == 2 -> 1
 * 
 * @param n The n-th position of the Fibonacci number to get.
 * @return The value of the Fibonacci number at position n-th.
 */
int fib_recursive(int n);

/**
 * @brief Calculate Fibonacci iteratively
 * 
 * This function calculates the n-th Fibonacci number iteratively. It
 * starts from n==3 with the the following starting values:
 * - n == 1 -> 1
 * - n == 2 -> 1 
 * 
 * @param n The n-th position of the Fibonacci number to get.
 * @return The value of the Fibonacci number at position n-th.
*/
int fib_iterative(int n);
#endif