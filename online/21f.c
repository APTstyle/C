#include <stdio.h>
#include <string.h>
int main(void) {
    int fin = 0;
    char arr[100][100];
    int cou = 0;  //目標個數
    char str[50];
    scanf("%[^\n]",str);
    char *delim = " ";
    char * pch;
    pch = strtok(str,delim);
    while (pch != NULL) {
        strcpy(arr[cou],pch);
        pch = strtok (NULL, delim);
        cou++;
    }
    int menumber;
    int arr2[cou];             //存是否跟目標一樣的字串
    for (int pp = 0;pp < cou;pp++) arr2[pp] = 0;
    scanf(" %d",&menumber);
    int ansarr[200][cou];                //存最後能用單字個數
    for (int i = 0;i < menumber;i++){        
        char uarr[100][100];
        int coun = 0;
        char ustr[50];
        scanf(" %[^\n]",ustr);
        pch = strtok(ustr,delim);
        while (pch != NULL) {
            strcpy(uarr[coun],pch);
            pch = strtok (NULL, delim);
            coun++;
        }
        int senlen = coun;
        int judge = 0;
        for (int j = 0;j < senlen;j++){   // 輸入字元的個數 第一個開始
            int wordlen = strlen(uarr[j]);  // 輸入字元的長度
            for (int h = 0;h < (cou);h++){     // 目標字串的第一個開始
                int oplen = strlen(arr[h]);    // 目標字元的長度
                for (int k = 0;k < wordlen;k++){   // 開始從字元的第一個開始
                    if (arr[h][k] == uarr[j][k]) continue;
                    else if (oplen != wordlen) judge = 1;
                    else judge = 1;
                }
                if (judge == 0){
                    if (arr2[h] == 1) break;
                    else arr2[h] = 1;
                }
                judge = 0;
            }
        }
        for (int l = 0;l < cou;l++) ansarr[fin][l] = arr2[l];   //加總
        fin += 1;
        for (int pp = 0;pp < cou;pp++) arr2[pp] = 0;
    }
    int pe = 0;
    int answer = 0;
    int test[cou];
    for (int i = 0;i < cou;i++) test[i] = 0;

    for (int i = 0;i < menumber-1;i++){
        for (int j = i+1;j < menumber;j++){
            for (int h = 0;h < cou;h++) test[h] = ansarr[i][h]+ansarr[j][h];
            for (int de = 0;de < cou;de++) {
                if (test[de] == 0 || test[de] == 2) pe = 1;     
            }
            if (pe == 0){
                answer += 1;
            }
            pe = 0;
        }
    }
    printf("%d\n",answer);
}