#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../inc/c_structures.h"

// Print callback for example
void print_list_callback(void *data, int iter)
{
    int *array = (int *)data;
    printf("%d:\t[%d, %d]\n", iter, array[0], array[1]);
}

int main(int argc, char *argv[])
{
    // === Example ===
    printf("\n=== Example ===\n");

    // Stack creation
    CS_Stack *stack = c_structures_stack_create();
    // Create mock data
    int a1[2] = {1, 2};
    int a2[2] = {3, 4};
    int a3[2] = {5, 6};
    // Pushing to stack
    c_structures_stack_push(stack, (void *)a1);
    // Printing stack
    printf("==Initial stack:\n");
    c_structures_stack_print(stack, print_list_callback);
    // Push more items
    c_structures_stack_push(stack, (void *)a2);
    printf("==First push:\n");
    c_structures_stack_print(stack, print_list_callback);
    printf("==Second push:\n");
    c_structures_stack_push(stack, (void *)a3);
    c_structures_stack_print(stack, print_list_callback);
    // Pop items
    printf("==First pop:\n");
    CS_StackItem *pop_item_1 = c_structures_stack_pop(stack);
    printf("stack:\n");
    c_structures_stack_print(stack, print_list_callback);
    printf("popped item: [%d, %d]\n", ((int *)pop_item_1->data)[0], ((int *)pop_item_1->data)[1]);

    printf("==Second pop:\n");
    CS_StackItem *pop_item_2 = c_structures_stack_pop(stack);
    printf("stack:\n");
    c_structures_stack_print(stack, print_list_callback);
    printf("popped item: [%d, %d]\n", ((int *)pop_item_2->data)[0], ((int *)pop_item_2->data)[1]);

    printf("==Third pop:\n");
    CS_StackItem *pop_item_3 = c_structures_stack_pop(stack);
    printf("stack:\n");
    c_structures_stack_print(stack, print_list_callback);
    printf("popped item: [%d, %d]\n", ((int *)pop_item_3->data)[0], ((int *)pop_item_3->data)[1]);

    return 0;
}