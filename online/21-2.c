#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
int judge(char in[300],char ans[300][300]){
    for(int i=0;strcmp(ans[i],"\0")!=0;i++) {
        if(strcmp(in,ans[i])==0){
            return i;
        }
    }
    return -1;
}
int main()
{
    char ans[300][300];
    scanf("%[^\n]",ans);
    //printf("%s\n",ans);
    int n;
    scanf("%d",&n);
    getchar();
    int i,j,m;
    char in[300][300];
    int list[300][300];
    int count=0;
    for(i=0;i<n;i++) {
        scanf("%[^\n]",in);
        getchar();
        printf("%c123\n",in[2]);
        int ram=0;
        for(j=0;strcmp(in[j],"\0")!=0;j++) {
            printf("%d\n",j);
            int value=judge(in[j],ans);
            if(value!=-1){
                for(m=0;m<ram;m++) {
                    if(list[count][m]==value){
                        break;
                    }
                }
                if(m==ram) {
                    list[count][ram]=value;
                    ram++;
                }
            }
        }
    }
    for(i=0;i<3;i++) {
        printf("%d ",list[0][i]);
    }
    return 0;
}