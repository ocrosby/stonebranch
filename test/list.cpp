#include "gtest/gtest.h"

extern "C" {
    #include "list.h"
}

// Test list_size empty
TEST(list_size, empty_list) {
    node_t *head = NULL;
    ASSERT_EQ(0, list_size(head));
}

// Test list_size with one element
TEST(list_size, one_element) {
    node_t *head = NULL;
    int data = 42;
    list_insert(&head, &data, 0);
    ASSERT_EQ(1, list_size(head));
    list_delete(&head);
}

// Test list_size with multiple elements
TEST(list_size, multiple_elements) {
    node_t *head = NULL;
    int data1 = 42;
    int data2 = 43;
    int data3 = 44;
    list_insert(&head, &data1, 0);
    list_insert(&head, &data2, 0);
    list_insert(&head, &data3, 0);
    ASSERT_EQ(3, list_size(head));
    list_delete(&head);
}

