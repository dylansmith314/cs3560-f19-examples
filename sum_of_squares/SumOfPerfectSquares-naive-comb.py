import time
import math
from itertools import combinations

# Naive solution using combinations. Extremely slow.
# Obvious ways to improve:
#   1) in numbers[], only include numbers up to sqrt(n)
#   2) in candidates, remove duplicates such as (1, 2) and (2, 1)
def check_square_sum(n, a):
    for i in a:
        n -= i * i
    return n == 0


def sum_of_squares(n):
    print(n)
    numbers = [i for i in range(1, n + 1)]
    i = 1
    while i <= n:
        candidates = list(combinations(numbers * i, i))
        print(candidates)
        for c in candidates:
            if check_square_sum(n, c):
                return i
        i += 1


if __name__ == "__main__":
    start = time.time()
    max = 100001
    max_digits = math.floor(math.log10(max)) + 1
    for i in range(1, max):
        t1 = time.time()
        s = sum_of_squares(i)
        istr = str(i).rjust(max_digits)
        t2 = time.time()
        print(
            f"{istr}: sum of {s} perfect squares: computed in {t2-t1} sec. Elapsed time: {t2-start} sec."
        )
        end = time.time()
    print(f"Total elapsed time: {end-start} seconds")
