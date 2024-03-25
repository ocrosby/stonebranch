#include "list.h"

#include <stdio.h>
#include <stdlib.h>


// list_size returns the number of elements in the list
int list_size(node_t *head) {
    int size = 0;
    node_t *current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    } // end while

    return size;
}

// list_insert inserts a new node with the given data at the beginning or end of the list
void list_insert(node_t **head, void *data, int insert_at_end) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    } // end if

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        // insert into an empty list
        *head = new_node;
    } else if (!insert_at_end) {
        // insert at the end
        node_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        } // end while

        current->next = new_node;
    } else {
        // insert at the beginning
        new_node->next = *head;
        *head = new_node;
    } // end if
}

// list_delete deletes all nodes in the list
void list_delete(node_t **head) {
    node_t *current = *head;
    node_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    } // end while

    *head = NULL;
}

// list_print prints the data in each node of the list
void list_print(node_t *head, void (*print)(void *)) {
    node_t *current = head;

    while (current != NULL) {
        print(current->data);
        current = current->next;
    } // end while
}
