#ifndef _C_STRUCTURES_H
#define _C_STRUCTURES_H

typedef unsigned char uint8;
typedef unsigned int uint;

// === Simple linked list ===

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

S_list *c_structures_s_list_create();
void c_structures_s_list_free(S_list *list, void callback(void *data));
void c_structures_s_list_append(S_list *list, void *data);
void c_structures_s_list_print(S_list *list, void callback(void *data, int iter));
S_list_item *c_structures_s_list_get_item(S_list *list, int index);
S_list_item *c_structures_s_list_find_item(S_list *list, void *data, int callback(void *data1, void *data2));
int c_structures_s_list_index_of(S_list *list, void *data, int callback(void *data1, void *data2));
void c_structures_s_list_for_each(S_list *list, void callback(void *data, int index));

// === Dynamic Array ===
typedef struct
{
    uint length;
    uint8 data[];
} D_array;

D_array *d_array_create(void);

#endif
