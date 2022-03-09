#include<stdio.h>
#include<stdbool.h>

int main(void){
    char answer[2000];
    char number[15];
    int turn[2000];
    int i = 0,j=0 ,a=0,l=0;
    bool test=true;
    for(int j = 0 ; j <2001;j++){
        answer[j]='a';
    }
    scanf("%s",answer);
    scanf("%d",&l);
    for(int k = 0 ; k<2001;k++){
        turn[k]=answer[k]-'0';
    }
    //for(int j = 0 ; j <200;j++){
 //       printf("%c",answer[j]);
//}

    for(int x=0;x<10;x++){
        number[x]='0';
       // printf("%c\n",number[x]);
    }

    while(answer[i]!='a'){
       // printf("test");
        for(int z=i;z<i+l;z++){
              //  printf("%c %c \n",number[answer[z]);
                if(number[turn[z]]=='0'){
                    number[turn[z]]='1';
                }
                else{

                    test=false;
                    break;
                }

        }

        for(int x=0;x<10;x++){
            number[x]='0';
        }

        if (test==true){
            a+=1;
        }
        test=true;

        i+=1;
        //printf("%d\n",a);

    }
   printf("%d",a);

}
