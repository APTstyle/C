#include<stdio.h>
#define max 1100

int list[max][max];

void put(int k ,int data){
    int i = 0 ;
    while(1){
        if(list[k][i]==0){
            list[k][i]=data;
            break;
        }
        i++;
    }
}

int main(void){

    int dot[max]={0},total[max]={0},ru[max]={0};
    int time,pn,con,t,w,check=0,ans,wait;
    scanf("%d",&time);
    for(int i = 1 ; i<=time;i++){
        scanf("%d",&pn);
        for(int k = 1 ; k<=pn;k++){
            scanf("%d %d",&w,&t);
            dot[k]=w;
            total[k]=w;
            if(t==0) wait=w;
            for(int j = 1 ; j <= t;j++){
                scanf(" %d",&con);
                ru[con]+=1;
                //printf("%d?",ru[con]);
                put(k,con);
            }
        }
        //for(int i = 0 ; i < pn;i++){
        //    printf("%d",ru[i]);
        //}


        while(1){
        check=0;
        for(int k=1;k<=pn;k++){
            if(ru[k]==0){
                int p=0;
                while((list[k][p])!=0){
                    //printf("%dyo!",k);
                    //printf("%d?\n",total[list[k][p]] );
                    t= total[k]+dot[list[k][p]];
                    if(t>total[list[k][p]]){
                    total[list[k][p]] =  t;
                    }
                    ru[list[k][p]]--;

                    p++;
                }
                ru[k]=-1;
            }

        }
        //printf("bitchh");
        for(int i = 1 ; i <=pn;i++){
            if(ru[i]>0){
                check = 1;
                break;
            }
        }
        if(check==0)break;
    }



   /* for(int i = 0 ; i<5 ; i++){
            printf("\n");
        for(int j = 0; j <max;j++){
            printf("%d",list[i][j]);
        }
    }*/
    ans = total[0];
    for(int i = 1 ; i <= pn;i++){
        //printf("%d!\n",total[i]);
        if(total[i]>ans){
            ans=total[i];
        }
    }
    printf("%d\n",ans);



    ans=0;
    wait=0;
    for(int i= 0 ; i<max;i++){
        dot[i]=0;
        total[i]=0;
        ru[i]=0;
        t=0;
        pn=0;
        check=0;
        w=0;
        for(int j =0 ; j<max;j++){
            list[i][j]=0;
        }
    }



    }


}

