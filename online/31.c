#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int next(int size,int pivot, int perm[], int possible[50000][10]) {
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
    char data[100][100];
    int numberlist[100][10];
    int mal;
    int possible[50000][10];
    int min=99999999;
    int size,perm[30]={0};
    int count;
    scanf("%d",&mal);
    getchar();
    size=mal-1;
    count = next(size,0,perm,possible);
    for(int i=0;i<mal+1;i++) {
        scanf("%[^\n]",data[i]);
        getchar();
        for(int j=0;j<(mal*2)+1;j+=2) {
            numberlist[i][j/2]=data[i][j]-'0';
        }
    }
    int x1=0,y1=0;
    for(int i=2;i<mal+1;i++) {
        for(int j=2;j<mal+1;j++) {
            possible[x1][y1];
        }
    }
    int ram;
    for(int i=0;i<count;i++) {
        ram=0;
        ram+=numberlist[1][possible[i][0]];
        for(int j=0;j<size-1;j++) {
            ram+=numberlist[possible[i][j]][possible[i][j+1]];
        }
        if (ram<min) {
            min = ram ;
        }
    }
    printf("%d",min);
    return 0;
}