#include "citer.h"

#include <string.h>
#include <stdio.h>


int iter(void* array, size_t element_size, size_t array_length, BaseIterator* out) {
    if (NULL == array) { return 0; }
    
    out->array = array;
    out->element_size = element_size;
    out->array_length = array_length;
    out->i = 0;
    out->increment = 1;

    return 1;
}

static int base_next(BaseIterator* iterator, void* out) {
    if (NULL == iterator || NULL == out) { return -1; }

    if ((iterator->increment > 0 && iterator->i >= iterator->array_length) ||
        (iterator->increment < 0 && iterator->i <= 0)) { 
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

