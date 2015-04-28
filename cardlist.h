#ifndef CARDLIST_H
#define CARDLIST_H

#include <iostream>
using namespace std;

typedef struct card_node_t {
    int cardId;   // id of the card, from 1, -1 is invalid
    card_node_t *next;

    card_node_t() :cardId(-1),  next(NULL) {
    }
    card_node_t(const int cardId) : cardId(cardId), next(NULL) {
    }
} CardNode, *pCardNode;

class CardList
{
public:
    CardList();
    CardList(int size);
    ~CardList();

    void pushFront(const int cardId);
    int popFront();
    void pushBack(const int cardId);
    void popBack(); /* reserve */

    string listString() const;

    size_t size() const;
    void print() const;

private: // Helper

private:
    CardNode * m_pHeadNode;
    CardNode * m_pTailNode;
};



#endif // CARDLIST_H
