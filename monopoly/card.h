#ifndef CARD_H
#define CARD_H

#include <QString>
#include "player.h"

class CardStack
{
    Card *deck[];
    Card *usedCards[];
    shuffle();

public:
    CardStack(QString cardData[][]);
    void pickup(Player *player);
    void returnGojfc(Card card);

};


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

#endif // CARD_H
