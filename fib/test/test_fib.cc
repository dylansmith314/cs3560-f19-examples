/**
 * @file test_fib.cc
 * @brief Collection of test cases for fibonacci functions
 *
 * These test cases only test the functions in fib.h and fib.cc
 * */
// Let Catch2 know that we are using its main function.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// This is possible because of -I../
#include "fib.h"

// For the floating point example.
using namespace Catch::Matchers;

/**
 * @brief Test the interative version
 *
 * This contains two test cases. One for the lower number
 * and another one for larger number.
 *
 * The `WithinAbs` is used so that the test cases
 * tolorate error in floating point value.
 */
TEST_CASE( "Iterative version should work" ) {
  // Get result.
  int result = fib_iterative(5);
  float result_f = static_cast<float>(result);
  
  // Test.
  REQUIRE(result == 5);
  REQUIRE_THAT( result_f, WithinAbs(5.0, 0.05) ); // Floating point example.


  result = fib_iterative(8);
  result_f = static_cast<float>(result);

  REQUIRE(result == 21);
  REQUIRE_THAT( result_f, WithinAbs(21.0, 0.05) );
}

/** @brief Test the recursive version
 *
 * The same input value from the interative version is used.
 */
TEST_CASE( "Recursive version should work" ) {
  // Get result.
  int result = fib_recursive(5);
  float result_f = static_cast<float>(result);
  
  // Test.
  REQUIRE(result == 5);
  REQUIRE_THAT( result_f, WithinAbs(5.0, 0.05) ); // Floating point example.


  result = fib_recursive(8);
  result_f = static_cast<float>(result);

  REQUIRE(result == 21);
  REQUIRE_THAT( result_f, WithinAbs(21.0, 0.05) );
}

/**
 * @brief Sample test case
 *
 * Another example but it does not use floating point result.
 * It shows how to compare the integer value with expected integer
 * value.
 */
TEST_CASE("Test") {
  // Setup.

  // Try to get the result.
  int result = fib_recursive(9);

  REQUIRE( result == (fib_recursive(8) + 13));
}
