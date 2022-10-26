/**
 * c_structures.c - library for data structures
 */
#include "../inc/s_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

S_list *create_s_list()
{
    // S_list *list = &(S_list){NULL, NULL, 0};
    // S_list *list = &(S_list){0, NULL, NULL};
    S_list *list = (S_list *)malloc(sizeof(*list));
    return list;
}

void free_s_list(S_list *list)
{
    // TODO: implement
}

void append_s_list(S_list *list, void *data)
{
    S_list_item *new_item = (S_list_item *)malloc(sizeof(*new_item));
    new_item->data = data;
    new_item->next = NULL;

    if (list->length < 1)
    {
        list->tail = new_item;
        list->head = new_item;
    }
    else
    {
        list->tail->next = new_item;
        list->tail = new_item;
    }
    list->length++;
}

void print_s_list(S_list *list, void callback(void *data, int iter))
{
    /// @brief Print function for simple linked lists
    /// @param list to print
    /// @param callback custom function for printing each list item. The print_s_list function iterates through each item on the list and calls the callback function passing the items data and the iteration number as arguments

    S_list_item *curr = list->head;
    for (int i = 0; i < list->length; i++)
    {
        callback(curr->data, i);
        curr = curr->next;
    }
}

S_list_item *get_item_s_list(S_list *list, int index)
{
    /// @brief Get item from lisit at specified index (starts at 0)
    /// @param list to look through for item
    /// @param index of item to get
    /// @return item of list at specified index, NULL if invalid index

    if (list->length > index)
    {
        S_list_item *item = list->head;
        for (int i = 0; i < index; i++)
        {
            item = item->next;
        }
        return item;
    }
    printf("\n\033[0;33m");
    printf("WARNING: ");
    printf("\033[0m");
    printf("Invalid index, returning NULL. Might cause segmentation fault.\n\n");
    fflush(stdout);
    return NULL;
}
S_list_item *find_item_s_list(S_list *list, void *data)
{
    // TODO: Implement
}
