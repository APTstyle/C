#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void){
    int countnumber,tans = 0;
    scanf ("%d",&countnumber);
    int counti = 1;
    char arr[100];
    int arr2[100];
    scanf (" %s",arr);
    int arrlen = strlen(arr);
    int answer[50];
    for (int i = 0;i < arrlen;i++){
      if (islower(arr[i])) arr2[i] = 1;
      else arr2[i] = 0;
    }
    int k = 0;
    for (int i = 1;i < arrlen;i++){
      if (arr2[i] == arr2[i-1]) counti += 1;
      else {
        answer[k] = counti;
        k++;
        counti = 1;
      }
    }
    answer[k] = counti;
    k++;
    for (int i = 0;i < k;i++){
      int fot = 0;
      if (answer[i] >= countnumber){
        fot += countnumber;
        for (int j = i + 1;j < k;j++){
          if(answer[j] == countnumber) fot += countnumber;
          else if (answer[j] > countnumber){
            fot += countnumber;
            break;
          }
          else break;
        }
        if (fot > tans) tans = fot;
      }
    }
    printf("%d\n",tans);
}