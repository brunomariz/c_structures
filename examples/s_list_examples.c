#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../inc/c_structures.h"

// Struct for example 1
typedef struct my_data
{
    int x1;
    float x2;
    char *x3;
} My_data;

// Print callback for example 1
void my_print_callback(void *data, int iter)
{
    // Custom print function made specifically for My_data
    My_data *my_data = (My_data *)data;
    printf("===item %d===\nx1: %d\nx2: %f\nx3: %s\n",
           iter,
           my_data->x1, my_data->x2, my_data->x3);
}

// Print callback for example 2
void print_list_callback(void *data, int iter)
{
    int *array = (int *)data;
    printf("%d:\t[%d, %d]\n", iter, array[0], array[1]);
}

// Free callback for example 2
void random_free_callback(void *data)
{
    free(data);
}

// Comparison callback for example 2
int compare_callback(void *data1, void *data2)
{
    int *a1 = (int *)data1;
    int *a2 = (int *)data2;
    if (a1[0] == a2[0])
    {
        return 1;
    }
    return 0;
}

// "For each" callback for example 2
void weird_fizz_buzz(void *data, int index)
{
    int *a = (int *)data;
    if (a[0] % 3 == 0 || a[1] % 3 == 0)
    {
        if (a[0] % 5 == 0 || a[1] % 5 == 0)
        {
            printf("FizzBuzz: [%d, %d]\n", a[0], a[1]);
        }
        else
        {
            printf("Fizz:     [%d, %d]\n", a[0], a[1]);
        }
    }
    else
    {
        if (a[0] % 5 == 0 || a[1] % 5 == 0)
        {
            printf("Buzz:     [%d, %d]\n", a[0], a[1]);
        }
        else
        {
            printf("\t  [%d, %d]\n", a[0], a[1]);
        }
    }
}

int main(int argc, char *argv[])
{

    // ===Example 1 - struct data===
    printf("\n===Example 1 - struct data===\n");

    // List creation
    CS_SList *my_list = c_structures_s_list_create();
    // Create mock data
    My_data data_1 = {1, 2.5, "abc"};
    My_data data_2 = {15, 0.2, "dfg"};
    My_data data_3 = {0, 4.25, "hij"};
    // Appending to list
    c_structures_s_list_append(my_list, (void *)(&data_1));
    c_structures_s_list_append(my_list, (void *)(&data_2));
    c_structures_s_list_append(my_list, (void *)(&data_3));
    // Printing list
    c_structures_s_list_print(my_list, my_print_callback);
    // Getting list item
    printf("=Getting list item\n");
    int index = 0;
    CS_SListItem *second_item = c_structures_s_list_get_item(my_list, index);
    if (second_item != NULL)
        my_print_callback(second_item->data, index);
    else
        printf("Item at index %d not found.\n", index);

    // ===Example 2 - list of arrays===
    printf("\n===Example 2 - list of arrays===\n");
    // Create list
    CS_SList *array_list = c_structures_s_list_create();
    // Create data
    int a[2] = {1, 2};
    int b[2] = {3, 4};
    int c[2] = {5, 6};
    // Add data to list
    c_structures_s_list_append(array_list, (void *)a);
    c_structures_s_list_append(array_list, (void *)b);
    c_structures_s_list_append(array_list, (void *)c);
    // Print list
    c_structures_s_list_print(array_list, print_list_callback);

    // Creating random items on for loop
    CS_SList *random_list = c_structures_s_list_create();
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
        c_structures_s_list_append(random_list, (void *)d);
    }
    // Print list
    printf("=Random list:\n");
    c_structures_s_list_print(random_list, print_list_callback);
    // Get item from list
    printf("=Get item:\n");
    int random_list_index = 4;
    CS_SListItem *random_list_item = c_structures_s_list_get_item(random_list, random_list_index);
    print_list_callback(random_list_item->data, random_list_index);
    // Find item on list
    printf("=Find item:\n");
    int compare_item[2] = {1, 0};
    CS_SListItem *found_item = c_structures_s_list_find_item(random_list, compare_item, compare_callback);
    if (found_item != NULL)
        print_list_callback(found_item->data, 0);
    else
        printf("No match.\n");
    // Index of item on list
    int index_of_item = c_structures_s_list_index_of(random_list, compare_item, compare_callback);
    printf("=Index of: %d\n", index_of_item);
    // For each item on list
    printf("=For each:\n");
    c_structures_s_list_for_each(random_list, weird_fizz_buzz);
    // Remove item from list
    printf("=Remove last item:\n");
    c_structures_s_list_remove(random_list, random_list->length - 1);
    c_structures_s_list_print(random_list, print_list_callback);
    printf("=Remove first item:\n");
    c_structures_s_list_remove(random_list, 0);
    c_structures_s_list_print(random_list, print_list_callback);
    printf("=Remove third item:\n");
    c_structures_s_list_remove(random_list, 2);
    c_structures_s_list_print(random_list, print_list_callback);

    // Free allocated space
    c_structures_s_list_free(random_list, random_free_callback);

    return 0;
}