#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int main()
{
    int a;
    scanf("%d",&a);
    if (a==1){
        int times;
        scanf("%d",&times);
        times = times/2+1;
        for (int i=1;i<times;i++){
            for(int j=0;j<i;j++){
                printf("*");
            }
            printf("\n");
        }
        for (int i=times;i>0;i--){
            for(int j=0;j<i;j++){
                printf("*");
            }
            printf("\n");
        }
    }
    if (a==2){
        int times;
        scanf("%d",&times);
        int mal=times/2;
        for (int i=0;i<mal;i++){
            for(int j=i;j<mal;j++){
                printf(".");
            }
            for(int k=mal-i;k<mal+1;k++){
                printf("*");
            }
            printf("\n");
        }
        for (int i=mal+1;i>0;i--){
            for(int j=i-1;j<mal;j++){
                printf(".");
            }
            for(int k=mal-i;k<mal;k++){
                printf("*");
            }
            printf("\n");
        }
    }
    if (a==3){
        int times;
        scanf("%d",&times);
        int mal=times/2;
        for (int i=0;i<mal;i++){
            for(int j=i;j<mal;j++){
                printf(".");
            }
            for(int k=times;k>times-2*i-1;k--){
                printf("*");
            }
            printf("\n");
        }
        for (int i=mal;i>-1;i--){
            for(int j=i;j<mal;j++){
                printf(".");
            }
            for(int k=2*i+1;k>0;k--){
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}