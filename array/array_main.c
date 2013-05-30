#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int main(
) {
  t_array array = array_new();

  array_append(array, 3);
  array_append(array, 6);
  array_append(array, 9);

  printf("array size: %d\n", array_count(array));
  printf("item at index 0: %d\n", array_get(array, 0));
  printf("item at index 1: %d\n", array_get(array, 1));

  array_print(array);

  array_free(array);
  return 0;
}
