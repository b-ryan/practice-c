#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(
  char** argv,
  int argc
) {
  struct List* list = list_new();

  list_append(list, 8);
  list_append(list, 9);
  list_append(list, 2);

  printf("List size: %d\n", list_count(list));
  printf("Index of node with data 9: %d\n", list_find(list, 9));
  printf("Data at index 0: %d\n", list_get(list, 0));
  printf("Data at index 2: %d\n", list_get(list, 2));
  printf("Data at index -1: %d\n", list_get(list, -1));

  list_free(list);
  return 0;
}
