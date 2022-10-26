#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../inc/s_list.h"

// Struct for example 1
typedef struct my_data
{
    int x1;
    float x2;
    char *x3;
} My_data;

// Callback for example 1
void my_print_callback(void *data, int iter)
{
    // Custom print function made specifically for My_data
    My_data *my_data = (My_data *)data;
    printf("===item %d===\nx1: %d\nx2: %f\nx3: %s\n",
           iter,
           my_data->x1, my_data->x2, my_data->x3);
}

// Callback for example 2
void print_list_callback(void *data, int iter)
{
    int *array = (int *)data;
    printf("%d:\t[%d, %d]\n", iter, array[0], array[1]);
}

int main(int argc, char *argv[])
{

    // ===Example 1 - struct data===
    printf("\n===Example 1 - struct data===\n");

    // List creation
    S_list *my_list = create_s_list();
    // Create mock data
    My_data data_1 = {1, 2.5, "abc"};
    My_data data_2 = {15, 0.2, "dfg"};
    My_data data_3 = {0, 4.25, "hij"};
    // Appending to list
    append_s_list(my_list, (void *)(&data_1));
    append_s_list(my_list, (void *)(&data_2));
    append_s_list(my_list, (void *)(&data_3));
    // Printing list
    print_s_list(my_list, my_print_callback);
    // Getting list item
    printf("\nGetting list item\n");
    int index = 0;
    S_list_item *second_item = get_item_s_list(my_list, index);
    if (second_item != NULL)
        my_print_callback(second_item->data, index);
    else
        printf("Item at index %d not found.\n", index);

    // ===Example 2 - list of arrays===
    printf("\n===Example 2 - list of arrays===\n");
    // Create list
    S_list *array_list = create_s_list();
    // Create data
    int a[2] = {1, 2};
    int b[2] = {3, 4};
    int c[2] = {5, 6};
    // Add data to list
    append_s_list(array_list, (void *)a);
    append_s_list(array_list, (void *)b);
    append_s_list(array_list, (void *)c);
    // Print list
    print_s_list(array_list, print_list_callback);

    // Creating random items on for loop
    S_list *random_list = create_s_list();
    // Set seed for random number function
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        // Allocate new array
        int *d = (int *)malloc(sizeof(int) * 2);
        // Insert random values
        d[0] = rand() % 10;
        d[1] = rand() % 5 + 5;
        // Append to list
        append_s_list(random_list, (void *)d);
    }
    // Print list
    printf("Random list:\n");
    print_s_list(random_list, print_list_callback);
    // Get item from list
    printf("Get item:\n");
    int random_list_index = 4;
    S_list_item *random_list_item = get_item_s_list(random_list, random_list_index);
    print_list_callback(random_list_item->data, random_list_index);

    return 0;
}