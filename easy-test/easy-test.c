#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <setjmp.h>

extern ULONGLONG testWinMain();

int main()
{
    ULONGLONG r = 0;
    jmp_buf buf = { 0 };
    setjmp(buf);
    __try
    {

        r = testWinMain();
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        longjmp(buf, 1);
    }

    printf("return %ull\n", r);

    system("pause");
}

/*

eq idtr+f0 4006ee00`00109ACB
eq idtr+f8 00000000`00000001

0000 0001 4006 9ACB

*/
