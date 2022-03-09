#include <stdio.h>
#include <string.h>
void black(char c[300],int map[1000][1000],int x,int y,int n){
    char ram = c[0];
    for(int i = 0;i < strlen(c);i++){
        c[i] = c[i+1];
    }
    if(ram == '1'){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                map[y + i][x + j] = 1;
            }
        }
    }
    else if(ram == '0'){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                map[y + i][x + j] = 0;
            }
        }
    }
    else if(ram == '2'){

        int temp = n/2;
        black(c,map,x,y,temp);
        black(c,map,x+temp,y,temp);
        black(c,map,x,y+temp,temp);
        black(c,map,x+temp,y+temp,temp);
    }
    else{
        return;
    }
}
int main()
{
    int n;
    char c[300];
    scanf("%s",c);
    scanf("%d",&n);
    if(c[0] == '0')printf("all white");
    int map[1000][1000];
    black(c,map,0,0,n);
    for(int i = 0;i <n;i++){
        for(int j = 0;j < n;j++){
            if(map[i][j] == 1){
                printf("%d,%d\n",i,j);
            }
        }
    }
}