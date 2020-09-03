/**
 * @file       functions.h
 * @author     Ondřej Ševčík
 * @date       6/2019
 * @brief      Header file for a small mathematical library
 * **********************************************************************
 * @par       COPYRIGHT NOTICE (c) 2019 TBU in Zlin. All rights reserved.
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* Public includes --------------------------------------------------------- */
#include <stddef.h>

/* Public defines --------------------------------------------------------- */
#define PI 3.14159265358979323846
#define E 2.718281828459045235360

/* Public Mathematical functions API --------------------------------------- */
/**
 * @brief       Returns minimum and maximum from an array to integer pointer
 * @param[in]   array    Array of integers
 * @param[in]   arrayLenght   The number of items in an array
 * @param[out]  minimum   Pointer at integer where is the minimum number from an
 * array stored
 * @param[out]  maximum   Pointer at integer where is the maximum number from an
 * array stored
 * @return  Returns maximum and minimum number from an array
 */
void Functions_Minimax(int *array, int arrayLenght, int *minimum, int *maximum);

/**
 * @brief       Loops through an array and return the minimum value
 * @param[in]   array    Array of integers
 * @param[in]  arrayLenght   The number of items in an array
 * @return  Returns minimum number from an array
 */
int Functions_GetMin(int *array, int arrayLenght);

/**
 * @brief       Loops through an array and return the maximum value
 * @param[in]   array    Array of integers
 * @param[in]  arrayLenght   The number of items in an array
 * @return  Returns maximum number from an array
 */
int Functions_GetMax(int *array, int arrayLenght);

/**
 * @brief       Counts the factorial of an number
 * @param[in]   n   Number from which we want the result of factiorial
 * @return  Returns factorial of an number
 */
double Functions_Factorial(double n);

/**
 * @brief       Counts n-th number of fibonacci sequence
 * @param[in]   n
 * @return  Returns n-th number of fibonacci sequence
 */
int Functions_Fibonacci(int n);

#endif /* FUNCTIONS_H_ */
