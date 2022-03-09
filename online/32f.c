#include<stdio.h>

int main(void){
    int n,left=0,right=0,a=0;
    int sttt[1000],ans[1000]={0};
    for(int i = 0 ; i<1000;i++)sttt[i]=-1;
    scanf("%d",&n);
    for(int i = 1 ;i<=n;i++){
        scanf("%d",&sttt[i]);
    }
    for(int i = 1;i<=n;i++){
        int l=i,r=i;
        if(i==1 || i == n){
            sttt[i]=1;
        }
        while(sttt[l]>=sttt[i] && sttt[r]>=sttt[i]){
            l--;
            r++;
        }
        if(sttt[l]<sttt[i]){
            ans[i]=i-l;
        }
        if(sttt[r]<sttt[i]){
            ans[i]=r-i;
        }


    }
    for(int i=0;i<1000;i++){
        a+=ans[i];
    }
    printf("%d",a);

}
