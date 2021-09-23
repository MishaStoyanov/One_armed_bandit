#include <stdio.h>
#include "funcs.h"


int makingBet(int personMoney){
    int bet = 0;
    int bigBet;
    char des;
    while(1){
        printf("\nEnter your bet: ");
        scanf("%i", &bet);
        if (bet < 1){
            printf("\nImpossible operation! Accepting bets over 0.99 dollar");
        }
         else
        if (bet > personMoney) printf("\nYou haven't got money for such bet!");
          else
        if (bet > 1000) {
            printf("\nAre you sure that you want to bet %i dollars(1/0)", bet);
            scanf("%i", &bigBet);
//            scanf("%c", &des);
            if (bigBet == 0) printf("\nOk. Let's try one more time!"); else break;
        }
        else
         break;
    }

    printf("Your bet accepted!");
    return bet;
}
