#include <stdio.h>
#include "funcs.h"

int resultOfBet(int prize, int personMoney){
    if (prize > 0){
        printf("\nCongratulations! You win %i $!!!", prize);
    }
     else
    {
        printf("This time you lose :(\nWish you good luck next time!!!");
    }
    personMoney += prize;
    printf("\nYour current balance us %i $", personMoney);
    return personMoney;
}
