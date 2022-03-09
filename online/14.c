#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int game(char result[],int count,char answer[]){
    char input[10];
    int i,j;
    result[count]='0';
    result[count+1]='A';
    result[count+2]='0';
    result[count+3]='B';
    scanf("%c%c%c%c",&input[0],&input[1],&input[2],&input[3]);
    getchar( );
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            if (answer[i]==input[j]){
                if(i==j){
                    result[count]+=1;
                }
                else{
                    result[count+2]+=1;
                }
            }
        }
    }
    if (result[count]=='4'){
        result[count]='w';
        result[count+1]='i';
        result[count+2]='n';
    }
    //printf("A=%c",result[count]);
    return 0;
}
int main(){
    char result[100];
    char answer[10];
    int count=0;
    int i;
    scanf("%c%c%c%c",&answer[0],&answer[1],&answer[2],&answer[3]);
    /*for (i=0;i<4;i++){
        printf("%c",answer[i]);
    }*/
    getchar( );
    for(i=0;i<6;i++){
        game(result,count,answer);
        if (result[count]=='w'){
            break;
        }
        else count+=4;
    }
    for(i=0;i<24;i++){
        printf("%c",result[i]);
        if (i%4==3){
            printf("\n");
        }
        if(result[i]=='n'){
            break;
        }
    }
    return 0;
}