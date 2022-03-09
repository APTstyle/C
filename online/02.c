#include<stdio.h>
#include <math.h>

int main()
{
    int a=0,b=0,c=0,x,y,z,i,count=0;
    char d;
    for(i=0;i<5;i++)
    {
        scanf("\n %c",&d);
        if (d == '1')
        {
            x=a,y=b,z=c;
            a=1,b=x,c=y;
        }
        else if(d == '2')
        {
            x=a,y=b,z=c;
            a=0,b=1,c=x;
        }
        else if(d == '3')
        {
            x=a,y=b,z=c;
            a=0,b=0,c=1;
        }
        else if(d == 'H')
        {
            x=a,y=b,z=c;
            c=0,b=0,a=0;
        }
        else if(d == 'O')
        {
            count = count + 1;
        }
        if (count == 3)
        {
            a=0,b=0,c=0;
            count=0;
        }
        
        /*d=0;*/
    }

    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    /*printf("%d\n",count);*/
    
}