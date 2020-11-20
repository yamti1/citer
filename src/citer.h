#ifndef CITER_H
#define CITER_H

#include <stdlib.h>

typedef enum {
    BASE_ITERATOR,
    REVERSED_ITERATOR,
    FILTER_ITERATOR,
} IteratorType;

typedef struct {
    void* array;
    size_t element_size;
    size_t array_length;
    int i;
    int increment;
} BaseIterator;


typedef struct {
    void* iterator;
    IteratorType iterator_type;
} UnderlyinIterator;


typedef int (*FilterFunctionPtr) (void*);

typedef struct {
    FilterFunctionPtr filter_function_ptr;
    UnderlyinIterator underlying_iterator;
} FilterIterator;


/// Get an iterator over an array
/// `element_size` is the size in bytes of each element in the array.
/// `array_length` is the count of elements in the array.
BaseIterator iter(void* array, size_t element_size, size_t array_length);

/// Get a reversed iterator over an array. Iterate from finish to start.
/// `element_size` is the size in bytes of each element in the array.
/// `array_length` is the count of elements in the array.
BaseIterator reversed(void* array, size_t element_size, size_t array_length);

/// Get an iterator that only allows items that pass the filter.
/// Gets elements from the `underlying_iterator` and calls `filter_function_ptr` with each.
/// If the result is true returns that element. Otherwise moves to the next one.
FilterIterator filter(FilterFunctionPtr filter_function_ptr, IteratorType underlying_iterator_type, void* underlying_iterator);

/// Get the next element from the iterator.
/// Result will be in `out` parameter.
/// Returns 1 if there was an element, 
///         0 if iteration should stop or on error.
int next(void* iterator, IteratorType iterator_type, void* out);

#endif