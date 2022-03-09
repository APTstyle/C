#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include <string.h> 
double change(char* card){ 
    if(strcmp("A",card)==0){ 
        return 1.0; 
    } 
    else if(strcmp("J",card)==0||strcmp("Q",card)==0||strcmp("K",card)==0){ 
        return 0.5; 
    } 
    else{ 
        return atof(card);
    } 
} 
int main(){ 
    double player1 = 0.0; 
    double player2 = 0.0; 
    char player[2]; 
    for(int i = 0 ;i<6;i++){ 
        if(i<3){ 
            scanf("%s",&player); 
            player1+=change(player); 
             
        } 
        else{ 
            scanf("%s",&player); 
            player2+=change(player); 
        } 
    } 
    if(player1>10.5){ 
        player1 = 0; 
    } 
    if(player2>10.5){ 
        player2 = 0; 
    } 
    if(player1>player2){ 
        printf("%.1f\n%.1f\nA wins.",player1,player2); 
    } 
    else if(player1<player2){ 
        printf("%.1f\n%.1f\nB wins.",player1,player2); 
    } 
    else{ 
        printf("%.1f\n%.1f\nIt's a tie.",player1,player2); 
    } 
     
}