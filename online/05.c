#include<stdio.h>
#include <math.h>

int main()
{
    int hr[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            hr[i][j] = 0;
        }
    }
    int n[3];
    int h[3];
    int t[3][3];
    for (int i = 0; i < 3; i++)
    {
        scanf("\n%d",&n[i]);
        scanf("\n%d",&h[i]);
        for (int j=0; j<h[i]; j++)
        {
            scanf("\n%d",&t[i][j]);
        }
    }
int x,y;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < h[i]; j++) {
            x=(t[i][j])/10;
            y=(t[i][j])%10;
            if (hr[x][y]!=0)
            {
                /*printf("%d %d %d\n",i,j,hr[x][y]);*/
                printf("%d and %d conflict on %d\n",hr[x][y],n[i],t[i][j]);
                break;
            }
            else
            {
                hr[x][y]=n[i];
                /*printf("%d %d %d\n",x,y,n[i]);*/
            }
        }
    }
    return 0;
}