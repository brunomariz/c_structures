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
} CSSListItem;

/// @brief Simple linked list
typedef struct s_list
{
    int length;
    CSSListItem *head;
    CSSListItem *tail;
} CSSList;

CSSList *c_structures_s_list_create();
void c_structures_s_list_free(CSSList *list, void callback(void *data));
void c_structures_s_list_append(CSSList *list, void *data);
void c_structures_s_list_print(CSSList *list, void callback(void *data, int iter));
CSSListItem *c_structures_s_list_get_item(CSSList *list, int index);
CSSListItem *c_structures_s_list_find_item(CSSList *list, void *data, int callback(void *data1, void *data2));
int c_structures_s_list_index_of(CSSList *list, void *data, int callback(void *data1, void *data2));
void c_structures_s_list_for_each(CSSList *list, void callback(void *data, int index));

// === Dynamic Array ===
typedef struct
{
    uint length;
    uint8 data[];
} CSDArray;

CSDArray *c_structures_d_array_create(void);

#endif
