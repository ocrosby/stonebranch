#ifndef _LIST_H_
#define _LIST_H_

typedef struct Node {
    void *data;
    struct Node *next;
} node_t;

int list_size(node_t *head);
void list_insert(node_t **head, void *data, int insert_at_end);
void list_delete(node_t **head);
void list_print(node_t *head, void (*print)(void *));

#endif // _LIST_H_
