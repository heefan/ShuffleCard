#ifndef ICARDOPERATION_H
#define ICARDOPERATION_H

#include <iostream>
using namespace std;

class CardList;

class ICardOperation
{
public:
    ICardOperation();
    ~ICardOperation();

    bool dealCardsFromHand(CardList * pCardsInHand, CardList * pCardsOnTable, string & result);
    int yeildRoundsWhenSameWithOriginalInHand(CardList * pCardsInHand, CardList * pCardsOnTable );

private:
};

#endif // ICARDOPERATION_H
