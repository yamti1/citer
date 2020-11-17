#ifndef CITER_H
#define CITER_H

#include <stdlib.h>

typedef enum {
    BASE_ITERATOR,
    REVERSED_ITERATOR
} IteratorType;

typedef struct {
    void* array;
    size_t element_size;
    size_t array_length;
    size_t i;
    int increment;
} BaseIterator;

/// Get an iterator over an array
/// `element_size` is the size in bytes of each element in the array.
/// `array_length` is the count of elements in the array.
/// `out` is the resulted BaseIterator.
/// Returns 1 if `array` is NULL, 0 otherwise.
BaseIterator iter(void* array, size_t element_size, size_t array_length);

/// Get the next element from the iterator.
/// Result will be in `out` parameter.
/// Returns 1 if there was an element, 
///         0 if iteration should stop.
///         -1 on error.
int next(void* iterator, IteratorType iterator_type, void* out);

#endif