"""
Pytest Example.
"""

from fib import fib_func, Fib


def test_fib_func():
    assert fib_func(1) == 1
    assert fib_func(2) == 1
    assert fib_func(6) == 8


def test_fib_class():
    obj = Fib()

    assert obj.at(1) == 1
    assert obj.at(2) == 1
    assert list(obj.get_all(2)) == [1, 1]
    assert list(obj.get_all(6)) == [1, 1, 2, 3, 5, 8]
