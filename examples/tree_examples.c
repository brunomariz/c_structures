#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../inc/c_structures.h"

typedef struct
{
    int *array;
    int parent_id
} Example_TreeNodeData;

void tree_example_tree_print_nodes_and_parents_callback(void *data, int iter)
{
    static int pad_len = 0;
    CS_TreeNode *node = data;
    Example_TreeNodeData *node_data = node->data;
    int *node_array;
    int parent_id = 0;
    if (node_data != NULL)
    {
        node_array = node_data->array;
        parent_id = node_data->parent_id;
    }

    printf("%*.sid: %d data: %d | [%d %d]\n", pad_len, " ", node->id, parent_id, node_array[0], node_array[1]);
    if ((node->children != NULL) && (node->children->length > 0))
    {
        pad_len += 8;
        printf("%*.schildren: [\n", pad_len, " ");
        c_structures_s_list_print(node->children, tree_example_tree_print_nodes_and_parents_callback);
        printf("%*.s]\n", pad_len, " ");
        pad_len -= 8;
    }
}

int main(int argc, char *argv[])
{
    /// ==Example 1 - Creating tree==
    // Create nodes
    CS_Tree *tree = c_structures_tree_create();
    CS_TreeNode *node1 = c_structures_tree_node_create(1, NULL);
    CS_TreeNode *node2 = c_structures_tree_node_create(2, NULL);
    CS_TreeNode *node3 = c_structures_tree_node_create(3, NULL);
    CS_TreeNode *node4 = c_structures_tree_node_create(4, NULL);
    // Define children of node 1
    c_structures_tree_node_add_child(node1, node2);
    c_structures_tree_node_add_child(node1, node3);
    // Define children of node 3
    c_structures_tree_node_add_child(node3, node4);
    // Add node1 as root node to the tree
    c_structures_tree_add_root_node(tree, node1);
    // Print the tree
    printf("==Tree:\n");
    c_structures_tree_print(tree);

    // Set data for nodes
    int a1[2] = {1, 11};
    Example_TreeNodeData node1_data = {a1, 1};
    node1->data = &node1_data;
    int a2[2] = {2, 22};
    Example_TreeNodeData node2_data = {a2, 1};
    node2->data = &node2_data;
    int a3[2] = {3, 33};
    Example_TreeNodeData node3_data = {a3, 1};
    node3->data = &node3_data;
    int a4[2] = {4, 44};
    Example_TreeNodeData node4_data = {a4, 3};
    node4->data = &node4_data;
    // Print tree showing the data on each node
    printf("==Tree (showing node data):\n");
    c_structures_s_list_print(tree->root_nodes, tree_example_tree_print_nodes_and_parents_callback);

    // Create new node and add to the tree
    CS_TreeNode *node5 = c_structures_tree_node_create(5, NULL);
    // Add node 5 as child of nodes 2 and 3
    c_structures_tree_node_add_child(node2, node5);
    c_structures_tree_node_add_child(node3, node5);
    // Print the tree
    printf("==Add children:\n");
    c_structures_tree_print(tree);
    // Remove child from node 3
    c_structures_tree_node_remove_child(node3, 4);
    // Print the tree
    printf("==Remove child:\n");
    c_structures_tree_print(tree);

    /// ===Example 2 - Multitree===
    CS_Tree *multitree = c_structures_tree_create();
    // Create new nodes
    CS_TreeNode *node6 = c_structures_tree_node_create(6, NULL);
    CS_TreeNode *node7 = c_structures_tree_node_create(7, NULL);
    CS_TreeNode *node8 = c_structures_tree_node_create(8, NULL);
    CS_TreeNode *node9 = c_structures_tree_node_create(9, NULL);
    c_structures_tree_node_add_child(node7, node8);
    c_structures_tree_node_add_child(node7, node9);
    c_structures_tree_add_root_node(multitree, node1);
    c_structures_tree_add_root_node(multitree, node6);
    c_structures_tree_add_root_node(multitree, node7);
    printf("==Multiree:\n");
    c_structures_tree_print(multitree);
    return 0;
}