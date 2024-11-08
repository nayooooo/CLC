#include <stdio.h>
#include "../list.h"

struct list_int
{
    int* data;
    struct list_int* next;
};
typedef struct list_int **list_int_head;

bool int_pred(list_node node, void* data)
{
    return *(int*)(node->data) == *(int*)data;
}

int main()
{
    list_int_head l = (list_int_head)list_create();

    for (int i = 0; i < 10; i++)
    {
        list_push((list_head)l, &i, sizeof(i));
    }

    int num = 3;
    list_remove_if((list_head)l, &num, int_pred, nullptr);

    list_delete((list_head)l, nullptr);

    return 0;
}
