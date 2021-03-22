/**
 * @file fib_cache.cc
 * @brief Implementation of the FibCache class.
 * 
 * All the documentation for these member functions are in the .h file already.
 * 
 */
#include "fib.h"
#include "fib_cache.h"

FibCache::~FibCache() {

}


int FibCache::get(int n) {
    /**
     * <h4>Implementation Note</h4>
     */
    /// Catch an invalid value of n.
    if (n < 1) {
        return 0;
    }

    /// Check if we already calculated the value
    /// before or not.
    if (cache[n - 1] != 0) {
        return cache[n - 1];
    }

    int result = fib_recursive(n);
    cache[n - 1] = result;
    
    return result;
}
