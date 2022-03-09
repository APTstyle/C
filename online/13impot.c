#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int common(char M[],int n1,int n2,int* p){
    if (n1<0&&n2<0){n1=0-n1;n2=0-n2;}
    int ram=n1,judge=0;
    while(1){
        judge=0;
        for (int i=2;i<n1;i++){
            if (n1%i==0 && n2%i==0){
                ram/=i; n2/=i;
                judge=1;
            }
        }
        if (judge==0){
            break;
        }
    }
    if (ram>0 && n2<0){
        ram = 0-ram;
        n2 = abs(n2);
    }
    printf("ram=%d,n2=%d\n",ram,n2);
    if (ram>=0){
        M[0] = '0'+ram;
        M[1] ='/';}
    else {
        M[0] = '-';
        M[1] = '0'-ram;
        M[2] ='/';
    }
    printf("%d %d\n",n2,ram);
    if (n2>=0 && ram>=0){
    M[2] = '0'+n2;
    *p = 3;}
    else if (n2>=0 && ram<0)
    {
        M[3] = '0'+n2;
        *p = 4 ;
    }
    else{
        M[3]='-';
        M[4]='0'-n2;
        *p = 5 ;
    }
    //printf("%d\n",p);
    return 0;
}
int main()
{
    int a,b,c,d;
    scanf("%d,%d",&a,&b);
    getchar( );
    scanf("%d,%d",&c,&d);
    getchar( );
    //printf("%d %d %d %d\n",a,b,c,d);
    int m1 =(b-d); int m2 = (a-c);
    int b1 = (b*c-a*d); int b2 = (c-a);
    char M[10]={0};
    char B[10]={0};
    //printf("%d %d\n",m1,b1);
    if ((m1%m2==0&&b1%b2==0)) {
        //printf("111\n");
        M[0]= m1 / m2;
        B[0]=b1/b2;
        //printf("%d %d %d %d\n",m1,m2,b1,b2);
        if (B[0]>0){
            if(M[0]==1) {printf("y=x+%d",B[0]);}
            else if(M[0]==-1) {printf("y=-x+%d",B[0]);}
            else {printf("y=%dx+%d",M[0],B[0]);}
        }
        else if (B[0]==0){
            if(M[0]==1) {printf("y=x");}
            else if(M[0]==-1) {printf("y=-x");}
            else {printf("y=%dx",M[0]);}
        }
        else {
            if(M[0]==1) {printf("y=x%d",B[0]);}
            else if(M[0]==-1) {printf("y=-x%d",B[0]);}
            else {printf("y=%dx%d",M[0],B[0]);}
        }
    }
    else{
        int p1=1;
        int p2=1;
        if(m1==0){
            M[0]=0;
            p1=1;
        }
        else if (m1%m2!=0){
            //printf("%d %d\n",m1,m2);
            common(M,m1,m2,&p1);
            for (int i=0;i<p1;i++){
                printf("M[%d]=%c\n",i,M[i]);
            }
        }
        else M[0]=m1/m2;
        if(b1==0){
            B[0]=0;
            p2=1;
        }
        else if (b1%b2!=0){
            common(B,b1,b2,&p2);
        }
        else B[0]=b1/b2;
        /*for (int i=0;i<3;i++){
            printf("%c",M[i]);
        }
        printf("\n");
        for (int i=0;i<3;i++){
            printf("%c",B[i]);
        }
        printf("\n");*/
        printf("y=");
        if (M[1]==0){
            printf("%c",M[0]);
        }
        else {
            for(int i=0;i<p1;i++){
                printf("%c",M[i]);
            }
        }
        printf("x");
        if (B[0]>0){
            printf("+");
        }
        if (B[1]==0 && B[0]!=0){
            printf("%c",B[0]);
        }
        else if(B[0]==0){
            printf("");
        }
        else {
            for (int i=0;i<p2;i++){
                printf("%c",B[i]);
            }
        }
    }
    return 0;
}