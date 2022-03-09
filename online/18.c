#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int CW(int sp[]) {
    int s[9];
    s[0]=sp[6];
    s[1]=sp[3];
    s[2]=sp[0];
    s[3]=sp[7];
    s[4]=sp[4];
    s[5]=sp[1];
    s[6]=sp[8];
    s[7]=sp[5];
    s[8]=sp[2];
    for(int i=0;i<9;i++) {
        sp[i]=s[i];
    }
    return 0;
}
int UW(int sp[]) {
    int s[9];
    s[0]=sp[2];
    s[1]=sp[5];
    s[2]=sp[8];
    s[3]=sp[1];
    s[4]=sp[4];
    s[5]=sp[7];
    s[6]=sp[0];
    s[7]=sp[3];
    s[8]=sp[6];
    for(int i=0;i<9;i++) {
        sp[i]=s[i];
    }
    return 0;
}
int main()
{
    int MB[6][9];
    for(int i=0;i<6;i++) {
        for(int j=0;j<9;j++) {
            MB[i][j]=i+1;
            //printf("%d",MB[i][j]);
            //printf(",");
        }
        //printf("\n");
    }
    int ram[3];
    int input[100];
    int mal;
    scanf("%d",&mal);
    getchar();
    for(int i=0;i<mal;i++) {
        scanf("%d",&input[i]);
        getchar();
        switch (input[i]) {
        case 10:
            //printf("10\n");
            for(int j=0;j<3;j++) {
                ram[j]=MB[0][3*j];
                MB[0][3*j]=MB[3][3*j];
                MB[3][3*j]=MB[5][3*j];
                MB[5][3*j]=MB[2][3*j];
                MB[2][3*j]=ram[j];
                
            }
            UW(MB[4]);
            break;
        case 11:
            for(int j=0;j<3;j++) {
                ram[j]=MB[0][3*j+1];
                MB[0][3*j+1]=MB[3][3*j+1];
                MB[3][3*j+1]=MB[5][3*j+1];
                MB[5][3*j+1]=MB[2][3*j+1];
                MB[2][3*j+1]=ram[j];
            }
            break;
        case 12:
            for(int j=0;j<3;j++) {
                ram[j]=MB[0][3*j+2];
                MB[0][3*j+2]=MB[3][3*j+2];
                MB[3][3*j+2]=MB[5][3*j+2];
                MB[5][3*j+2]=MB[2][3*j+2];
                MB[2][3*j+2]=ram[j];
                
            }
            CW(MB[1]);
            break;
        case 20:
            //printf("20\n");
            for(int j=0;j<3;j++) {
                ram[j]=MB[3][j];
                MB[3][j]=MB[1][j];
                MB[1][j]=MB[2][j];
                MB[2][j]=MB[4][j];
                MB[4][j]=ram[j];
                
            }
            CW(MB[0]);
            break;
        case 21:
            for(int j=0;j<3;j++) {
                ram[j]=MB[3][j+3];
                MB[3][j+3]=MB[1][j+3];
                MB[1][j+3]=MB[2][j+3];
                MB[2][j+3]=MB[4][j+3];
                MB[4][j+3]=ram[j];
            }
            break;
        case 22:
            for(int j=0;j<3;j++) {
                ram[j]=MB[3][j+6];
                MB[3][j+6]=MB[1][j+6];
                MB[1][j+6]=MB[2][j+6];
                MB[2][j+6]=MB[4][j+6];
                MB[4][j+6]=ram[j];
                
            }
            UW(MB[5]);
            break;
        default:
            break;
        }
    }
    //printf("%d",input[0]);
    for(int j=0;j<9;j++) {
        printf("%d",MB[0][j]);
        if((j%3)!=2) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
    return 0;
}