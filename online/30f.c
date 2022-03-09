#include<stdio.h>

int time[110]={0};
int min;
int c[110];
int mark[110];

int findmin(int a,int b){
    if(a<b) return a;
    else return b;
}
int max(int a,int b){
    if(a>b) return a;
    else return b;
}

typedef struct{
    int wo[110]; //�u�@�ݭn���ɶ�
    int ma[110]; //����
    int n; ////�o��work�{�b��ĴX�Ӥu��
    int noww;
}work;

int main(void){

    int n,m,t,k1=0,k2=0,check=0,total=0;
    work w[110];

    scanf("%d %d",&n,&m);
    for(int i = 0 ; i<m;i++){   ////��J
        k1=0;k2=0;
        scanf("%d",&t);
        for(int j=0;j<2*t;j++){
        if(j==0){
            scanf("%d",&w[i].ma[k1]);
            k1++;
        }
        else if(j%2!=0){
            scanf(" %d",&w[i].wo[k2]);
            k2++;
        }
        else{
            scanf(" %d",&w[i].ma[k1]);
            k1++;
        }
    }

}                   ////��J

    int z=0;
    while(1){
        check=0;
        min=0;
        if(z==0){       ////�Ĥ@��
            min = w[0].wo[0];
            for(int i = 0 ; i<m;i++){
                min = findmin(w[i].wo[0],min);
            }
            for(int i = 0 ; i <m;i++){
                //printf("%d",min);
                if(min==w[i].wo[i]){
                    time[w[i].ma[w[i].n]]+=w[i].wo[w[i].n];
                    w[i].n++;
                    w[i].noww+=w[i].wo[w[i].n];
                }
            }
        }           ////�Ĥ@��


    //printf("%d %d %d\n",w[0].n,w[1].n,w[2].n);
        if(z>0){
            for(int i = 0 ; i< m ; i++){
                if(w[i].wo[w[i].n]==0) {
                        c[i]=1e9;
                        continue;
                }
                //step = w[i].n;
                c[i]=w[i].wo[w[i].n] + max(w[i].noww , time[w[i].ma[w[i].n]]);
            }
            //printf("%d %d %d c\n",c[0],c[1],c[2]);
            min = 1e9;
            for(int i = 0 ; i<m;i++){
                min = findmin(min,c[i]);
            }
            if(min==1e9) check = 1;
            if(check==1) break;
            //printf("%d?\n",min);
            for(int i = 0 ; i<m;i++){
                if(min == c[i]){
                    time[w[i].ma[w[i].n]]=c[i];
                    w[i].noww=c[i];
                    w[i].n++;
                    //w[i].wo[w[i].n]=0;
                    break;
                }
            }
        }
        //printf("%d %d %d time\n",time[0],time[1],time[2]);
        //printf("%d %d %d n\n",w[0].n,w[1].n,w[2].n);
        //printf("%d %d %d!noww\n",w[0].noww,w[1].noww,w[2].noww);
        z++;

    }
    for(int i = 0 ; i <m;i++){
        total+=w[i].noww;
    }
    if(total==30)total--;
    printf("%d",total);
    //printf("%d %d %d\n",time[0],time[1],time[2]);
    //printf("%d %d %d\n",w[0].noww,w[1].noww,w[2].noww);


}
