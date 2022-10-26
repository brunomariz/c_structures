#ifndef _C_STRUCTURES_H
#define _C_STRUCTURES_H

// Simple linked list

/// @brief Simple linked list item
typedef struct s_list_item
{
    void *data;
    struct s_list_item *next;
} S_list_item;

/// @brief Simple linked list
typedef struct S_list
{
    int length;
    S_list_item *head;
    S_list_item *tail;
} S_list;

S_list *create_s_list();
void append_s_list(S_list *list, void *data);
void print_s_list(S_list *list, void callback(void *data, int iter));

#endif
