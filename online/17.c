#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int point(char a1[],int length1,int i1,int count1,int Lx,int Ly,int pt[100][100],int *local) {
    int L1=0,L2=0;
    *local+=1;
    count1+=1;
    //printf("all=%s\n",a1);
    for(int j=0;j<4;j++) {
        L1=((j-*local)/2)*length1/pow(2,count1);
        L2=((j-*local)%2)*length1/pow(2,count1);
        int Rx =L1+Lx;
        int Ry =L2+Ly;
        printf("a1[%d]=%c,count=%d,i1=%d,(x,y)=(%d,%d),(x,y)=(%d,%d)\n",j,a1[j],count1,*local,Lx,Ly,Rx,Ry);
        switch (a1[*local]) {
            case '2':
                //printf("%d\n",pow(2,count1));
                //j+=1;
                point(a1,length1,j,count1,Rx,Ry,pt,local);
                //i1+=4;
                //j+=3;
                break;
            case '1':
                //printf("%d,%d\n",(j-i1)%2,(j-i1)/2);
                //printf("%d,%d\n",length1,pow(2,count1));
                //printf("%d",length1/pow(2,count1));
                for(int m=0;m<length1/pow(2,count1);m++) {
                    for(int n=0;n<length1/pow(2,count1);n++) {
                        //int aa=pow(2,count1);
                        ////printf("%d,%d\n",Lx+L1+m,Ly+L2+n);
                        pt[Lx+L1+m][Ly+L2+n]=1;
                    }
                }
                break;
        }  
    }
    return 0;
}
int main() {
    int i,j,k;
    int limit=1;
    int length;
    char a[500]={'0'};
    int pt[100][100]={{0}};
    int *local;
    *local=1;
    scanf("%s",&a);
    scanf("%d",&length);
    //printf("%s",a);
    //printf("\n%d",length);
    int count=0;
    for(i=0;i<1;i++){
        switch (a[0])
        {
        case '2':
            //limit*=4;
            i+=1;
            point(a,length,i,count,0,0,pt,local);
            break;
        case '1':
            for(int m=0;m<length;m++){
                for(int n=0;n<length;n++){
                    printf("%d,%d\n",m,n);
                }
            }
            break;
        case '0':
        printf("all white");
            break; 
        }
    }
    int AW=0;
    for(i=0;i<limit;i++) {
        if(a[i]=='2') {
            limit+=4;
        }
        else if(a[i]=='1') {
            AW+=1;
        }
    }
    if(AW==0&&a[0]!='0') {
        printf("all white");
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(pt[i][j]==1){
                printf("%d,%d\n",i,j);
            }
        }
    }
    return 0;
}