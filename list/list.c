#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct Node {
  int data;
  struct Node* next;
};

struct List {
  struct Node* head;
  struct Node* tail;
  int count;
};

/***************************************/

struct Node* node_new(
  int data
) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void node_free(
  struct Node* node
) {
  printf("Freeing node with data: %d\n", node->data);
  free(node);
}

struct List* list_new(
) {
  struct List* list = malloc(sizeof(struct List));
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;
  return list;
}

void list_free(
  struct List* list
) {
  struct Node* curr = list->head;
  struct Node* next;
  while(curr != NULL) {
    next = curr->next;
    node_free(curr);
    curr = next;
  }
  free(list);
}

void list_append(
  struct List* list,
  int data
) {
  printf("Appending node with data %d\n", data);
  struct Node* node = node_new(data);
  if(list->tail == NULL) {
    list->head = node;
    list->tail = node;
  }
  else {
    list->tail->next = node;
    list->tail = node;
  }
  list->count++;
}

int list_count(
  struct List* list
) {
  return list->count;
}

int list_find(
  struct List* list,
  int data
) {
  struct Node* curr = list->head;
  int index = 0;

  while(curr != NULL) {
    if(curr->data == data) {
      return index;
    }
    curr = curr->next;
    index++;
  }
  return -1;
}

int list_get(
  struct List* list,
  int index
) {
  index %= list->count;
  if(index < 0)
    index += list->count;

  struct Node* curr = list->head;
  while(curr != NULL) {
    if(index-- == 0)
      return curr->data;
    curr = curr->next;
  }
}
