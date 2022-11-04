#include "../inc/c_structures.h"

#include <stdio.h>

CS_Stack *c_structures_stack_create()
{
    return (CS_Stack *)c_structures_s_list_create();
}

void c_structures_stack_push(CS_Stack *stack, void *data)
{
    CS_StackItem *new_item = (CS_StackItem *)malloc(sizeof(*new_item));
    new_item->data = data;
    new_item->next = NULL;

    if (stack->length < 1)
    {
        stack->head = new_item;
        stack->tail = new_item;
    }
    else
    {
        new_item->next = stack->head;
        stack->head = new_item;
    }
    stack->length++;
}

CS_StackItem *c_structures_stack_pop(CS_Stack *stack)
{
    if (stack->length > 0)
    {
        CS_StackItem *item = stack->head;
        stack->head = item->next;
        stack->length--;
        return item;
    }
    printf("\n\033[0;33m");
    printf("WARNING: ");
    printf("\033[0m");
    printf("Pop empty stack, returning NULL. Might cause segmentation fault.\n\n");
    fflush(stdout);
    return NULL;
}

void c_structures_stack_print(CS_Stack *stack, void callback(void *data, int iter))
{
    c_structures_s_list_print(stack, callback);
}
