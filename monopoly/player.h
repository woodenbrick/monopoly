#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include "gui/playerframe.h"
#include <vector>
#include "dice.h"

class Card;
class CardStack;
class Square;
class Property;
class Offer;


class Purchase
{
    Property* property;
    int houseCount;
public:
    Purchase(Property* property);
    Property* getProperty();
    int getHouseCount();
    void addHouse();
    void removeHouse();
    void makePurchases();
};

class PurchaseTracker
{
    int houses; //this is the total number of houses for all purchases
    std::vector<Purchase *> purchases;
    Purchase* currentPurchase;

public:
    PurchaseTracker();
    void addPurchase(Property* property);
    void removePurchase(Property* property);
    void cancelPurchases();
    void makePurchases();
    Purchase* getPurchase(Property* property);
};

class Player
{
private:
    QString name;
    Square *currentSquare;
    std::vector<Property*> properties;
    int money;
    std::vector<Card *> gojfc;
    bool inJail;
    PurchaseTracker currentPurchases;
    QImage counter;
    PlayerFrame *playerFrame;
    void moveForward();
    int returnBuildingCount(bool isHotelCount);


public:
    std::vector<Player *> *otherPlayers;
    Dice* dice;
    bool hasTurn;
    bool pauseTurn; //true when player needs to do something before game can continue
    Player *creditor;
    int debt;
    Player(QString name, Square *currentSquare, int money, QString counter);
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
