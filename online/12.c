#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int aa(char ans[],int count){
    int a=0,b=0,c=0,d=0,j=0,ram;
    char e;
    scanf("%d/%d",&a,&b);
    getchar( );
    scanf("%d/%d",&c,&d);
    getchar( );
    //printf("%d %d %d %d %c\n",a,b,c,d,e);
    scanf("%c",&e);
    getchar( );
    if (b==0 || d==0){
        ans[count]='*';
        ans[count+1]=0;
        ans[count+2]=0;
        return 0;
    }
    a *= d; c *= b; b *= d; d = b;
    //printf("%d %d %d %d\n",a,b,c,d);
    int num=0;
    int mol,com;
    if (e=='+'){
         mol = a + c;
         com = d;
    }
    else if (e=='-'){
         mol = a - c; com = d; 
    }
    else if (e=='*'){
         mol = a * c; com = d*b; 
    }
    else if (e=='/'){
         mol = a; com = c; 
    }
    //printf("%d %d\n",mol,com);
    ram = mol;
    while(1){
        j=0;

        for (int i=2;i<abs(mol);i++){
            if (com%i==0 && ram%i==0){
                com/=i; ram/=i;
                j=1;
                break;
            }
            //printf("com=%d ram=%d\n",com,ram);
        }
        //printf("%d\n",j);
        if(j==0){
            mol =ram;
            break;
        }
    }
    while(1){
        if (abs(mol)>com){
            if (mol<0)
            {
                mol+=com;
                num++;
            }
            else{
                mol-=com;
                num++;
            }
        }
        else break;
    }
    if (mol/com==1){
        num+=1;
        mol=0;
    }
    else if(mol/com==-1){
        num = 0 -num -1;
        mol=0;
    }
    if (mol>0 && com <0 && num==0){
        mol = 0-mol;
        com = 0-com;
    }
    else if (mol>0 && com <0 && num!=0){
        num = 0 -num;
        com = 0 -com;
    }
    ans[count]=num;
    ans[count+1]=mol;
    ans[count+2]=com;
    //printf("%d/%d",ans[count+1],ans[count+2]);
    return 0;
}
int main(){
    char result[100]={0};
    int count=0;
    while(1){
        aa(result,count);
        char k;
        scanf("%c",&k);
        getchar( );
        if (k=='n'){
            count+=3;
            break;
        }
        count+=3;
    }
    for(int i=0;i<100;i+=3){
        if (result[i]==0 && result[i+1]==0 && result[i+2]==0){
            break;
        }
        else if (result[i]=='*'){
            printf("ERROR\n");
        }
        else if (result[i]==0 && result[i+1]!=0 && result[i+2]!=0){
            printf("%d/%d\n",result[i+1],result[i+2]);
        }
        else if (result[i]!=0 && result[i+1]==0 ){
            printf("%d\n",result[i]);
        }
        else if (result[i]==0 && result[i+1]==0 && result[i+2]!=0){
            printf("0\n");
        }
        else if (result[i]!=0){
            printf("%d(%d/%d)\n",result[i],result[i+1],result[i+2]);
        }
    }
}