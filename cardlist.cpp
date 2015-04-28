#include "cardlist.h"
#include "helper.h"
#include <sstream>

using namespace std;

CardList::CardList()
    : m_pHeadNode(NULL), m_pTailNode(NULL)
{
}

CardList::CardList(int size)
    : m_pHeadNode(NULL), m_pTailNode(NULL)
{
    for (int i=1; i < size + 1; ++i) {
        pushBack(i);
    }
}

CardList::~CardList()
{
    while(m_pHeadNode) {
        CardNode *current = m_pHeadNode;
        m_pHeadNode = m_pHeadNode->next;
        delete current;
    }

    m_pHeadNode = NULL;
    m_pTailNode = NULL;
}

void CardList::pushFront(const int cardId)
{
    CardNode *newNode = new CardNode(cardId);
    if (!m_pHeadNode) {
        m_pHeadNode = newNode;
        m_pTailNode = newNode;
        return;
    }
    newNode->next = m_pHeadNode;
    m_pHeadNode = newNode;
}

int CardList::popFront()
{
    if(!m_pHeadNode)
        return '0';

    int data = m_pHeadNode->cardId;
    CardNode *node = m_pHeadNode;
    m_pHeadNode = node->next;
    delete node;

    return data;
}

void CardList::pushBack(const int cardId)
{
    CardNode * newNode = new CardNode(cardId);
    if (!m_pHeadNode) {
        m_pHeadNode = newNode;
        m_pTailNode = newNode;
    }

    m_pTailNode->next = newNode;
    newNode->next = NULL;
    m_pTailNode = newNode;
}


size_t CardList::size() const
{
    size_t size = 0;
    CardNode * current = m_pHeadNode;

    while(current) {
        size++;
        if (NULL == current->next) {
            return size;
        }
        current = current->next;
    }

    return size;
}

void CardList::print() const
{
    CardNode *elm = m_pHeadNode;
    while(elm) {
        DLOG("card: %d\n", elm->cardId);
        elm = elm->next;
    }
}

string CardList::listString() const
{
    string cardsString;
    CardNode * current = m_pHeadNode;
    while(current) {
        std::ostringstream ss;
        ss << current->cardId;
        cardsString.append(ss.str() + " ");
        current = current->next;
    }
    return cardsString;
}

