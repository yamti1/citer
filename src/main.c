#include <stdio.h>

#include "citer.h"


void basic_iteration() {
    printf("Basic iteration:\n");
    int arr[] = {1, 2, 5, 9};
    BaseIterator iterator = iter(arr, sizeof(*arr), 4);

    int element = 0;
    while (next(&iterator, BASE_ITERATOR, &element)) {
        printf("%i\n", element);
    }
}

void reversed_iteration() {
    printf("Reversed iteration:\n");
    int arr[] = {1, 2, 5, 9};
    ReversedIterator iterator = reversed(arr, sizeof(*arr), 4);

    int element = 0;
    while (next(&iterator, REVERSED_ITERATOR, &element)) {
        printf("%i\n", element);
    }
}

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
