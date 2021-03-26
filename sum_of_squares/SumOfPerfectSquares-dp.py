import sys
import time
import math

# Dynamic Programming.
def sum_of_squares(n):
    count = [sys.maxsize for i in range(n + 1)]
    count[0] = 0
    for i in range(n + 1):
        j = 1
        while j * j <= i:
            count[i] = min(count[i], count[i - j * j] + 1)
            j += 1
    return count[n]


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
