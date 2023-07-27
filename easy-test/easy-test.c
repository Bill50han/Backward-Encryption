#include <stdio.h>
#include <stdlib.h>

extern void Int0f();

int main()
{
    printf("%p\n", Int0f);
    system("pause");
}

/*

eq idtr+f0 4006ee00`00109ACB
eq idtr+f8 00000000`00000001

0000 0001 4006 9ACB

*/
