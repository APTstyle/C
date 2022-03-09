#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int f(int sum,int mal){
    int count=0;
    while(1){
        if (sum==0&&sum==1){
            b(count,mal);
            break;
        }
        if (sum%2==0){
            sum/=2;
            count+=1;
        }
        if (sum%2==1){
            sum++;
            sum/=2;
            count+=1;
        }
    }
}
int b(int count,int mal){
    char a[5];
    for(int i=3;i>-1;i--){
        a[i]=count%2;
        count/=2;
    }
    p[mal]=a;
}
int main()
{
    char num[10][10];
    for (int i=0;i<10;i++){
        scanf("%s",&num[i]);
        num
    }
    
    //printf("%s\n",num);
    int sum=0;
    //printf("%d\n",sum);
    char p[100][100];
    for (int i=7;i>-1;i--){
        int a = pow(2,i);
        int b = num[7-i]-'0';
        sum = sum + (b*a);
        /*printf("num %d\n",b);
        printf("pow %d\n",a);
        printf("sum %d\n",sum);*/
    }
    //printf("%d\n",sum);

    int mal=0;

    return 0;
}