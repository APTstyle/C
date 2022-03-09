#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int main()
{
    char p[100][100];
    int n,k,judge=0;
    int mal=0;
    while (1)
    {
        scanf("%d %d",&n,&k);
        char ram[100];
        memset (ram,'\0',sizeof(ram));
        int mirror=0;
        k=k+1;
        for(int i=n-1;i>-1;i--){
            int max = pow(2,i);
            if (max>=k && mirror == 0){
                strcat(ram, "0");  //將 s2 串接到 s1 後面
                mirror=0;
            }
            else if (max<k && mirror == 0){
                strcat(ram, "1");
                mirror=1;
                k = k-max;
            }
            else if (max>=k && mirror == 1){
                strcat(ram, "1");
                mirror=0;
            }
            else if (max<k && mirror == 1){
                strcat(ram, "0");
                mirror=1;
                k = k-max;
            }
        }
        //printf("ram=%s\n",ram);

        scanf("%d",&judge);
        strcpy(p[mal],ram);
        //printf("%s\n",ram);
        if (judge == -1){
            break;
        }
        //printf("%d\n",judge);
        mal =mal +1;
        

    }
    for (int i=0;i<mal+1;i++){
        printf("%s\n",p[i]);
    }
    return 0;
}