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
 * @file "stats.c" 
 * @brief sort and perform some data analytics on an array of unsigned char data 
 *
 * The functionality implemented in this module sorts an array of unsigned char
 * data passed into it, and also calculates a few different data analytics on it.
 *
 * @author Jesse Silverman
 * @date 6 January 2026
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_statistics(test, SIZE);
}

/* A function that prints the statistics of an array including minimum, maximum,
 * mean, and median. */
void print_statistics(unsigned char *data, unsigned int array_size) {

	// print the array, then the minimum, maximum, mean and median
	if (data == NULL || array_size == 0) {
		printf("Null array pointer or 0 size.");
		return;
	}
	print_array(data, array_size);
	printf("\n");
	printf("The minimum value in the array is: %u\n", find_minimum(data, array_size) );
	printf("The maximum value in the array is: %u\n", find_maximum(data, array_size) );
	printf("The mean value in the array is: %u\n", find_mean(data, array_size) );
	printf("The median value in the array is: %u\n", find_median(data, array_size) );
	printf("Warning: the array has now been sorted!\n");
	print_array(data, array_size);

}

/* Given an array of data and a length, prints the array to the screen */
void print_array(unsigned char *data, unsigned int array_size) {
	if (data == NULL || array_size == 0) return;
	printf("The Array: ");
	for (int i = 0; i != array_size; ++i) {
            printf("%d,", (unsigned int)data[i]);
	    if ( (i + 1)  % 20 == 0) printf("\n");
	}
	printf("\n");
}

/* Given an array of data and a length, returns the median value */
unsigned char find_median(unsigned char *data, unsigned int array_size) {
	// to do this, we must be sorted first!
	sort_array(data, array_size);
	// now we take the value at the middle, from index at array_size / 2, 
	// whether the number of elements is even or odd.
	return data[array_size / 2];
}

/* Given an array of data and a length, returns the mean value */
unsigned char find_mean(unsigned char *data, unsigned int array_size) {
	unsigned int total = 0;   // assumption, total value still fits in an unsigned int
	// this is the kind of thing that one would normally discuss as part of specs
	if (data == NULL || array_size == 0) return (unsigned char)0;
	for (int i = 0; i < array_size; ++i) {
            total += data[i];
	}
	return (unsigned char)(total / array_size);
}

/* Given an array of data and a length, returns the maximum value */
unsigned char find_maximum(unsigned char *data, unsigned int array_size) {
	unsigned char maximum = 0;
	if (data == NULL || array_size == 0) return maximum;
	for (int i = 0; i < array_size; ++i) {
            if ( data[i] > maximum) maximum = data[i];
	}
	return maximum;
}

/* Given an array of data and a length, returns the minimum value */
unsigned char find_minimum(unsigned char *data, unsigned int array_size) {
	unsigned int minimum = 255;
	if (data == NULL || array_size == 0) return minimum;
	for (int i = 0; i < array_size; ++i) {
            if ( data[i] < minimum) minimum = data[i];
	}
	return minimum;
}

// internal helper function to compare two unsigned char types, as unsigned chars
int ubc(const void *p1, const void *p2) {
	unsigned char uc1 = *(unsigned char *)p1;
	unsigned char uc2 = *(unsigned char *)p2;
	if (uc1 < uc2) return -1;
	else if (uc1 > uc2) return 1;
	return 0;

}
// int (*comp)(const void*, const void*

/* Given an array of data and a length, sorts the array from largest to smallest.  (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. ) */
void sort_array(unsigned char *data, unsigned int array_size) {

	// verified at:
	// void qsort( void* ptr, size_t count, size_t size,
	//             int (*comp)(const void*, const void*) );
	qsort( data, array_size, 1, ubc );
}
/* Add other Implementation File Code Here */
