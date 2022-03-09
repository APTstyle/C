#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
void sw(char a[1000],char b[1000]) {
    char c[1000];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}

int main()
{
    char in[1000];
    char a[1000][1000];
    char p[1000];
    char q[1000];
    int nn=1;
    scanf("%[^\n]",in);
    scanf("%s",p);
    scanf("%s",q);
    int begin=0,end=-1,count=0;
    for(int i=0;i<1000;i++){
        if(in[i]!=' '&&begin<=end){
            begin=i;
            //printf("%d\n",begin);
        }
        if(in[i]==' '&&begin>end){
            end=i;
            for(int j=begin;j<end;j++){
                a[count][j-begin]=in[j];
            }
            //printf("a[%d]=%s\n",count,a[count]);
            count++;
        }
        if(in[i]=='\0'){
            end=i;
            for(int j=begin;j<end;j++){
                a[count][j-begin]=in[j];
            }
            //printf("%d",i);
            break;
        }
    }
    char name[1000][1000];
    int times[1000];
    
    for(int i=0;i<1000;i++){
        nn=1;
        if(a[i][0]=='\0'){
            break;
        }
        for(int j=0;j<1000;j++){
            if(strcmp(name[j],a[i])==0){
                times[j]++;
                //printf("j %s:%d\n",name[j],times[j]);
                nn=0;
                break;
            }
        }
        if(nn==1){
            for(int m=0;m<1000;m++) {
                if(name[m][0]=='\0'){
                    strcpy(name[m],a[i]);
                    times[m]=1;
                    //printf("m %s:%d\n",name[m],times[m]);
                    break;
                }
            }
        }
    }
    //Q取代P
    char str1[1000][1000];
    for(int i=0;i<1000;i++) {
        if(strcmp(a[i],"\0")==0) {
            break;
        }
        strcpy(str1[i],a[i]);
    }
    for(int i=0;i<1000;i++) {
        if(strcmp(str1[i],p)==0) {
            strcpy(str1[i],q);
        }
        printf("%s",str1[i]);
        if(str1[i][0]=='\0') {
            printf("\n");
            break;
        }
        else printf(" ");
    }
    //P之前插入Q
    char str2[1000][1000];
    for(int i=0;i<1000;i++) {
        if(strcmp(a[i],"\0")==0) {
            break;
        }
        strcpy(str2[i],a[i]);
    }
    for(int i=0;i<1000;i++) {
        if(strcmp(str2[i],p)==0) {
            printf("%s ",q);
        }
        printf("%s",str2[i]);
        if(str2[i][0]=='\0') {
            printf("\n");
            break;
        }
        else printf(" ");
    }
    //刪除P
    char str3[1000][1000];
    int r=0;
    for(int i=0;i<1000;i++) {
        if(strcmp(a[i],"\0")==0) {
            break;
        }
        if(strcmp(a[i],p)!=0){
            //printf("%d\n",strcmp(a[i],p));
            strcpy(str3[r],a[i]);
            r++;
        }
    }
    for(int i=0;i<1000;i++) {
        printf("%s",str3[i]);
        if(str3[i][0]=='\0') {
            printf("\n");
            break;
        }
        else printf(" ");
    }
    //printf("%s",a[0]);
    //printf(" %s",a[1]);
    //printf("%s\n",p);
    //printf("%s",q);
    for(int i=0;i<1000;i++) {
        if(strcmp(name[i],"\0")==0) {
            break;
            }
        for(int j=1;j<1000;j++){
            if(strcmp(name[j],"\0")==0) {
            break;
            }
            else {
                if(times[j-1]<times[j]){
                    sw(name[j-1],name[j]);
                    int ram=times[j-1];
                    times[j-1]=times[j];
                    times[j]=ram;
                }
                else if(times[j-1]==times[j]){
                    for(int m=0;m<1000;m++) {
                        if((name[j-1][m]-'0')>(name[j][m]-'0')){
                            sw(name[j-1],name[j]);
                            int ram=times[j-1];
                            times[j-1]=times[j];
                            times[j]=ram;
                            break;
                        }
                        if((name[j-1][m]-'0')<(name[j][m]-'0')){
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<1000;i++){
        if(times[i]==0){
            break;
        }
        if(i!=0){
            printf("\n");
        }
        printf("%s : %d",name[i],times[i]);
    }
    return 0;
}