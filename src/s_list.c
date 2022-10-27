/**
 * c_structures.c - library for data structures
 */
#include "../inc/c_structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

S_list *s_list_create()
{
    // S_list *list = &(S_list){NULL, NULL, 0};
    // S_list *list = &(S_list){0, NULL, NULL};
    S_list *list = (S_list *)malloc(sizeof(*list));
    return list;
}

void s_list_free(S_list *list, void callback(void *data))
{
    /// @brief Iterates through items on list, and passes data to a
    ///                 callback that should handle freeing the memory, then
    ///                 frees the item and list memory. Callback function only
    ///                 has to deal with freeing the data memory.
    /// @param list List to free from memory.
    /// @param callback Function that should handle freeing memory
    ///                 from each of the lists items data.

    S_list_item *item = list->head;
    S_list_item *next_item = NULL;
    for (int i = 0; i < list->length; i++)
    {
        next_item = item->next;
        callback(item->data);
        free(item);
        item = next_item;
    }
    free(list);
}

void s_list_append(S_list *list, void *data)
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

void s_list_print(S_list *list, void callback(void *data, int iter))
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

S_list_item *s_list_get_item(S_list *list, int index)
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

S_list_item *s_list_find_item(S_list *list, void *data, int callback(void *data1, void *data2))
{
    /// @brief Find and item on a list.
    /// @param list to search for item.
    /// @param data to compare to each items data on list.
    /// @param callback function that returns 1 when data1 and data2 should be considered
    ///                 a match and returns 0 otherwise.
    /// @return Item that matches according to callback function.

    S_list_item *curr = list->head;
    for (int i = 0; i < list->length; i++)
    {
        if (callback(data, curr->data))
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int s_list_index_of(S_list *list, void *data, int callback(void *data1, void *data2))
{
    /// @brief Find the index of an item on the list.
    /// @param list to look for item.
    /// @param data to compare to each items data on the list.
    /// @param callback function that returns 1 when data1 and data2 should be considered
    ///                 a match and returns 0 otherwise.
    /// @return index of item or -1 if no match found.

    S_list_item *curr = list->head;
    for (int i = 0; i < list->length; i++)
    {
        if (callback(data, curr->data))
        {
            return i;
        }
        curr = curr->next;
    }
    return -1;
}

void s_list_for_each(S_list *list, void callback(void *data, int index))
{
    S_list_item *item = list->head;
    for (int i = 0; i < list->length; i++)
    {
        callback(item->data, i);
        item = item->next;
    }
}