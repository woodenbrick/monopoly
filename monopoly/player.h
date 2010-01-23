#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include "gui/playerframe.h"
class Card;
class Square;
class Property;
class Set;

class PurchaseTracker
{
public:
    Property *property[];
    int houses;
};

class Player
{
private:
    QString name;
    //XXX SHOULD WE INCLUDE THE BOARD?
    Square *currentSquare;
    Property *properties[];
    int money;
    Card *gojfc[];
    bool inJail;
    Property *sets[]; //not sure if this is required
    PurchaseTracker currentPurchases;
    QImage counter;
    PlayerFrame *playerFrame;


public:
    Player(QString name, Square *currentSquare, int money, QString counter);
    void makeOffer(Player *player2, int payment, Property *properties[], Card *gojfc[],
                   int paymentPlayer2, Property *propertiesPlayer2[], Card *gojfcPlayer2[]);
    bool hasSet();
    Set propertiesInSetOwned(const QString setName);
    Set propertiesInSetOwned(const Property *prop);
    void confirmHousePurchases();
    void addHouse();
    int returnHouseCount();
    int returnHotelCount();
    int getMoney();
    void makePayment(int amount);
    void receivePayment(int amount);


};


#endif // PLAYER_H
