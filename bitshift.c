#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    a = 0xFF2342FF;
    printf("Int : %d\n Hex : %#10x\n", a, a);
    a = ~a; 
    printf("Int : %d\n Hex : %#10x\n", a, a);
}