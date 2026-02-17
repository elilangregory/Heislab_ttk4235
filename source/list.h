#ifndef LIST_H
#define LIST_H

#include <stddef.h>  // for size_t

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} List;

/* Initialization */
void list_init(List* list);

/* Insert */
void list_push_front(List* list, int value);
void list_push_back(List* list, int value);

/* Remove */
void list_pop_front(List* list);
void list_pop_back(List* list);
void list_remove_at(List* list, size_t index);

/* Access */
int  list_get(List* list, size_t index);
void list_set(List* list, size_t index, int value);

/* Info */
size_t list_size(List* list);

/* Cleanup */
void list_free(List* list);

#endif
