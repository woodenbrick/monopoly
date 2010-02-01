#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include "gui/playerframe.h"
#include <vector>
class Card;
class CardStack;
class Square;
class Square;
class Offer;


class Purchase
{
    Square* property;
    int houseCount;
public:
    Purchase(Square* property, int houseCount);
    Square* getProperty();
    int getHouseCount();
};

class PurchaseTracker
{
    int houses; //this is the total number of houses for all purchases
    std::vector<Purchase> purchases;
public:
    void addPurchase(Square * property);
    void removePurchase(Square * property);
    void cancelPurchases();
    void makePurchases();
};

class Player
{
private:
    QString name;
    Square *currentSquare;
    std::vector<Square*> properties;
    int money;
    std::vector<Card *> gojfc;
    bool inJail;
    PurchaseTracker currentPurchases;
    QImage counter;
    PlayerFrame *playerFrame;
    void moveForward();


public:
    std::vector<Player *> *otherPlayers;
    bool hasTurn;
    bool pauseTurn; //true when player needs to do something before game can continue
    Player *creditor;
    int debt;
    Player(QString name, Square &currentSquare, int money, QString counter);
    void makeOffer(Offer *offer);
    bool hasSet();
    int propertiesInSetOwned(const QString setName);
    int propertiesInSetOwned(const Square *prop);
    void confirmHousePurchases();
    int returnHouseCount();
    int returnHotelCount();
    int getMoney();
    void createDebt(int amount, Player *player);
    void createDebt(int amount);
    void acquireGojfc(Card *card);
    void useGojfc(CardStack *stack);
    void makePayment(int amount);
    void receivePayment(int amount);
    void move(int squareId);
    void move(Square* destination);
    void moveToNearestRailroad();
    void moveToNearestUtility();
    void moveBack3Spaces();
    void sendToJail();



};


#endif // PLAYER_H
