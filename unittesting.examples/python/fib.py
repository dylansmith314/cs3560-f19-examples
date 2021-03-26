"""
Fibonacci module.
"""


def fib_func(n):
    """
    Representing your code as a function.

    You can test the function directly.
    """
    if n == 1 or n == 2:
        return 1
    return fib_func(n - 1) + fib_func(n - 2)


class Fib:
    """
    Representing your code as a class.

    In this case you want to test the individual method
    of the class.
    """

    def _fib(self, n):
        a, b = 0, 1
        i = 1
        while i <= n:
            a, b = b, a + b
            yield a
            i += 1

    def at(self, n):
        """
        Return Fibonacci number at position n.
        """
        result = 1
        i = 1
        generator = self._fib(n)
        while i <= n:
            result = next(generator)
            i += 1
        return result

    def get_all(self, n):
        """
        Return all Fibonacci number up to position n.
        """
        return self._fib(n)
