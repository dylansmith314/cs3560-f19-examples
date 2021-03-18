# code for codewars problem: Missing Numbers
from math import isqrt


def missing_number(n):
    if n == 0:
        return 2
    p10 = 10 ** n
    if ~n & 1:
        return (p10 // 2 + 10 ** (n // 2) - 1) ** 2 // p10 + 1
    res = p10 // 2 + isqrt(p10)
    if res ** 2 // p10 - (res - 1) ** 2 // p10 <= 1:
        res += 1
    return (res - 1) ** 2 // p10 + 1
