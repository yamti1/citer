#ifndef CITER_H
#define CITER_H

#include <stdlib.h>

typedef enum{
    BASE_ITERATOR
} IteratorType;

typedef struct {
    const void* array;
    const size_t element_size;
    const size_t array_length;
    size_t i;
} BaseIterator;

/// Get the next element from the iterator.
/// Result will be in `out` parameter.
/// Returns 1 if there was an element, 
///         0 if iteration should stop.
///         -1 on error.
int next(void* iterator, IteratorType iterator_type, void* out);

#endif