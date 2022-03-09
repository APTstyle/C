#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int main()
{
    char in[100];
    scanf("%[^\n]",in);
    getchar();
    char datain[2][10];
    int abc=0;
    int ab=0;
    int n;
    int m;
    for(int i=0;i<100;i++) {
        if(((in[i]-'0')>-1)&&((in[i]-'0')<10)){
            datain[ab][abc++]=in[i]-'0';
        }
        else if(in[i]==' ') {
            ab++;
            if(abc==1){
                n=datain[0][0];
            }
            else if(abc==2) {
                n=datain[0][0]*10+datain[0][1];
            }
            else if(abc==3) {
                n=datain[0][0]*100+datain[0][1]*10+datain[0][2];
            }
            abc=0;
        }
    }
    if(abc==1){
                m=datain[1][0];
            }
            else if(abc==2) {
                m=datain[1][0]*10+datain[1][1];
            }
            else if(abc==3) {
                m=datain[1][0]*100+datain[1][1]*10+datain[1][2];
            }
    //printf("%d %d",n,m);
    int data[100]={0};
    //printf("%d",data[99]);
    for(int i=0;i<n;i++) {
        data[i]=1;
    }
    char out[100000];
    if (m!=0) {
        scanf("%[^\n]",out);
        getchar();
    }
    int number[4];
    int c=0;
    int ram=0;
    for(int i=0;i<100000;i++) {
        if(out[i]==' ') {
            if(c==1){
                ram=number[0];
                data[number[0]-1]=2;
            }
            else if(c==2) {
                ram=number[0]*10+number[1];
                data[ram-1]=2;
            }
            else if(c==3) {
                ram=number[0]*100+number[1]*10+number[2];
                data[ram-1]=2;
            }
            else if(c==4) {
                ram=number[0]*1000+number[1]*100+number[2]*10+number[3];
                data[ram-1]=2;
            }
            //printf("%d\n",ram);
            c=0;
            ram=0;
            continue;
        }
        else if (((out[i]-'0')>-1)&&((out[i]-'0')<10)) {
            number[c++]=(out[i]-'0');
            //printf("%d",number[c-1]);
            continue;
        }
        else {
            if(c==1){
                    ram=number[0];
                    data[number[0]-1]=2;
                }
            else if(c==2) {
                    ram=number[0]*10+number[1];
                    data[ram-1]=2;
                }
            else if(c==3) {
                    ram=number[0]*100+number[1]*10+number[2];
                    data[ram-1]=2;
                }
            else if(c==4) {
                ram=number[0]*1000+number[1]*100+number[2]*10+number[3];
                data[ram-1]=2;
            }
            //printf("%d\n",ram);
            c=0;
            ram=0;
        }
        break;
    }
    int max=0;
    int r=0;
    int bk=0;
    if(data[0]==1) {
        r+=1;
        int nn=n;
        while(1) {
            if(data[--nn]==1) {
                r+=1;
            }
            else {
                break;
            }
            if(r==n) {
                max=r;
                bk=1;
                break;
            }
        }
    }
    if(bk==0)
    {    
        for(int i=1;i<n;i++) {
            //printf("data[%d]=%d\n",i,data[i]);
            if(data[i]==1) {
                    r+=1;
                }
            else {
                if(r>max) {
                    max=r;
                    r=0;
                }
                else {
                    r=0;
                }
            }
            if(i==n-1) {
               if(r>max) {
                    max=r;
                    r=0;
                } 
            }
        }
    }
    printf("%d",max);
    return 0;
}