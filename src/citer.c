#include "citer.h"

#include <string.h>
#include <stdio.h>


BaseIterator iter(void* array, size_t element_size, size_t array_length) {
    if (NULL == array) { 
        printf("Warning: Iterating over a NULL array!");
        BaseIterator iterator;
        return iterator;
    }

    BaseIterator iterator = {
        .array = array,
        .element_size = element_size,
        .array_length = array_length,
        .i = 0,
        .increment = 1
    };

    return iterator;
}

BaseIterator reversed(void* array, size_t element_size, size_t array_length) {
    BaseIterator iterator = iter(array, element_size, array_length);
    iterator.increment = -1;
    iterator.i = array_length - 1;

    return iterator;
}

static int base_next(BaseIterator* iterator, void* out) {
    if (NULL == iterator || NULL == out) { return -1; }

    if ((iterator->increment > 0 && iterator->i >= iterator->array_length) ||
        (iterator->increment < 0 && iterator->i < 0)) { 
        // Iteration is over
        return 0; 
    }

    // Copy element into the output
    const char* array = (char*) (iterator->array);
    const char* element_ptr = array + ((iterator->i) * (iterator->element_size));
    memcpy(out, element_ptr, iterator->element_size);

    (iterator->i) += (iterator->increment);
    
    return 1;
}

int next(void* iterator, IteratorType iterator_type, void* out) {
    if (NULL == iterator || NULL == out) { return -1; }

    switch (iterator_type)
    {
    case BASE_ITERATOR:
    case REVERSED_ITERATOR:
        return base_next((BaseIterator*) iterator, out);
    
    default:
        return -1;
    }
}

