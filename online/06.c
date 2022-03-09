#include<stdio.h>
#include <math.h>
double t183(int v,int w,int x,int y,int z)
{
    float a=0.08,b=0.1393,c=0.1349,d=1.1287,e=1.4803;
    float sum=a*v+w*b+x*c+y*d+z*e;
    if (sum<183)
    {
        sum=183;
    }

    return sum;
}
double t383(int v,int w,int x,int y,int z)
{
    float a=0.07,b=0.1304,c=0.1217,d=1.1127,e=1.2458;
    float sum = a*v + w*b + x*c + y*d + z*e;
    if (sum<383)
    {
        sum=383;
    }

    return sum;
}
double t983(int v,int w,int x,int y,int z)
{
    float a=0.06,b=0.1087,c=0.1018,d=0.9572,e=1.1243;
    float sum=a*v+w*b+x*c+y*d+z*e;
    if (sum<983)
    {
        sum=983;
    }
    
    return sum;
}
int main()
{   
    int a,b,c,e,d;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);
    if ((t183(a,b,c,d,e) < t383(a,b,c,d,e)) && (t183(a,b,c,d,e) < t983(a,b,c,d,e)))
    {
        printf("%d",183);
    }
    else if ((t183(a,b,c,d,e) > t383(a,b,c,d,e)) && (t383(a,b,c,d,e) < t983(a,b,c,d,e)))
    {
        printf("%d",383);
    }
    else if ((t183(a,b,c,d,e)>t983(a,b,c,d,e)) && (t383(a,b,c,d,e)>t983(a,b,c,d,e)))
    {
        printf("%d",983);
    }

    return 0;
}