#include<stdio.h>
int a = 0;
int s[1000]; //�n�L�X���r��
int mm[1000]; //�����аO �P�_�o�}���S�����L�F
//int cave[1000][1000];
int nn[1000]={0};

typedef struct cave_t{
    int gald;
    int cave[2];
    int mark[2];
}cave;
typedef struct prin_t{
    int ss[1000];
    int v;
}prin;
int point=0;
prin p[1000];
cave c[1000];
int dfs(int step,int now,int ca,int money){
    int origin=now;

       if(step==ca || nn[now]==1){
        //point++;
        //printf("%d!",point);
        s[step]=now;
        if(a<=money){
            a=money;
            p[point].v=a;
        }
        for(int i = 0;i<ca*2;i++){
            p[point].ss[i]=s[i];
        }
        point++;
        s[step]=0;
        //printf("\n");

        return money;

    }
    else {
        for(int i = 0 ; i < 2 ;i++){
        //for(int k = 0;k<ca;k++)printf("%d",s[k]);
        //printf(" %d\n",step);
        if(c[now].mark[i]==0  && mm[now]==0){
            nn[now]=1;
            c[now].mark[i]=1;
            mm[now]=1;
            money+=c[now].gald;
            //printf("%d!\n",money);
            s[step]=now;
            now = c[now].cave[i];
            step++;
            dfs(step,now,ca,money);
            s[step]=0;
            step--;
            now=origin;
            nn[now]=0;
            mm[now]=0;
            c[now].mark[i]=0;
            money-=c[now].gald;
       // }
        }
        else if(c[now].mark[i]==1){
            c[now].mark[i]=1;
            //mm[now]=1;
            //printf("%d!\n",money);
            //money+=c[now].gald;
            s[step]=now;
            now = c[now].cave[i];
            step++;
            dfs(step,now,ca,money);
            s[step]=0;
            step--;
            now=origin;
            //mm[now]=0;
            c[now].mark[i]=0;
            //money-=c[now].gald;
        }

    }

}
}


int main(void){
    int n,m,emp;

    scanf("%d %d",&n,&m);
    for(int i = 0 ;i<1000;i++){
        for(int j = 0 ; j <2;j++){
            c[i].mark[j]=0;
        }
    }
    for(int i = 1 ; i<= n;i++){
        scanf("%d %d %d %d",&emp,&c[i].gald,&c[i].cave[0],&c[i].cave[1]);
    }

    dfs(0,m,n,0);
    //printf("%d?",point);

    /*for(int i = 0 ; i<point;i++){
        for(int j = 0 ; j <n;j++){
            printf("%d",p[i].ss[j]);
        }
        printf(" %d ",p[i].v);
        printf("\n");
    }*/
    int test[1000]={0};
    for(int i = 0 ; i<point;i++){
         int check=0;
        for(int k = 0 ; k<n*2;k++){
            if(p[i].ss[k]!=test[k])check=1;
        }


        if(p[i].v==a && check==1){
        for(int j = 0 ; j <n*2;j++){
            test[j]=p[i].ss[j];
            if(p[i].ss[j]!=0){
            if(j==0)printf("%d",p[i].ss[j]);
            else printf(" %d",p[i].ss[j]);
            }
        }
        printf("\n");
        }
    }




printf("%d",a);



}
