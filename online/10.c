#include<stdio.h>
#include<math.h>
#include <string.h>

int c(int a,int count){
    if(a==1 || a==0){
        count+=1;
        return count-1;
    }
    else if (a%2==0){
        count+=1;
        c(a/2,count);
    }
    else if (a%2==1){
        count+=1;
        c((a+1)/2,count);
    }
}
int f(int a,int *ch){
    if (a>=8){
        *ch=1;
        a-=8;
    }
    else{
        *(ch)=0;
    }
    if (a>=4){
        *(ch+1)=1;
        a-=4;
    }
    else{
        *(ch+1)=0;
    }
    if (a>=2){
        *(ch+2)=1;
        a-=2;
    }
    else{
        *(ch+2)=0;
    }
    if (a>=1){
        *(ch+3)=1;
        a-=1;
    }
    else{
        *(ch+3)=0;
    }

}

int main(void){

    int m =0,co=0,ans,pp[4],what=0;
    char arr[9],all[20][5],pu[5];    
    while(what==0){
    scanf("%s",arr);


    for(int a = 7 ; a>=0;a--){
        if(arr[a]=='1'){
            m+=pow(2,(7-a));
        }
    }
    ans = c(m,0);
    f(ans,&pp);
    for(int i =0;i<4;i++){
        pu[i]=pp[i]+'0';
    }
    strcpy(all[co],pu);

    m=0;
    co+=1;
    for(int i =0;i<4;i++){
        pp[i]=0;
    }

    scanf("%d",&what);
    if(what!=0){
        break;
    }
}

    /*for(int i =0;i<8;i++){
        printf("%c",arr[i]);
    }*/

    for(int i =0;i<co;i++){
        printf("%s",all[i]);
        printf("\n");
    }

    //printf("\n%d %d",m,ans);


}
