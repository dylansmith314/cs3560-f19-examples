"""
@file fib.py
@author Johnny Gilbert
@brief This file contains both a recursive and iterative version of calculating fibonacci combinations
"""


def fib_recursive(n):
    if n == 1 or n == 2:
        return 1
    return fib_recursive(n - 1) + fib_recursive(n - 2)


def fib_iterative(n):
    temp = 0
    a = 1
    b = 1

    if n == 1 or n == 2:
        return 1

    for x in range(2, n):
        temp = b
        b = a + b
        a = temp

    return b
