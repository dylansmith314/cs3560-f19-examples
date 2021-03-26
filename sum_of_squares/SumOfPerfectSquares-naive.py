import time
import math

# Naive solution. Extremely slow.
# Obvious ways to improve:
#   1) include numbers only up to sqrt(n) in candidates
#   2) in candidates, generate only f(n)-1 numbers. Compute the last number.


def check_candidate(c, n):
    for i in reversed(range(len(c))):
        if c[i] > n:
            if i == 0:
                return False
            c[i] = 0
            c[i - 1] += 1
    return True


def sum_of_squares(n):
    numbers = [i for i in range(1, n + 1)]
    i = 1
    while i <= n:
        candidate = [0 for _ in range(i)]
        while check_candidate(candidate, n):
            # print(n, candidate)
            s = 0
            for x in candidate:
                s += x * x
            if s == n:
                return i
            candidate[~0] += 1
        i += 1


if __name__ == "__main__":
    start = time.time()
    max = 1000001
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
