/**
 * @file fib.cc
 * @brief Two diffferent implementation of the fibonacci functions.
 * 
 * All the documentation for these functions are in the .h file already.
 */
#include "fib.h"

int fib_recursive(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    /** <h4>Implementation Note</h4>
     * Instead of saving the values and add them before returning them
     * we saved ourselves from declaring varaibles by returning
     * the value from the expression directly.
     * */
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n) {
    int a, b, temp;
    a = 1;
    b = 1;

    /**
     <h4>Implementation Note</h4>
     Instead of using multiple `if` statements, we only
     use one `if` statement with two logical expressions.*/
    if (n == 1 || n == 2) {
        return 1;
    }

    for (int i = 3; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }

    return b;
}
