/**
 * @file fib_cache.h
 * @brief A class definition for FibCache.
 * 
 */
#ifndef FIB_CACHE_H
#define FIB_CACHE_H
#include <vector>

 /**
  * @class FibCache
  * @brief Calculating Fibonacci with value caching
  *
  * The class has internal vector that save the calulated values of fibbonacci number
  * at position `n`. Thus, when the same value is requested again, the cached
  * values is return.
  */
class FibCache {
private:
    int cache_size; //!< The length of the slot of cahce.
    std::vector<int> cache; //!< Internal cache storage. It is based on vector.
public:
    /**
     * @brief A class contructor.
     * 
     * This is using the initialization list. It is then resize the vector
     * for the storage.
     * 
     * @param cache_size The size of the cache storage.
     */
    FibCache(int cache_size) : cache_size{cache_size} {
        if (cache_size < 2) {
            cache_size = 2;
        }

        cache.resize(cache_size);

        // Zero initialize.
        for (std::vector<int>::iterator itr = cache.begin(); itr != cache.end(); itr++) {
            *itr = 0;
        }
        cache[0] = 1;
        cache[1] = 1;
    };

    /**
     * @brief A class destructor.
     * 
     * It is used to free resources used by a class. 
     */
    ~FibCache();

    /**
     * @brief Answer the query for n-th 
     * 
     * It will try to answer the query using cached value. If that
     * is not possible, it will calculate and answer.
     * 
     * This uses \ref fib_recursive function.
     * 
     * @param n The n-th position of the Fibonacci number to get.
     */
    int get(int n);
};
#endif
