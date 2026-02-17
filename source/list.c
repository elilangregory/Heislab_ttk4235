#include <stdlib.h>
#include "list.h"

static Node* create_node(int value) {
    Node* node = malloc(sizeof(*node));
    if (!node) return NULL;

    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void list_init(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_push_front(List* list, int value) {
    Node* node = create_node(value);
    if (!node) return;

    node->next = list->head;

    if (list->head)
        list->head->prev = node;
    else
        list->tail = node;

    list->head = node;
    list->size++;
}

void list_push_back(List* list, int value) {
    Node* node = create_node(value);
    if (!node) return;

    node->prev = list->tail;

    if (list->tail)
        list->tail->next = node;
    else
        list->head = node;

    list->tail = node;
    list->size++;
}

void list_pop_front(List* list) {
    if (!list->head) return;

    Node* temp = list->head;
    list->head = temp->next;

    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(temp);
    list->size--;
}

void list_pop_back(List* list) {
    if (!list->tail) return;

    Node* temp = list->tail;
    list->tail = temp->prev;

    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(temp);
    list->size--;
}

void list_remove_at(List* list, size_t index) {
    if (index >= list->size) return;

    Node* current = list->head;

    for (size_t i = 0; i < index; i++)
        current = current->next;

    if (current->prev)
        current->prev->next = current->next;
    else
        list->head = current->next;

    if (current->next)
        current->next->prev = current->prev;
    else
        list->tail = current->prev;

    free(current);
    list->size--;
}

int list_get(List* list, size_t index) {
    if (index >= list->size) return -1;

    Node* current = list->head;
    for (size_t i = 0; i < index; i++)
        current = current->next;

    return current->value;
}

void list_set(List* list, size_t index, int value) {
    if (index >= list->size) return;

    Node* current = list->head;
    for (size_t i = 0; i < index; i++)
        current = current->next;

    current->value = value;
}

size_t list_size(List* list) {
    return list->size;
}

void list_free(List* list) {
    while (list->head)
        list_pop_front(list);
}
