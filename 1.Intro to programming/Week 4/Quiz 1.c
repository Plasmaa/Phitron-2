#include <stdio.h>
int main()
{

    int ary[4] = {1, 2, 3, 4};

    int *p;

    p = ary + 3;

    *p = 5;

    printf("the number is --> %d\n", ary[3]);

}
