#include<stdio.h>
#include<string.h>

typedef struct stack_t1{
    char name[100];
    int age;
    int y;
    int m;
    int d;
}s_c;


int main(void){
    int sw=0,sw2=0,p=0;
    char st[1000];
    char *pch;
    char t;
    s_c s[1000];
    while(1){
        scanf("%d",&sw);
        if(sw==3)break;
    if(sw==1){
        scanf(" %[^0-9]",st);
        scanf("%d %d %d %d",&s[p].age,&s[p].y,&s[p].m,&s[p].d);
        for(int i = 0 ; i<strlen(st);i++){
            if(i==0||i==strlen(st)-1||i==strlen(st)-2){
                st[i]="\0";
            }
            if(i>0){
                st[i-1]=st[i];
            }
        }
        for(int i = 0 ;i<strlen(st);i++){
            if(i==strlen(st)-1||i==strlen(st)-2||i==strlen(st)-3){
                st[i]=NULL;
            }
        }
        strcat(s[p].name,st);
        //printf("%s",s[p].name);

        /*char *pch;
        pch = strtok(s," ");
        while (pch != NULL) {
            d1[p]=(int)strtol(pch,&pch,10);
            pch = strtok(NULL, " ");
            p++;
        }*/
    p++;
    }

    else if(sw==2){
        p--;
        scanf(" %d",&sw2);
        if(p<0){
            printf("The Stack is empty\n");
            p++;
        }
        else if(sw2==1){
            printf("%s\n",s[p].name);
        }
        else if(sw2==2){
            printf("%d\n",s[p].age);

        }
        else if(sw2==3){
            printf("%d_%d_%d\n",s[p].y,s[p].m,s[p].d);
        }
        memset(s[p].name,'\0',sizeof(s[p].name));
        sw=0;
        sw2=0;
    }
}


}
