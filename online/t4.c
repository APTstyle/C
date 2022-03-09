#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i[4], j;

    for (i[0]=1; i[0]<=4; i[0]++)
    {
        for (i[1]=1; i[1]<=4; i[1]++)
        {
            if (i[1]==i[0]) 
                continue;
            for (i[2]=1; i[2]<=4; i[2]++)
            {
                for (j=0; j<2; j++)
                    if (i[2]==i[j])
                        j=5;
                if (j>=5) continue;
                for (i[3]=1; i[3]<=4; i[3]++)
                {
                    for (j=0; j<3; j++)
                        if (i[3]==i[j])
                            j=5;
                    if (j>=5) continue;
                    for (j=0; j<3; j++)
                        printf("%d ", i[j]);
                    printf("\n");
                }
            }
        }
    }
    system("pause");
    return 0;
}