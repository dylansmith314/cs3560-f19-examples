import math
import time

# Recursive solution.
def sos(n, k):  # is it possible for sum k perfect squares to n?
    # print(n,k)
    if k == 1:
        if math.floor(math.sqrt(n)) ** 2 == n:
            return True
        else:
            return False

    for i in reversed(range(1, math.floor(math.sqrt(n)) + 1)):
        t = n - i * i
        # print(f"trying {i} for {n},{k}")
        if sos(t, k - 1):
            return True
    return False


def sum_of_squares(n):
    # print(n)
    i = 1
    while not sos(n, i):
        i += 1
    return i


if __name__ == "__main__":
    start = time.time()
    max = 1000001
    max_digits = math.floor(math.log10(max)) + 1
    last_duration = 0
    last_elapsed = 0
    for i in range(1, max):
        t1 = time.time()
        s = sum_of_squares(i)
        t2 = time.time()
        if t2 - t1 > last_duration * 2 or t2 - start > last_elapsed * 2:
            istr = str(i).rjust(max_digits)
            print(
                f"{istr}: sum of {s} perfect squares: computed in {t2-t1} sec. Elapsed time: {t2-start} sec."
            )
            last_duration = t2 - t1
            last_elapsed = t2 - start
    end = time.time()
    print(
        f"Total elapsed time to compute sum of squares up to {max}: {end-start} seconds"
    )
