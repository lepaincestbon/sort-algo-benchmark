#include "rand_array.h"
#include <bits/types/__FILE.h>
#include <stdio.h>
#include <stdlib.h>

// ==================================================================

rand_array_t rand_array_init(const size_t size) {
  rand_array_t ra;
  ra.size = size;
  if ((ra.arr = calloc(size, sizeof(int))) == NULL) {
    fprintf(stderr, "Error : Can't allocate memory for random array\nIn %s at line %d", __FILE__, __LINE__);
    exit(-1);
  }
  for (size_t i = 0; i < size; i++) {
    ra.arr[i] = rand();
  }

  return ra;
}

// ==================================================================

void rand_array_free(rand_array_t *ra) {
  free(ra->arr);
  ra->size = 0;
  ra->arr = NULL;
}

// ==================================================================

int rand_array_is_sorted(const rand_array_t ra) {
  int is_sorted = ra.arr != NULL;
  for (size_t i = 1; i < ra.size; i++) {
    is_sorted &= ra.arr[i - 1] <= ra.arr[i];
  }

  return is_sorted;
}

// ==================================================================

void rand_array_print(const rand_array_t ra) {
  if (ra.arr == NULL) {
    puts("<NULL>");
    return;
  }

  printf("Printing a rand_array_t of size %zu : \n", ra.size);
  putchar('|');
  for (size_t i = 0; i < ra.size; i++) {
    printf(" %d ", ra.arr[i]);
    putchar('|');
  }
}