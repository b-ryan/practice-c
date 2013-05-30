#include <stdlib.h>
#include <stdio.h>

struct Array {
  int* data;
  int capacity;
  int count;
};

struct Array* array_new(
) {
  struct Array* array = malloc(sizeof(struct Array));
  array->data = malloc(sizeof(int));
  array->capacity = 1;
  array->count = 0;
  return array;
}

void array_free(
  struct Array* array
) {
  free(array->data);
  free(array);
}

void resize_if_at_capacity(
  struct Array* array
) {
  if(array->count == array->capacity) {
    int capacity = array->capacity * 2;
    printf("Reached capacity, reallocating to hold %d items\n", capacity);
    array->data = realloc(array->data, capacity * sizeof(int));
    array->capacity = capacity;
  }
}

void array_append(
  struct Array* array,
  int value
) {
  printf("Adding to array value: %d\n", value);
  resize_if_at_capacity(array);
  array->data[array->count] = value;
  array->count++;
}

int array_count(
  struct Array* array
) {
  return array->count;
}

int array_get(
  struct Array* array,
  int index
) {
  return array->data[index];
}

void array_print(
  struct Array* array
) {
  int i;
  for(i = 0; i < array->count; i++) {
    printf("Index %d, Value %d\n", i, array->data[i]);
  }
}
