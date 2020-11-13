#include "citer.h"

#include <string.h>


static int base_next(BaseIterator* iterator, void* out) {
    if (NULL == iterator || NULL == out) { return -1; }

    if (iterator->i >= iterator->array_length) { 
        // Iteration is over
        return 0; 
    }

    // Copy element into the output
    const char* array = (char*) (iterator->array);
    const char* element_ptr = array + ((iterator->i) * (iterator->element_size));
    memcpy(out, element_ptr, iterator->element_size);

    (iterator->i)++;
    
    return 1;
}

/// Get the next element from the iterator.
/// Result will be in `out` parameter.
/// Returns 1 if there was an element, 
///         0 if iteration should stop,
///         -1 on error.
int next(void* iterator, IteratorType iterator_type, void* out) {
    switch (iterator_type)
    {
    case BASE_ITERATOR:
        return base_next((BaseIterator*) iterator, out);
    
    default:
        return -1;
    }
}

