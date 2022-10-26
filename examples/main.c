#include <stdio.h>

#include "../inc/c_structures.h"

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
    S_list *list = create_s_list();
    My_data data_1 = {1, 2.5, "abc"};
    void *void_ptr = (void *)(&data_1);
    append_s_list(list, void_ptr);
    append_s_list(list, void_ptr);
    append_s_list(list, void_ptr);
    print_s_list(list, my_print_callback);

    return 0;
}