#include <stdio.h>
#include <string.h>
#define MAX 200

void rev(int* gross, char* str){//����}�C
    int i=0, len=strlen(str);
    for (int j=0;j<MAX;j++) gross[j]=0;
    for(i=len-1; i>=0; --i)
        if(str[i]=='-')continue;
        else gross[len - i - 1] = str[i] - '0';
}
void sub(int* ans,int* x,int* y){//��k
    int borrow=0;
            for(int i=0; i<MAX; i++) {
                ans[i] = x[i]-y[i]-borrow;
                if(ans[i]<0) {
                    borrow=1, ans[i]+=10;
                } else {
                    borrow=0;
                }
            }
}

/*int ww(int a){
    a+=1;
    return 0;
}*/

int main(void){
    int choose,x[MAX],y[MAX],ans[MAX],ch1=0,ch2=0,p1=0,p2=0;
    char c_x[MAX],c_y[MAX];
    scanf("%d",&choose);
    scanf("%s",&c_x);
    scanf("%s",&c_y);
    if(c_x[0]=='-') {ch1=1;}
    if(c_y[0]=='-') {ch2=1;}
    for (int j=0;j<MAX;j++) ans[j]=0;
    rev(x,c_x);
    rev(y,c_y);
    //for(int i = 0 ; i<MAX;i++){
    //    printf("%d",x[i]);
    //}
    //printf("%d %d %d",choose,ch1,ch2 );
    if(choose ==1 && (ch1==1 && ch2==1)){
        printf("-");
    }
    else if(choose == 1 &&(ch1==1 && ch2==0)){
        p1=1;
        choose = 2;
    }
    else if(choose == 1 &&(ch1==0&&ch2==1)){
        choose = 2 ;
    }
    else if (choose ==2 && ch1==1&&ch2==1){/////!!
        p1=1;
    }
    else if(choose==2 && ch1==1 &&ch2==0){
        printf("-");
        choose =1;
    }
    else if(choose==2 && ch1==0 &&ch2==1){
        choose=1;
    }
    else if(choose==3 && (ch1==1 && ch2==0)||(ch1==0&&ch2==1)){
        printf("-");
    }


    if (choose == 1){
        int carry = 0;
        for (int i=0;i<200;i++){
            ans[i] = x[i] + y[i] + carry;
            if (ans[i]>9){
                carry = ans[i]/10;
                ans[i]%=10;
            }
            else carry = 0;
        }
    }


    else if (choose == 2){
        int a=MAX-1;
        while(a>0 && x[a] == y[a]) a--;
        if (x[a] > y[a]) {
            if(p1==1)printf("-");
            sub(ans,x,y);}
        else if (x[a] < y[a]){
            if(p1!=1){printf("-");}//�t��
            sub(ans,y,x);
        }
    }


    else if (choose == 3){
        int c=0;
        for(int i=0; i<MAX; i++) {
            if(x[i]==0) continue;
            for(int j=0; i+j<MAX; j++)
                ans[i+j]+= x[i]*y[j];
        }

        for(int i=0; i<MAX; i++) {
            ans[i]+=c;
            c = ans[i] / 10;
            ans[i] %= 10;
        }
    }

    int b=MAX-1;
    for(b=MAX-1;b>=0 && ans[b]==0; b--);
    while(b>=0) printf("%d", ans[b]), b--;
}
