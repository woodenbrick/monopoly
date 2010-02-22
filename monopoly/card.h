#ifndef CARD_H
#define CARD_H

#include <QString>
#include <vector>
#include "player.h"
#include "square.h"


class Card
{
    friend class CardStack;
    int id;
    QString text;
    bool isGojfc;
    int streetRepairs; //set to 0 if not street repairs otherwise it is the amount per house
    int money; //a payment to be made (- pay, + receive) or the cost of street repairs per hotel
    bool playerTransfer; //true if money should be transfered between players
    int squareId; //a square to move to or -1 if not moving. -2 for special cases (move to next railroad, go back 3 spaces
    Square* square; //A destination square, if we are going to move
    
public:
    Card(int id, QString text, bool isGojfc, int streetRepairs, int money,
         bool playerTransfer, int squareId);
    void setDestinationSquare(Square* destination);
    void printCard();

};


class CardStack
{
    std::vector<Card *> deck;
    std::vector<Card *> usedCards;
    std::vector<Card *>::iterator iter;
    void addToDiscardPile(Card *card);

public:
    CardStack();
    void shuffle();
    void addToStack(Card *card);
    QString pickup(Player *player);
    void useGojfc(Card *card);

};

#endif // CARD_H
