#include<stdio.h>
#include <math.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    printf("%.1f\n", ((-b)+sqrt(b*b-4*a*c))/(2*a));
    printf("%.1f\n", ((-b)-sqrt(b*b-4*a*c))/(2*a));
    return 0;
}