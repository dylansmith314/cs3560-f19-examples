# Math-based solution
import time
import math


def sum_of_squares(n):
    if n ** (0.5) == int(n ** 0.5):
        return 1
    c1 = 0
    m = n
    while m // 4 * 4 == m:
        # print(n, bin(n), n&3, n>>2, bin(n>>2), n&7)
        m /= 4
        c1 += 1
    if m % 8 == 7:
        # if c1 == 0:
        #     print(f"{N} = {n:03}({n:#012b})")
        # elif c1==1:
        #     print(f"{N} = {n:03}({n:#012b}) * 4")
        # else:
        #     print(f"{N} = {n:03}({n:#012b}) * 4^{c1}")
        return 4

    for i in range(1, int(n ** (0.5)) + 1):
        if (n - i * i) ** (0.5) == int((n - i * i) ** (0.5)):
            return 2
    return 3


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
