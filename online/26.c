#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
/*int num(int a,int b,int c,int* n,int list[100],int datalist[100][100]) {
    //list[count]+=a;
    if(b==0) {
        return a;
    }
    if(b>1){
        for(int j=0;j<b;j++) {
            &n+=1;
            list[n]=a+num(datalist[c][0],datalist[c][1],datalist[c][2],count+j,list,datalist);
        }
    }
    
    return 0;
}*/
int main()
{
    int pt[100];
    int cn;
    scanf("%d",&cn);
    getchar();
    for(int i=0;i<cn;i++){
        int sn;
        scanf("%d",&sn);
        getchar();
        int datalist[100][100];
        for(int j=0;j<sn;j++) {
            char ram[100];
            scanf("%[^\n]",ram);
            getchar();
            //printf("%s\n",ram);
            //printf("%d\n",ram[2]-'0');
            //printf("%d\n",(ram[0]-'0')+3);
            int count=0;
            for(int m=0 ; m < 2*(ram[2]-'0')+3;m++) {
                if(ram[m]!=' ') {
                    //printf("*");
                    datalist[j][count]=ram[m]-'0';
                    count++;
                }
                //printf("datalist[%d][%d]=%c\n",j,m,datalist[j][m]);
            }
        }
        int list[100]={0};
        int* n;
        &n=0;
        /*list[0]=datalist[0][0]-'0';*/
        //list[0]=num(datalist[0][0],datalist[0][1],datalist[0][2],n,list,datalist);
        list[0]=datalist[0][0];
        for(int m=0;m<100;m++){
            for(int j=0;j<datalist[0][1];j++) {
                list[0+j]=list[0]+datalist[datalist[0][2+j]][0];
            }
        }
        for(int j=0;j<10;j++) {
            printf("list[%d]=%d\n",j,list[j]);
        }
    }
    

    return 0;
}