#include <stdio.h>

#include "../inc/s_list.h"

typedef struct my_data
{
    int x1;
    float x2;
    char *x3;
} My_data;

void my_print_callback(void *data, int iter)
{
    // Custom print function made specifically for My_data
    My_data *my_data = (My_data *)data;
    printf("===item %d===\nx1: %d\nx2: %f\nx3: %s\n",
           iter,
           my_data->x1, my_data->x2, my_data->x3);
}

int main(int argc, char *argv[])
{
    // List creation
    S_list *list = create_s_list();
    // Create mock data
    My_data data_1 = {1, 2.5, "abc"};
    My_data data_2 = {15, 0.2, "dfg"};
    My_data data_3 = {0, 4.25, "hij"};
    // Appending to list
    append_s_list(list, (void *)(&data_1));
    append_s_list(list, (void *)(&data_2));
    append_s_list(list, (void *)(&data_3));
    // Printing list
    print_s_list(list, my_print_callback);
    // Getting list item
    printf("\nGetting list item\n");
    int index = 0;
    S_list_item *second_item = get_item_s_list(list, index);
    if (second_item != NULL)
        my_print_callback(second_item->data, index);
    else
        printf("Item at index %d not found.\n", index);

    return 0;
}