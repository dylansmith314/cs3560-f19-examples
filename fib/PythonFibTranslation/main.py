"""
@file main.py
@author Johnny Gilbert
@brief The main function is used in order to test our recursive and iterative fib function as well as the fib_cache class
"""
import fib
from fib_cache import FibCache

if __name__ == "__main__":
    n = 0
    n = input("Please Enter n: ")
    y = fib.fib_recursive(int(n))
    print("Fib(n) is", y)
    x = FibCache(int(n))
    print("FibCache(n) is ", x.get(int(n)))
