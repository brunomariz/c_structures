/**
 * c_structures.c - library for data structures
 */
#include "../inc/c_structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

CS_SList *c_structures_s_list_create()
{
    CS_SList *list = (CS_SList *)malloc(sizeof(*list));
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

CS_SList *c_structures_s_list_copy(CS_SList *list)
{
    /// @brief Copies a list
    /// @param list to copy
    /// @return copy of list

    CS_SList *copy_list = c_structures_s_list_create();
    CS_SListItem *current_item = list->head;
    for (size_t i = 0; i < list->length; i++)
    {
        c_structures_s_list_append(copy_list, current_item->data);
        current_item = current_item->next;
    }
    return copy_list;
}

void c_structures_s_list_free(CS_SList *list, void callback(void *data))
{
    /// @brief Iterates through items on list, and passes data to a
    ///                 callback that should handle freeing the memory, then
    ///                 frees the item and list memory. Callback function only
    ///                 has to deal with freeing the data memory.
    /// @param list List to free from memory.
    /// @param callback Function that should handle freeing memory
    ///                 from each of the lists items data.

    CS_SListItem *item = list->head;
    CS_SListItem *next_item = NULL;
    for (int i = 0; i < list->length; i++)
    {
        next_item = item->next;
        callback(item->data);
        free(item);
        item = next_item;
    }
    free(list);
}

void c_structures_s_list_append(CS_SList *list, void *data)
{
    /// @brief Appends a new item to the end of a list
    /// @param list to append item to
    /// @param data of new item

    CS_SListItem *new_item = (CS_SListItem *)malloc(sizeof(*new_item));
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

void c_structures_s_list_remove(CS_SList *list, int index)
{
    if ((index < list->length) && (index >= 0))
    {
        if (index > 0)
        {
            // Get item before the one that should be removed
            CS_SListItem *preceding_item = list->head;
            for (size_t i = 0; i < index - 1; i++)
            {
                preceding_item = preceding_item->next;
            }
            CS_SListItem *remove_item = preceding_item->next;
            preceding_item->next = remove_item->next;
        }
        else
        {
            // Update head
            list->head = list->head->next;
        }
        list->length--;
    }
}

void c_structures_s_list_print(CS_SList *list, void callback(void *data, int iter))
{
    /// @brief Print function for simple linked lists
    /// @param list to print
    /// @param callback custom function for printing each list item. The print_s_list function iterates through each item on the list and calls the callback function passing the items data and the iteration number as arguments

    CS_SListItem *curr = list->head;
    for (int i = 0; i < list->length; i++)
    {
        callback(curr->data, i);
        curr = curr->next;
    }
}

CS_SListItem *c_structures_s_list_get_item(CS_SList *list, int index)
{
    /// @brief Get item from lisit at specified index (starts at 0)
    /// @param list to look through for item
    /// @param index of item to get
    /// @return item of list at specified index, NULL if invalid index

    if (list->length > index)
    {
        CS_SListItem *item = list->head;
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

CS_SListItem *c_structures_s_list_find_item(CS_SList *list, void *data, int callback(void *data1, void *data2))
{
    /// @brief Find and item on a list.
    /// @param list to search for item.
    /// @param data to compare to each items data on list.
    /// @param callback function that returns 1 when data1 and data2 should be considered
    ///                 a match and returns 0 otherwise.
    /// @return Item that matches according to callback function.

    CS_SListItem *curr = list->head;
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

int c_structures_s_list_index_of(CS_SList *list, void *data, int callback(void *data1, void *data2))
{
    /// @brief Find the index of an item on the list.
    /// @param list to look for item.
    /// @param data to compare to each items data on the list.
    /// @param callback function that returns 1 when data1 and data2 should be considered
    ///                 a match and returns 0 otherwise.
    /// @return index of item or -1 if no match found.

    CS_SListItem *curr = list->head;
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

void c_structures_s_list_for_each(CS_SList *list, void callback(void *data, int index))
{
    CS_SListItem *item = list->head;
    for (int i = 0; i < list->length; i++)
    {
        callback(item->data, i);
        item = item->next;
    }
}
