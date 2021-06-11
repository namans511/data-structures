#include <stdio.h>
#include <stdlib.h>

// void lol(int *p) {
//     printf("%u,%d\n",p,*p);
//     *p=5;
// }

int main(int argc, char const *argv[])
{
    int a = 10;
    // lol(&a);
    // printf("a%u,%d\n",&a,a);
    int *p;
    printf("%lu,%u\n",sizeof(*p),p);
    p=(int *)malloc(sizeof(int));
    *p=10;
    printf("%d\n",*p);
    printf("%lu,%u\n",sizeof(p),p);
    return 0;
}