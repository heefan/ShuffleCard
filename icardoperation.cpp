#include "icardoperation.h"
#include "cardlist.h"
#include "helper.h"

using namespace std;

ICardOperation::ICardOperation()
{
}

ICardOperation::~ICardOperation()
{
}

bool ICardOperation::dealCardsFromHand(CardList * pCardsInHand, CardList * pCardsOnTable, string & result)
{
    if (!pCardsInHand || 0 == pCardsInHand->size()) {
        DMSG("No cards in hand\n");
        return false;
    }

    do {
      int firstCard = pCardsInHand->popFront();   // 1. Take the top card off the deck
      pCardsOnTable->pushFront(firstCard);         //  2. and set it on the table. (Quesiton. set on top or bottom?)

      if (1 > pCardsInHand->size())
          break;

      int secondCard = pCardsInHand->popFront();  // 3. Take the next card off the top
      pCardsInHand->pushBack(secondCard);        // 4. put it on the bottom of the deck in your hand.

    } while (0 != pCardsInHand->size());

     result = pCardsOnTable->listString();
     return true;
}

int ICardOperation::yeildRoundsWhenSameWithOriginalInHand(CardList * pCardsInHand, CardList * pCardsOnTable )
{
    string originalCardString = pCardsInHand->listString();
    DLOG("original cards string: %s\n", originalCardString.c_str());
    string roundString;
    int count = 0;

    while(0 != originalCardString.compare(roundString)) {
       dealCardsFromHand(pCardsInHand, pCardsOnTable, roundString);
       CardList * tmp = pCardsInHand;
       pCardsInHand = pCardsOnTable;
       pCardsOnTable = tmp;
       count ++;
       DLOG("Round Finished: on hand: %s\n", pCardsInHand->listString().c_str());
   }
    return count;
}

