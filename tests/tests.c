/**
 * @file       tests.c
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Source file for testing of mathematical functions in C.
 * **********************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include <inttypes.h>
#include <string.h>
#include "../src/functions.h"
#include "minunit.h"

////////////////////////////// IMPORTANT ///////////////////////////////////////
/////////// Source repository: https://github.com/siu/minunit //////////////////
/////////// For more info consult with this page ///////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/* Private defines --------------------------------------------------------- */
#define ARRAY_SIZE (0x400)

MU_TEST(test_minimax) {
  int mini = 0, maxi = 0;
  int pole[ARRAY_SIZE] = {-4, 2, 3, 9, 5, 16, 7, 38, 99, 10}, delka = 10;
  Functions_Minimax(pole, delka, &mini, &maxi);

  mu_assert_int_eq(-4, mini);
  mu_assert_int_eq(99, maxi);
}

MU_TEST(test_minimax_nulls) { Functions_Minimax(NULL, 4, NULL, NULL); }

MU_TEST(test_minimum) {
  int pole[ARRAY_SIZE] = {-14, 32, 3, 5, 4, 16, 7, 38, 99, 10}, delka = 10;
  mu_assert_int_eq(-14, Functions_GetMin(pole, delka));

  delka = 0;
  mu_assert_int_eq(0, Functions_GetMin(pole, delka));
}

MU_TEST(test_maximum) {
  int pole[ARRAY_SIZE] = {-14, 32, 3, 5, 4, 16, 7, 38, 99, 10}, delka = 10;
  mu_assert_int_eq(99, Functions_GetMax(pole, delka));
  delka = 0;
  mu_assert_int_eq(0, Functions_GetMax(pole, delka));
}

MU_TEST(test_factorial) {
  mu_assert_double_eq(120, Functions_Factorial(5));
  mu_assert_double_eq(3628800, Functions_Factorial(10));
}

MU_TEST(test_fibonacci) {
  mu_assert_int_eq(55, Functions_Fibonacci(10));
  mu_assert_int_eq(6765, Functions_Fibonacci(20));
}

MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(test_minimax);
  MU_RUN_TEST(test_minimax_nulls);
  MU_RUN_TEST(test_minimum);
  MU_RUN_TEST(test_maximum);
  MU_RUN_TEST(test_factorial);
  MU_RUN_TEST(test_fibonacci);
}

int main(void) {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
