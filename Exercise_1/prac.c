#include <stdio.h>


int main(){

    int a = 0x82424000;
    __u_int b = 0x82424000;

    printf("%x\n", a);
    printf("%d\n", a);
    printf("%u\n", b);
}