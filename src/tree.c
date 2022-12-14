#include "../inc/c_structures.h"

#include <stdio.h>

int c_structures_tree_node_compare_callback(void *data1, void *data2);
void c_structures_tree_print_list_callback(void *data, int iter);

CS_Tree *c_structures_tree_create()
{
    CS_Tree *tree = malloc(sizeof *tree);
    CS_SList *root_nodes = c_structures_s_list_create();
    tree->root_nodes = root_nodes;
    return tree;
}

void c_structures_tree_add_root_node(CS_Tree *tree, CS_TreeNode *node)
{
    if (tree->root_nodes == NULL)
    {
        tree->root_nodes = c_structures_s_list_create();
    }

    c_structures_s_list_append(tree->root_nodes, node);
}

CS_TreeNode *c_structures_tree_node_create(int id, void *data)
{
    CS_TreeNode *node = malloc(sizeof *node);
    node->id = id;
    node->data = data;
    node->children = c_structures_s_list_create();
    return node;
}

void c_structures_tree_node_add_child(CS_TreeNode *parent, CS_TreeNode *child)
{
    if (parent->children == NULL)
    {
        parent->children = c_structures_s_list_create();
    }
    c_structures_s_list_append(parent->children, child);
}

void c_structures_tree_node_remove_child(CS_TreeNode *parent, int child_id)
{
    CS_TreeNode *compare_node = c_structures_tree_node_create(child_id, NULL);
    int index = c_structures_s_list_index_of(parent->children,
                                             compare_node,
                                             c_structures_tree_node_compare_callback);
    c_structures_s_list_remove(parent->children, index);
}

int c_structures_tree_node_compare_callback(void *data1, void *data2)
{
    CS_TreeNode *node1 = data1;
    CS_TreeNode *node2 = data2;
    if (node1->id == node2->id)
    {
        return 1;
    }
    return 0;
}

void c_structures_tree_print(CS_Tree *tree)
{
    c_structures_s_list_print(tree->root_nodes, c_structures_tree_print_list_callback);
}

void c_structures_tree_print_list_callback(void *data, int iter)
{
    static int pad_len = 0;
    CS_TreeNode *node = data;
    printf("%*.sid: %d\n", pad_len, " ", node->id);
    if ((node->children != NULL) && (node->children->length > 0))
    {
        pad_len += 8;
        printf("%*.schildren: [\n", pad_len, " ");
        c_structures_s_list_print(node->children, c_structures_tree_print_list_callback);
        printf("%*.s]\n", pad_len, " ");
        pad_len -= 8;
    }
}