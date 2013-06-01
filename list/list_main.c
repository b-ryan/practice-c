#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

#define TIME_START t = clock();
#define TIME_STOP(event) \
  t = clock() - t;\
  printf("%s,%d,%f\n", event, n, ((float)t / CLOCKS_PER_SEC));

int main(
  int argc,
  char** argv
) {
  if(argc < 2) {
    puts("Please supply a number");
    return 1;
  }

  int nitems = atoi(argv[1]);
  t_list list = list_new();

  printf("Event,N,Time\n");

  int n;
  clock_t t;

  for(n = 0; n < nitems; n++) {
    TIME_START
    list_append(list, n);
    TIME_STOP("append")

    TIME_START
    list_count(list);
    TIME_STOP("count");

    TIME_START
    list_get(list, n / 2);
    TIME_STOP("index");

    TIME_START
    list_find(list, n / 2);
    TIME_STOP("search");
  }

  list_free(list);
  return 0;
}
