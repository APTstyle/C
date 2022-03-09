#include<stdio.h>
#include <math.h>

int main()
{
    float PI = 3.14159;
    float r;
    scanf(" %f",&r);
    float area,lang;
    area = r*r*PI;
    lang = 2*r*PI;
    printf("%.3f\n%.3f",area,lang);

    return 0;
}