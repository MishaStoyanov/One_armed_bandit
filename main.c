#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcs.h"

int nothing(int arr[5]);
int one7(int arr[5]);
int same2(int arr[5]);
int allsame(int arr[5]);
int all7(int arr[5]);
/*0 - nothing(no same)
  1 - one 7
  2 - 1/3 same numbers - berem za 1/3 2, t.k. eto 40% i samoe maloe
  3 - all the same
  4 - all 7
*/
int main(){

int balance = 2500;
int bet = 0;
int temp;
int numbers[5];

    while (1){

        system("clear");
        printf("\t\t\t\t\tWelcome to one-armed bandit!\n");
        printf("\n\n");
        if (balance < 1) 
        {
        	printf("You have too small balance to play :(\nSee you next time!!!\n\n");
		break;
	}
        bet = makingBet(balance);
        balance -= bet;

        printf("\n");
        for (int i = 0; i < 5; i++){ // generation of numbers
            numbers[i] = rand () % 10;//6//7
            printf("%i ", numbers[i]);
        }
        printf("\n");

        if (all7(numbers))
            balance = resultOfBet(bet * 3, balance);
         else
        if (allsame(numbers))
            balance = resultOfBet(bet * 2, balance);
         else
        if (same2(numbers) || one7(numbers))
            balance = resultOfBet(bet, balance);
         else
        if (nothing(numbers))
         balance = resultOfBet(0, balance);

        printf("\nDo you want to continue to play?(1/0)");
        scanf("%i", &temp);
        if (temp == 0) break;
    }
}

int nothing(int arr[5]){
    for (int i = 0; i < 4; i++){
        for (int j = i+1; j < 5; j++){
            if (arr[i] == arr[j]) return 0;
        }
    }
    return 1;
}

int one7(int arr[5]){
    for (int i = 0; i < 5; i++)
        if (arr[i] == 7) return 1;

    return 0;
}

int same2(int arr[5]){
    for (int i = 0;i < 4; i++){
        for (int j = i + 1; j < 5; j++)
            if(arr[i] == arr[j]) return 1;
    }

    return 0;
}
int allsame(int arr[5]){
    for (int i = 0; i < 4; i++){
        if (arr[i] != arr[i + 1]) return 0;
    }

    return 1;
}
int all7(int arr[5]){
    for (int i = 0; i < 5; i++){
        if (arr[i] != 7) return 0;
    }

    return 1;
}
