#include <stdio.h>
void chn4(int p){
    int arrrrrr[4] = {0,0,0,0};
    if (p >= 8){
        arrrrrr[0] = 1;
        p -= 8;
    }
    if (p >= 4){
        arrrrrr[1] = 1;
        p -= 4;
    }
    if (p >= 2){
        arrrrrr[2] = 1;
        p -= 2;
    }
    if (p == 1){
        arrrrrr[3] = 1;
    }
    for (int i = 0;i < 4;i++){
        printf("%d",arrrrrr[i]);
    }
}
int c(int m,int cou){
    if (m == 0 || m == 1){
        chn4(cou);
        return m;
    }
    else if (m % 2 == 0){
        return c(m/2,cou+1);
    }
    else if (m % 2 == 1){
        return c((m+1)/2,cou+1);
    }
}
int chn8(char j[]){
    int a = 0;
    int an;
    for (int i = 0 ;i < 8;i++){
        an = j[i] - 48;
        a += an*(1<<(7-i));
    }
    return a;
}
int main(void)
{
    char a[9];
    int arrrrrr[50];
    int abc = 0;
    int coufin = 0;
    while (abc == 0){
        scanf("%s",a);
        arrrrrr[coufin] = chn8(a);
        coufin++;
        scanf("%d",&abc);
    }
    for (int j = 0;j < coufin;j++){
        c(arrrrrr[j],0);
        printf("\n");
    }
    return 0;
}