#include <stdio.h>
#include <time.h>
 
int main(void)
{
    float temps;
    clock_t t1, t2;
 
    t1 = clock();
 
    // Ton programme
     
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
 
    return 0;
}