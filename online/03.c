#include<stdio.h>
#include <math.h>

int main()
{
    int a,b,x,y;
    float gold,spend,tax;
    scanf(" %d",&a);
    scanf(" %d",&b);
    scanf(" %d",&x);
    scanf(" %d",&y);
    spend = y*0.05;
    tax = (a+b)*x*0.08;
    gold = (a+b)*x-spend-tax;
    printf("%.1f\n%.1f\n%.1f\n",gold,spend,tax);
    return 0;
}