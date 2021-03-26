"""
@file fib_cache.py
@author Johnny Gilbert
@brief: This file has implementation for a FibCache class which contains cache values of fib values at appropriate indices
"""
import fib


class FibCache:
    cache_size = 0
    cache = []

    def __del__(self):
        pass

    def get(self, n):
        if n < 1:
            return 0
        if self.cache[n - 1] != 0:
            print("here")
            return self.cache[n - 1]

        result = fib.fib_recursive(n)
        self.cache[n - 1] = result
        return result

    def __init__(self, cache_size):
        if cache_size < 2:
            self.cache_size = 2
        for i in range(cache_size):
            self.cache.append(0)
        self.cache[0] = 1
        if cache_size > 1:
            self.cache[1] = 1
