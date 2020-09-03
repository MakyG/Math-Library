/**
 * @file       main.c
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Main file for mathematical functions
 * **********************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes --------------------------------------------------------- */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "ioutils.h"

/* Private defines --------------------------------------------------------- */
#define ARRAY_SIZE (0x400)

/* Private function -------------------------------------------------------- */
int Array_Insert(int* array, int array_length, int capacity) {
  int i, ok, value, userInput;
  char buffer[255];
  printf("Current content of array:\n");

  for (i = 0; i < array_length - 1; i++) printf("%d, ", array[i]);

  printf(
      "%d\n"
      "Insert new values? (Y/N)\n",
      array[i]);
  userInput = io_utils_get_char_line();

  if (toupper(userInput) == 'Y') {
    printf("Insert new values separated by new line, END = K:\n");

    for (i = 0; i < capacity; i++) {
      do {
        io_utils_get_string(buffer, 254);

        if (toupper(buffer[0]) != 'K') {
          ok = sscanf(buffer, "%d", &value);

          if (ok == 1)
            array[i] = value;

          else
            printf("Incorrect format!\n");

        } else
          return i;

      } while (ok != 1);
    }
  }

  return array_length;
}

/* Implementation of main file --------------------------------------------- */
int main(void) {
  int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, array_length = 10;
  int mini, maxi;
  long x;
  double n;
  bool running = true;
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  while (running) {
    printf(
        "Press:\n"
        "1 for minmax\n"
        "2 for minimum number\n"
        "3 for maximum number\n"
        "4 for factorial\n"
        "5 for Fibonacciho sequence\n"
        "E to exit the application\n");

    switch (io_utils_get_char_line()) {
      case '1':
        array_length = Array_Insert(array, array_length, ARRAY_SIZE);
        Functions_Minimax(array, array_length, &mini, &maxi);
        printf("Minimum=%d, maximum=%d\n", mini, maxi);
        break;

      case '2':
        array_length = Array_Insert(array, array_length, ARRAY_SIZE);
        printf("Minimum=%d\n", Functions_GetMin(array, array_length));
        break;

      case '3':
        array_length = Array_Insert(array, array_length, ARRAY_SIZE);
        printf("Maximum=%d\n", Functions_GetMax(array, array_length));
        break;

      case '4':
        printf("Insert value N:\n");
        io_utils_get_double(&n);

        if (n < 1) {
          printf("Incorrect format\n");
        } else {
          printf("Factorial(%.0lf)=%.0lf\n", n, Functions_Factorial(n));
        }
        break;

      case '5':
        printf("Insert value N:\n");
        io_utils_get_long(&x);

        if (x < 2) {
          printf("Incorrect format\n");
        } else {
          printf("Fibonacci(%d)=%d\n", (int)x, Functions_Fibonacci((int)x));
        }
        break;

      case 'e':
      case 'E':
        running = false;
        break;

      default:
        printf("Unknown choice!\n");
        break;
    }
  };

  return 0;
}
