#ifndef _C_STRUCTURES_H
#define _C_STRUCTURES_H

#include <stdlib.h>

typedef unsigned char uint8;
typedef unsigned int uint;

// === Simple linked list ===

/// @brief Simple linked list item
typedef struct s_list_item
{
    void *data;
    struct s_list_item *next;
} CS_SListItem;

/// @brief Simple linked list
typedef struct s_list
{
    int length;
    CS_SListItem *head;
    CS_SListItem *tail;
} CS_SList;

CS_SList *c_structures_s_list_create();
void c_structures_s_list_free(CS_SList *list, void callback(void *data));
void c_structures_s_list_append(CS_SList *list, void *data);
void c_structures_s_list_remove(CS_SList *list, int index);
void c_structures_s_list_print(CS_SList *list, void callback(void *data, int iter));
CS_SListItem *c_structures_s_list_get_item(CS_SList *list, int index);
CS_SListItem *c_structures_s_list_find_item(CS_SList *list, void *data, int callback(void *data1, void *data2));
int c_structures_s_list_index_of(CS_SList *list, void *data, int callback(void *data1, void *data2));
void c_structures_s_list_for_each(CS_SList *list, void callback(void *data, int index));

// === Tree ===
typedef struct
{
    int id;
    CS_SList *children;
} CS_TreeNode;

typedef struct
{
    CS_SList *root_nodes;
} CS_Tree;

CS_Tree *c_structures_tree_create();
void c_structures_tree_add_root_node(CS_Tree *tree, CS_TreeNode *node);
CS_TreeNode *c_structures_tree_node_create(int id);
void c_structures_tree_node_add_child(CS_TreeNode *parent, CS_TreeNode *child);
void c_structures_tree_print(CS_Tree *tree);

#endif
