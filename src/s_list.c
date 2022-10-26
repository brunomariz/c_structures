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

typedef struct my_data
{
    int x1;
    float x2;
    char *x3;
} My_data;

void append_s_list(S_list *list, void *data)
{
    // S_list_item item = {data, NULL};
    // S_list_item *new_item = &item;
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