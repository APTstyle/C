#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int isIn(char *s[300], char c[300], int n) { //判斷c 是否在 s 裡面
    int i=0;
    for (i=0; i<n; i++){
        if (c==s[i]) return 1;}
    return 0;
}
char (*erase(char s[300][300]))[300] { //將重複的部分刪除，變成集合
    int i=0, j=0;
    char *p[300];
    for (;strcmp(s[i],"\0")!=0;i++) {
        if(isIn(p, s[i], j)==0){
            p[j]=s[i];
            j++;
        }
    }
    return p;
}
int isDupilcate(char *s1, char *s2) { //判斷 s1, s2 是否有重複字元
    int i=0, j=0;
    printf("%s, %s\n", s1, s2);
    for (i=0; s1[i]!='\0'; i++) {
        for (j=0;s2[j]!='\0'; j++) {
            if (s1[i]==s2[j]) return 1;
        }
    }
    return 0;
}
int isFitLength(char *s1, char *s2, int m) { // 判斷s1+s2的長度是否剛好符合
    if (m==(strlen(s1)+strlen(s2))) return 1;
    else return 0;
}
void compute(char s[300][300], int n, int m) {
    char *p[300];
    int i=0, j=0, sum=0;
    p = {erase(s[300][300])};
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) { // p[i], p[j] 沒有重複，總和長度又等於 m
            if ((isDupilcate(p[i], p[j])==0) && (isFitLength(p[i], p[j],m)))
                sum++;
        }
    }
    printf("sum = %d\n", sum);
}
int main(){
    int i=0,j=0,m=0;    
    char ans[300][300]= {"AABAAB","ABCABCDE","CDECD","GFFGF"};
    char s1[300][300] = {"AABAAB"};
    char s2[300][300] = {"ABCABCDE","CDECD","GFFGF"};
    for(;strcmp(ans[i],"\0")!=0;i++){}
    for(;strcmp(s1[j],"\0")!=0;j++){}
    for(;strcmp(s2[m],"\0")!=0;m++){}
    printf("%d %d %d",i,j,m);
    compute()
    return 0;
}