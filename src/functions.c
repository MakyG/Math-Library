/**
 * @file       functions.c
 * @author     Makyča Tomáš
 * @date       26. 2. 2020
 * @brief      Implementing the mathematical functions from a header file fce.h
 * ****************************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

/* Private includes -------------------------------------------------------- */
#include "functions.h"

/* Functions defition ------------------------------------------------------ */
void Functions_Minimax(int *array, int arrayLenght, int *minimum, int *maximum) {
    if (!array || !arrayLenght || !minimum || !maximum)
        return;

    *maximum = array[0];
    *minimum = array[0];

    for (int i = 0; i < arrayLenght; i++){
        if (array[i] > *maximum)
            *maximum = array[i];

        if (array[i] < *minimum)
            *minimum = array[i];
    }
}

int Functions_GetMin(int *array, int arrayLenght) {

    if (!array || !arrayLenght)
        return 0;

    int min = array[0];

    for (int i = 1; i < arrayLenght; i++){
        if (array[i] < min){
            min = array[i];
        }
    }

  return min;
}

int Functions_GetMax(int *array, int arrayLenght) {

    if (!array || !arrayLenght)
        return 0;

    int max = array[0];
    for (int i = 1; i < arrayLenght; i++){
        if (array[i] > max){
            max = array[i];
        }
    }

  return max;
}

double Functions_Factorial(double n) {
    int factorial = 1;
    for(int i = 1; i <= n; i++) {
        factorial = factorial * i;
    }
    n = factorial;
    return n;
}

int Fibonacci_Series(int Number)
{
    if ( Number == 0 )
        return 0;
    else if ( Number == 1 )
        return 1;
    else
        return ( Fibonacci_Series(Number - 1) + Fibonacci_Series(Number - 2) );
}

int Functions_Fibonacci(int n) {
    n = Fibonacci_Series(n);
    return n;
}



