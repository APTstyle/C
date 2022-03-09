#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int GPA(char num[]){
    if(strcmp(num,"4.3")==0){
        return 95;
    }
    else if(strcmp(num,"4.0")==0){
        return 87;
    }
    else if(strcmp(num,"3.7")==0){
        return 82;
    }
    else if(strcmp(num,"3.3")==0){
        return 78;
    }
    else if(strcmp(num,"3.0")==0){
        return 75;
    }
    else if(strcmp(num,"2.7")==0){
        return 70;
    }
    else if(strcmp(num,"2.3")==0){
        return 68;
    }
    else if(strcmp(num,"2.0")==0){
        return 65;
    }
    else if(strcmp(num,"1.7")==0){
        return 60;
    }
    else{
        return 50;
    }
    return 0;
}
int G(char num[]){
    if(strcmp(num,"A+")==0){
        return 95;
    }
    else if(strcmp(num,"A")==0){
        return 87;
    }
    else if(strcmp(num,"A-")==0){
        return 82;
    }
    else if(strcmp(num,"B+")==0){
        return 78;
    }
    else if(strcmp(num,"B")==0){
        return 75;
    }
    else if(strcmp(num,"B-")==0){
        return 70;
    }
    else if(strcmp(num,"C+")==0){
        return 68;
    }
    else if(strcmp(num,"C")==0){
        return 65;
    }
    else if(strcmp(num,"C-")==0){
        return 60;
    }
    else{
        return 50;
    }
}
int S(char num[]){
    if(strcmp(num,"90-100")==0){
        return 95;
    }
    else if(strcmp(num,"85-89")==0){
        return 87;
    }
    else if(strcmp(num,"80-84")==0){
        return 82;
    }
    else if(strcmp(num,"77-79")==0){
        return 78;
    }
    else if(strcmp(num,"73-76")==0){
        return 75;
    }
    else if(strcmp(num,"70-72")==0){
        return 70;
    }
    else if(strcmp(num,"67-69")==0){
        return 68;
    }
    else if(strcmp(num,"63-66")==0){
        return 65;
    }
    else if(strcmp(num,"60-62")==0){
        return 60;
    }
    return 0;
}
int main()
{
    int ln;
    float sl[100];
    int nl[100];
    scanf("%d",&ln);
    char type[10][5];
    for(int i=0;i<ln;i++) {
        scanf("%s",type[i]);
        //printf("%s",type[i]);
    }
    int sn;
    scanf("%d",&sn);
    char ram[10];
    for(int i=0;i<sn;i++) { //學生數
        scanf("%d",&nl[i]);
        for(int j=0;j<ln;j++) { //課堂數
            scanf("%s",&ram);
            //printf("%s\n",ram);
            //printf("type[%d]==%s\n",j,type[j]);
            if(strcmp(type[j],"S")==0) {
                sl[i]+=S(ram);
                //printf("***\n");
                //printf("%d",sl[i]);
            }
            else if(strcmp(type[j],"GPA")==0) {
                sl[i]+=GPA(ram);
                //printf("***\n");
                //printf("%d",sl[i]);
            }
            else if(strcmp(type[j],"G")==0) {
                sl[i]+=G(ram);
                //printf("***\n");
                //printf("%d\n",sl[i]);
            }
        }
    }
    for(int i=0;i<sn;i++){
        sl[i]/=ln;
        //printf("sl[%d]=%f\n",i,sl[i]);
    }
    for(int i=1;i<sn;i++) {
        for(int j=1;j<sn;j++) {
            if(sl[j]>sl[j-1]) {
                float rams;
                int ramn;
                rams = sl[j];
                sl[j] = sl[j-1];
                sl[j-1]= rams;
                ramn = nl[j];
                nl[j] = nl[j-1];
                nl[j-1] = ramn;
            }
        }
    }
    for (int i=0;i<3;i++) {
        printf("%d\n",nl[i]);
        printf("%.0f\n",sl[i]);
    }
    return 0;
}