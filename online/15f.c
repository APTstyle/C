#include <stdio.h>
#include <string.h>
#define MAX 200

int www(int a){
	a++;
}

void rev(int* gross, char* str){//反轉陣列
    int i=0, len=strlen(str);
    for (int j=0;j<MAX;j++) gross[j]=0;
    for(i=len-1; i>=0; --i)
        gross[len - i - 1] = str[i] - '0';
}
void sub(int* ans,int* x,int* y){//減法
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

int main(void){
    int choose,x[MAX],y[MAX],ans[MAX];
    char c_x[MAX],c_y[MAX];
    scanf("%d",&choose);
    scanf("%s",&c_x);
    scanf("%s",&c_y);
    for (int j=0;j<MAX;j++) ans[j]=0;
    rev(x,c_x);
    rev(y,c_y);

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
        if (x[a] > y[a]) sub(ans,x,y);
        else if (x[a] < y[a]){
            printf("-");//負號
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
