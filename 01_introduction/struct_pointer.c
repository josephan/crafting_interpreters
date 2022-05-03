#include <stdio.h>

struct person
{
    char *name;
    struct person *friend;
};

int main(void)
{
    struct person p1 = {.name = "Joseph"};
    struct person p2 = {.name = "Bill"};

    p1.friend = &p2;

    if (p1.friend == NULL)
    {
        printf("p1 friend is null");
    }

    if (p2.friend == NULL)
    {
        printf("p2 friend is null");
    }

    return 0;
}