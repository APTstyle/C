#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
 
struct girls{
  int age;
  char name[10];
};
 
int main(){
  girls TWICE[3] =
  {17, {'T', 'z', 'u', 'y', 'u', '\0'},
   19, {'M', 'i', 'n', 'a', '\0'},
   20, {'M', 'o', 'm', 'o', '\0'},
  };
  girls *ONCE = TWICE;
  for(int i = 0; i < 3; i++){
    printf("%d \n", ONCE[i].age);
    printf("%s \n", ONCE[i].name);
  };
  return 0;
}