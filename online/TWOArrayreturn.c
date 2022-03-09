#include <stdio.h>
#include <string.h>
int (* TWOARRAY() ) [4]
{
  //int **ptr2=(int**)malloc(3*sizeof(int*));
  static int number[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

  return  number;
}
int main()
{
   int (*a)[4]={TWOARRAY()};
   for(int i=0;i<3;i++){
       for(int j=0;j<4;j++){
           printf("%d\n", a[i][j]);
       }
   }
   
   
   return(0);
}