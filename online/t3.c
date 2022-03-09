#include <stdio.h>
#include <string.h>
int main()
{
  int list[5]={0,1,2,3,4};
  int ram[5]={0,1,2,3,4};
  int k;
   for(int i=0;i<5;i++) {
     for(int j=0;j<5;j++) {
       k=ram[i];
       ram[i]=ram[j];
       ram[j]=k;
       for(int z=0;z<5;z++) {
         printf("%d",ram[z]);
         ram[z]=list[z];
       }
       printf("\n");
       
     }
   }
   return(0);
}