#include <stdio.h>

#include "citer.h"


int main() {
    int my_array[4] = {1, 2, 3, 5};
    BaseIterator iterator = {
        .array = my_array,
        .array_length = 4,
        .element_size = sizeof(int),
        .i = 0
    };

    int element = 0;
    while (next(&iterator, BASE_ITERATOR, &element))
    {
        printf("%i\n", element);
    }
    return 0;
}
