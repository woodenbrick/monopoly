#ifndef CARD_H
#define CARD_H

#include <QString>
#include "player.h"

class Card
{
    int id;
    QString text;
    bool isGojfc;
    int streetRepairs; //set to 0 if not street repairs otherwise it is the amount per house
    int money; //a payment to be made (- pay, + receive) or the cost of street repairs per hotel
    bool playerTransfer; //true if money should be transfered between players
    int square; //a square to move to or -1 if not moving.

public:
    Card(QString cardData[]);
};


class CardStack
{
    Card *deck[];
    Card *usedCards[];
    void shuffle();

public:
    CardStack();
    void addToStack(Card card);
    void pickup(Player &player);
    void returnGojfc(Card card);

};

#endif // CARD_H
