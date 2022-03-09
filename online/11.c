#include<stdio.h>
#include<math.h>
#include <string.h>



int main(void){
    int where[258],a=0,m=0,ans=0,co=0,sum[258],mal=0;
    char arr[9],fin[20][12],pu[12];
    for(int i = 0 ; i <256;i++ ){
        if((1 << a) >= i) where[i] = a;
        else where[i] = ++a;
    }
    for(int i = 0 ; i <=256;i++ ){
        if(i==0){
            sum[i]=0;
        }
        else{
            sum[i]=sum[i-1]+where[i];
        }
    }
while(mal==0){        ////////////////
    scanf("%s",arr);

    for(int a = 7 ; a>=0;a--){
        if(arr[a]=='1'){
            m+=pow(2,(7-a));
        }
    }
    m=sum[m];
   // printf("%d",m);
    for(int i = 10 ;i>=0;i--){
        if(m>=(1<<i)){
            m-=1<<i;
            pu[10-i]='1';
    }
        else{
            pu[10-i]='0';
        }
    }
    printf("%.11s",pu);
  //  printf("\n");
    /*for(int i =0;i<12;i++){
        fin[co][i]=pu[i];
    }*/
    //strcpy(fin[co],pu);

    m=0;
    co+=1;
    for(int i = 0;i<12;i++){
        pu[i]='0';
    }


    scanf("%d",&mal);
    if(mal!=0){
        break;
    }
} /////////////////////

  /*  for(int i = 0 ; i <co;i++){
        printf("%.11s",fin[i]);
        printf("\n");
    }
*/



}
