#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int next(int size,int pivot, int perm[], int possible[50000][10]) { //排列組合
    int i,collision;
    static int count=0;
    perm[pivot] = 0;

    while(perm[pivot]++ < size) {
        collision = 0;
        for (i=0;i<pivot;i++) {
            if (perm[pivot] == perm[i]) {
                collision=1;
                break;
            }
        }
        if (!collision) {
            if(pivot+1 <size) {
                next(size,pivot+1,perm,possible);
            }
            else {
                for(i=0;i<size;i++) {
                    possible[count][i]=perm[i]+1;
                }
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int size;
    scanf("%d",&size);
    getchar();
    char datalist[100][100];
    int numberlist[100][100];
    int possible[50000][10];
    int perm[12]={0};
    int max=0;
    int min=9999;
    int maxroute[100][10]={0};
    int minroute[100][10]={0};
    int mx=0;
    int mn=0;
    for (int i=0;i<size+1;i++) { //輸入
        scanf("%[^\n]",datalist[i]);
        getchar();
    }
    int aaa=0;
    for(int i=0;i<size+1;i++) { //分空輸入
        aaa=0;
        for(int j=0;j<2*size+1;j+=2) {
            numberlist[i][aaa++]=datalist[i][j]-'0';
        }
    }
    int count;
    count=next(size-1,0,perm,possible);
    int ram;
    for(int i=0;i<count;i++) { //計算該種可能性的數值
        ram=numberlist[1][possible[i][0]];
        for(int j=1;j<size-1;j++) {
            ram+=numberlist[possible[i][j-1]][possible[i][j]];
        }
        if(ram>max) { //判斷是否為最大
            max=ram; //如果有變更 把maxroute內的路徑清除
            for(int m=0;m<mx;m++) {
                for(int n=0;n<100;n++) {
                    maxroute[m][n]=0;
                }
                
            }
            mx=0;
        }
        if(ram<min) { //判斷是否為最小
            min=ram; //如果有變更 把minroute內的路徑清除
            for(int m=0;m<mn;m++) {
                for(int n=0;n<100;n++) {
                    minroute[m][n]=0;
                }
            }
            mn=0;
        }
        if(ram==max){ //如果同樣為最大 路徑輸入進maxroute
            for(int m=0;m<size;m++) {
                maxroute[mx][m]=possible[i][m];
            }
            mx++;
        }
        if(ram==min){ //如果同樣為最小 路徑輸入進minroute
            for(int m=0;m<size;m++) {
                minroute[mn][m]=possible[i][m];
            }
            mn++;
        }
    }
    printf("%d\n",min); //輸出
    for(int i=0;i<mn;i++) {
        printf("1"); //第一個城市
        for(int j=0;j<size-1;j++) { //依序輸出下個城市
            printf("->"); 
            printf("%d",minroute[i][j]); 
        }
        printf("\n"); //換行
    }
    printf("%d\n",max);
    for(int i=0;i<mx;i++) {
        printf("1");
        for(int j=0;j<size-1;j++) {
            printf("->");
            printf("%d",maxroute[i][j]);
        }
        printf("\n");
    }
    return 0;
}