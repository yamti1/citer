#include <stdio.h>

#include "citer.h"


int main() {
    int my_array[4] = {1, 2, 3, 5};
    BaseIterator iterator;
    if (!iter(my_array, sizeof(int), 4, &iterator)) {
        printf("Failed iterating array");
    }

    int element = 0;
    while (next(&iterator, BASE_ITERATOR, &element)) {
        printf("%i\n", element);
    }
    
    return 0;
}
