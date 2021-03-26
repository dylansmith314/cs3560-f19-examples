import sys
import time
import math

count = [0]

# Dynamic Programming (static).
def sum_of_squares(n):
    global count

    existing_count = len(count)
    if n < existing_count:
        return count[n]
    count.extend([sys.maxsize for i in range(existing_count, n + 1)])
    for i in range(existing_count, n + 1):
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

    sos = [[] for _ in range(5)]
    # print(sos)
    for index, item in enumerate(count):
        # print(index,item)
        sos[item].append(index)
    # print(sos[1])
    # print(sos[2])
    # print(sos[3])
    # print(sos[4])
