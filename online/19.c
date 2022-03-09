#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
void spin(int dice[],int input) {
    int ram;
    switch (input)
    {
    case 2:
        ram=dice[0];
        dice[0]=dice[3];
        dice[3]=dice[5];
        dice[5]=dice[2];
        dice[2]=ram;
        break;
    case 1:
        ram=dice[0];
        dice[0]=dice[2];
        dice[2]=dice[5];
        dice[5]=dice[3];
        dice[3]=ram;
        break;
    case 3:
        ram=dice[0];
        dice[0]=dice[4];
        dice[4]=dice[5];
        dice[5]=dice[1];
        dice[1]=ram;
        break;
    case 4:
        ram=dice[0];
        dice[0]=dice[1];
        dice[1]=dice[5];
        dice[5]=dice[4];
        dice[4]=ram;
        break;
    }
}
int point(int count[]) {
    int ram = count[0];
    for (int i=1;i<4;i++) {
        if (ram==count[i]){
            if(i==3) {
                printf("18");
                return 0;
            }
        }
        else {
            break;
        }
    }
    if(count[0]==count[1]&&count[2]==count[3]) {
        printf("%d",count[2]*2);
        return 0;
    }
    if(count[0]==count[1]&&count[1]==count[2]) {
        printf("0");
        return 0;
    }
    if(count[2]==count[1]&&count[3]==count[2]) {
        printf("0");
        return 0;
    }
    if(count[0]==count[1]) {
        printf("%d",count[2]+count[3]);
        return 0;
    }
    if(count[2]==count[3]) {
        printf("%d",count[0]+count[1]);
        return 0;
    }
    if(count[1]==count[2]) {
        printf("%d",count[0]+count[3]);
        return 0;
    }
    printf("0");
    return 0;
}
int main() {
    int dice[4][6];
    for(int i=0;i<4;i++) {
        for( int j=0;j<6;j++) {
            dice[i][j]=j+1;
            //printf("dice[%d][%d]=%d\n",i,j,j+1);
        }
    }
    int mal;
    int input[4];
    scanf("%d",&mal);
    for(int i=0;i<mal;i++) {
        scanf("%d %d %d %d",&input[0],&input[1],&input[2],&input[3]);
        for(int i=0;i<4;i++) {
            spin(dice[i],input[i]);
        }
    }
    int count[4];
    for(int i=0;i<4;i++) {
        count[i]=dice[i][0];
    }
    for(int i=0;i<4;i++) {
        for(int j=i+1;j<4;j++) {
            if(count[i]>count[j]) {
                int ram1 = count[i];
                count[i]=count[j];
                count[j]=ram1;
            }
        }
    }
    point(count);
    /*printf("\n");
    for(int i=0;i<4;i++) {
        printf("%d",count[i]);}*/
    return 0;
}