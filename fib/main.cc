/**
 * @file main.cc
 * @author Krerkkiat Chusap
 * @brief The main() function as an example to test the fibonacci function.
 */
#include <iostream>

#include "fib.h"
#include "fib_cache.h"

int main() {
    int n;
    std::cout << "Please enter n: ";
    std::cin >> n;

    std::cout << "Fib(n) is " << fib_recursive(n) << std::endl;

    FibCache fib_cache(5);
    std::cout << "FibCache(n) is " << fib_cache.get(n) << std::endl;
    
    return EXIT_SUCCESS;
}
