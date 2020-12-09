# citer
Iterators library in C

## Examples
Take a look at `main.c` for examples:
```c
#include <stdio.h>

#include "citer.h"

// Basic Iteration
void basic_iteration() {
    printf("Basic iteration:\n");
    int arr[] = {1, 2, 5, 9};
    BaseIterator iterator = iter(arr, sizeof(*arr), 4);

    int element = 0;
    while (next(&iterator, BASE_ITERATOR, &element)) {
        printf("%i\n", element);
    }
}

// Reversed Iteration
void reversed_iteration() {
    printf("Reversed iteration:\n");
    int arr[] = {1, 2, 5, 9};
    ReversedIterator iterator = reversed(arr, sizeof(*arr), 4);

    int element = 0;
    while (next(&iterator, REVERSED_ITERATOR, &element)) {
        printf("%i\n", element);
    }
}

// Filtered & Reversed Iteration
int is_odd(void* value_ptr) {
    int value = *((int*)value_ptr);
    return value % 2 == 1;
}

void filter_reversed_iteration() {
    printf("Filter reversed iteration:\n");
    int arr[] = {1, 2, 5, 9};
    ReversedIterator iterator1 = reversed(arr, sizeof(*arr), 4);
    FilterIterator iterator2 = filter(&is_odd, REVERSED_ITERATOR, &iterator1);

    int element = 0;
    while (next(&iterator2, FILTER_ITERATOR, &element)) {
        printf("%i\n", element);
    }
}

int main() {
    basic_iteration();
    reversed_iteration();
    filter_reversed_iteration();
    
    return 0;
}
```

Note that the `next` function must recieve a reference to the iterator 
as well as the enum value specifing its type.
