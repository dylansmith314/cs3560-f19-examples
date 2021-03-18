"""
Test cases for Fibonacci module.

This example use the builtin module for unit testing
from Python.
"""
import unittest

# Make sure to import the function to be tested
# from the module.
#
# Usually, the code to test and the code under test
# are separated.
from fib import fib_func


class TestFibFunc(unittest.TestCase):
    """
    Example of test cases that test the function.
    """

    def test_fib_func(self):
        self.assertEqual(8, fib_func(6))


from fib import Fib


class TestFibClass(unittest.TestCase):
    """
    Example of test cases that test the class.
    """

    def test_at(self):
        # Usually an object is created. You can also set it up using setUp() method.
        obj = Fib()

        self.assertEqual(8, obj.at(6))
        self.assertEqual(1, obj.at(1))
        self.assertEqual(1, obj.at(2))

    def test_get_all(self):
        obj = Fib()

        self.assertEqual([1], list(obj.get_all(1)))
        self.assertEqual([1, 1], list(obj.get_all(2)))
        self.assertEqual([1, 1, 2, 3, 5, 8], list(obj.get_all(6)))


if __name__ == "__main__":
    unittest.main()
