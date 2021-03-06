#include <iostream>
#include "cardlist.h"
#include "helper.h"
#include "icardoperation.h"

using namespace std;

int main(int argc, char * argv[])
{
    if ( 3 != argc ) {
        DMSG("Please input cards' number', for example, ./CardQuiz -n 10, where n belong (0,127) \n");
        return -1;
    }

    int cardCount = 0;

    if (0 == string(argv[1]).compare("-n")) {
        cardCount =  atoi(argv[2]);

        if (cardCount < 0 || cardCount > 127) {
            DMSG("n belong to (0,127)\n");
            return -1;
        }
    }

    CardList * pCardsOnTable = new CardList();
    CardList * pCardsInHand = new CardList(cardCount);
    ICardOperation cardsOperation;

    int rounds = cardsOperation.yeildRoundsWhenSameWithOriginalInHand(pCardsInHand, pCardsOnTable);
    DLOG("rounds : %d\n", rounds);

    delete pCardsOnTable;
    delete pCardsInHand;

    return 0;
}
