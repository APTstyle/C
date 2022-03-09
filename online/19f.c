#include<stdio.h>

int n1(int x[]){
    int mitte,up,down,left,right,back;
    mitte=x[1];
    up=x[5];
    down=x[0];
    left=x[3];
    right=x[4];
    back=x[2];
    x[0]=mitte;
    x[1]=up;
    x[2]=down;
    x[3]=left;
    x[4]=right;
    x[5]=back;
}
int n2(int x[]){
    int mitte,up,down,left,right,back;
    mitte=x[2];
    up=x[0];
    down=x[5];
    left=x[3];
    right=x[4];
    back=x[1];
    x[0]=mitte;
    x[1]=up;
    x[2]=down;
    x[3]=left;
    x[4]=right;
    x[5]=back;
}
int n3(int x[]){
    int mitte,up,down,left,right,back;
    mitte=x[3];
    up=x[1];
    down=x[2];
    left=x[5];
    right=x[0];
    back=x[4];
    x[0]=mitte;
    x[1]=up;
    x[2]=down;
    x[3]=left;
    x[4]=right;
    x[5]=back;
}
int n4(int x[]){
    int mitte,up,down,left,right,back;
    mitte=x[4];
    up=x[1];
    down=x[2];
    left=x[0];
    right=x[5];
    back=x[3];
    x[0]=mitte;
    x[1]=up;
    x[2]=down;
    x[3]=left;
    x[4]=right;
    x[5]=back;
}


int main(void){
    int a[6]={1,3,4,5,2,6}; //mitte,up,down,left,right,back
    int b[6]={1,3,4,5,2,6};
    int c[6]={1,3,4,5,2,6};
    int d[6]={1,3,4,5,2,6};
    int num[7]={0,0,0,0,0,0,0};
    int n,ans=0;
    char t1,t2,t3,t4;
    scanf("%d",&n);
    for(int i=0 ; i<n;i++){
        scanf(" %c %c %c %c",&t1,&t2,&t3,&t4);
        if(t1=='1'){
            n1(a);
        }
        else if(t1=='2'){
            n2(a);
        }
        else if(t1=='3'){
            n3(a);
        }
        else if(t1=='4'){
            n4(a);
        }
        if(t2=='1'){
            n1(b);
        }
        else if(t2=='2'){
            n2(b);
        }
        else if(t2=='3'){
            n3(b);
        }
        else if(t2=='4'){
            n4(b);
        }
        if(t3=='1'){
            n1(c);
        }
        else if(t3=='2'){
            n2(c);
        }
        else if(t3=='3'){
            n3(c);
        }
        else if(t3=='4'){
            n4(c);
        }
        if(t4=='1'){
            n1(d);
        }
        else if(t4=='2'){
            n2(d);
        }
        else if(t4=='3'){
            n3(d);
        }
        else if(t4=='4'){
            n4(d);
        }

    }
   /* printf("%d\n",a[0]);
    printf("%d\n",b[0]);
    printf("%d\n",c[0]);
    printf("%d\n",d[0]);*/
    num[a[0]-1]+=1;
    num[b[0]-1]+=1;
    num[c[0]-1]+=1;
    num[d[0]-1]+=1;
    /*for(int i = 0 ;i<6;i++){
        printf("%d\n",num[i]);
    }*/
    for(int i = 0 ; i<6;i++){
        if(num[i]==4){
            ans=18;
        }
        else if(num[i]==3){
            ans=0;
        }
        else if(num[i]==2){
            num[i]-=2;
            for(int j = 0 ; j<6;j++){
                if(num[j]==2) {
                    ans+=j*2+2;
                    //printf("%d\n",j);
                }
                else if(num[j]==1){
                        ans+=j+1;
                       // printf("%d\n",j);
                }
            }
        }

    }
    printf("%d",ans);

}
