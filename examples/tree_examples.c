#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../inc/c_structures.h"

int main(int argc, char *argv[])
{
    /// ==Example 1 - Creating tree==
    // Create nodes
    CS_Tree *tree = c_structures_tree_create();
    CS_TreeNode *node1 = c_structures_tree_node_create(1);
    CS_TreeNode *node2 = c_structures_tree_node_create(2);
    CS_TreeNode *node3 = c_structures_tree_node_create(3);
    CS_TreeNode *node4 = c_structures_tree_node_create(4);
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

    // Create new node and add to the tree
    CS_TreeNode *node5 = c_structures_tree_node_create(5);
    // Add node 5 as child of nodes 2 and 3
    c_structures_tree_node_add_child(node2, node5);
    c_structures_tree_node_add_child(node3, node5);
    // Print the tree
    printf("==New Tree:\n");
    c_structures_tree_print(tree);
    // Remove child from node 3
    c_structures_tree_node_remove_child(node3, 4);
    // Print the tree
    printf("==New Tree:\n");
    c_structures_tree_print(tree);

    /// ===Example 2 - Multitree===
    CS_Tree *multitree = c_structures_tree_create();
    // Create new nodes
    CS_TreeNode *node6 = c_structures_tree_node_create(6);
    CS_TreeNode *node7 = c_structures_tree_node_create(7);
    CS_TreeNode *node8 = c_structures_tree_node_create(8);
    CS_TreeNode *node9 = c_structures_tree_node_create(9);
    c_structures_tree_node_add_child(node7, node8);
    c_structures_tree_node_add_child(node7, node9);
    c_structures_tree_add_root_node(multitree, node1);
    c_structures_tree_add_root_node(multitree, node6);
    c_structures_tree_add_root_node(multitree, node7);
    printf("==Multiree:\n");
    c_structures_tree_print(multitree);
    return 0;
}