#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int main()
{
    char a[100]="",b[100]="",c[100]="",d[100]="";
    char p[100]="";
    int c1=0,c2=0;
    int counter = 0;
    int sin;
    scanf("%d",&sin);
    getchar();
    scanf("%s",&a);
    getchar();
    scanf("%s",&b);
    getchar();
    int i,j;
    for(i=0;i<100;i++){
        if (a[i]=='\0'){
            c1=i;
            break;
        }
    }
    for(i=0;i<100;i++){
        if (b[i]=='\0'){
            c2=i;
            break;
        }
    }
    for(i=0;i<c1;i++){
        c[c1-i-1]=a[i];
    }
    for(i=0;i<c2;i++){
        d[c2-i-1]=b[i];
    }
    if (sin==1){
        for(i=0;i<100;i++){
                p[i] = c[i] + d[i] + counter -'0';
                counter=0;
                if ((p[i]-'0')>=10){
                    counter = (p[i]-'0')/10;
                    p[i]=((p[i]-'0')%10)+'0';
                    //printf("%d\n",counter);
                }
                if((p[i]-'0')<0||(p[i]-'0')>10){
                    p[i]='\0';
                    break;
                }
            }
    }
    if(sin==2){
        for(i=0;i<100;i++){
                if (*c == *d){
                    p[0]='0';
                    p[1]='\0';
                    //printf("%d\n",counter);
                    break;
                }
                p[i] = c[i] - d[i] +counter +'0';
                counter=0;
                if (p[i]<0){
                    counter=-1;
                }
                /*if ((p[i]-'0')>=10){
                    counter = (p[i]-'0')/10;
                    p[i]=((p[i]-'0')%10)+'0';
                    //printf("%d\n",counter);
                }*/
                if(i>c1&&i>c2){
                    p[i-1]='\0';
                    break;
                }
            }
    }
    if(sin==3){
        /*if(c2!=1)
            {if ((c[c1-1]-'0')*(d[c2-1]-'0')>=10){
                p[c1+c2-1]='0';
            }
            else{
                
                p[c1+c2-2]='0';
                
            }}*/
        for(j=0;j<100;j++){
            if((d[j]-'0')<0||(d[j]-'0')>=10){
                if((p[i+j-1]-'0')>=10 || (p[i+j-1]-'0')<0){
                    p[i+j-1]='\0';
                    printf("****");
                }
                else{
                    p[i+j]='\0';
                }
                    break;
                }
            for(i=0;i<100;i++){
                if (j==0){
                    p[i+j] = p[i+j]+ ((c[i]-'0') * (d[j]-'0')) + counter +'0';
                }
                else{
                    p[i+j] = p[i+j]+ ((c[i]-'0') * (d[j]-'0')) + counter;
                }
                if ((p[i+j]-'0')>=10){
                    p[i+j+1] = (p[i+j]-'0')/10 + '0';
                    counter = (p[i+j]-'0')/10;
                    p[i+j]=((p[i+j]-'0')%10)+'0';
                    //printf("%d\n",counter);
                }
                if((c[i]-'0')<0||(c[i]-'0')>=10){
                    //p[i]='\0';
                    break;
                }
                printf("%c,i=%d,j=%d,counter=%d\n",p[i+j],i,j,counter);
                counter=0;
            }
        }
    }
    printf("%s\n",c);
    printf("%s\n",d);
    int c3;
    char p1[100];
    for(i=0;i<100;i++){
        if (p[i]=='\0'){
            c3=i;
            break;
        }
    }
    for(i=0;i<c3;i++){
        p1[c3-i-1]=p[i];
    }
    for(i=0;i<c3;i++){
        printf("%c",p1[i]);
    }
    
    
    return 0;
}