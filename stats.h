/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file "stats.h"
 * @brief Header file for First weeks's graded assignment for the course.
 *
 * Implements a variety of functions to both compute various statistics for
 * and to also sort an array of unsigned int values.
 *
 * @author Jesse Silverman
 * @date 23 December, 2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Print array statistics.
 *
 *  A function that prints the statistics of an array including minimum, maximum,
 *  mean, and median.
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return void
 */
void print_statistics(unsigned char *data, unsigned int array_size); 



/**
 * @brief Print array to stdout
 *
 * Given an array of data and a length, prints the array to the screen (stdout)
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return void
 */
void print_array(unsigned char *data, unsigned int array_size);


/**
 * @brief Return median value of array
 *
 * Given an array of data and a length, returns the median value
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return unsigned char -- value of the median
 */
unsigned char find_median(unsigned char *data, unsigned int array_size);


/**
 * @brief Return mean value of array
 *
 * Given an array of data and a length, returns the mean value
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return unsigned char -- value of the mean
 */
unsigned char find_mean(unsigned char *data, unsigned int array_size);


/**
 * @brief Return maximum value of array
 *
 * Given an array of data and a length, returns the maximum value
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return unsigned char -- value of the maximum element
 */
unsigned char find_maximum(unsigned char *data, unsigned int array_size);


/**
 * @brief Return minimum value of array
 *
 * Given an array of data and a length, returns the minimum value
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return unsigned char -- value of the minimum element
 */
unsigned char find_minimum(unsigned char *data, unsigned int array_size);


/**
 * @brief Sort an array of unsigned char values
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) 
 * should be the smallest value. ) Sorts in place.
 *
 * @param unsigned char *data -- input array of data
 * @param unsigned int array_size -- Number of elements in array
 *
 * @return void
 */
void sort_array(unsigned char *data, unsigned int array_size);



#endif /* __STATS_H__ */
