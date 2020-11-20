#include <stdio.h>

#include "citer.h"


int is_even(void* value_ptr) {
    int value = *((int*)value_ptr);
    return value % 2 == 0;
}

int main() {
    int my_array[] = {1, 2, 3, 5, 6, 10, 11, 29};
    BaseIterator iterator1 = reversed(my_array, sizeof(int), 8);
    FilterIterator iterator2 = filter(&is_even, REVERSED_ITERATOR, &iterator1);

    int element = 0;
    while (next(&iterator2, FILTER_ITERATOR, &element)) {
        printf("%i\n", element);
    }
    
    return 0;
}
