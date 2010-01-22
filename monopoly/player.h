#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include "square.h"
#include "gui/playerframe.h"

struct purchaseTracker
{
    Property *property;
    int houses;
};

class Player
{
private:
    QString name;
    //XXX SHOULD WE INCLUDE THE BOARD?
    Square *currentSquare;
    Property [] *properties;
    int money;
    Card[] *gojfc;
    bool inJail;
    Property [] *sets //not sure if this is required
    purchaseTracker currentPurchases;
    QImage *counter;
    PlayerFrame *playerFrame;


public:
    Player(QString name, Square *currentSquare, int money, QImage *counter);
    void makeOffer(Player *player2, int payment, Property *properties[], Card *gojfc[],
                   int paymentPlayer2, Property *propertiesPlayer2[], Card *gojfcPlayer2[]);
    bool hasSet();
    Property[] propertiesInSetOwned(QString set);
    Property[] propertiesInSetOwned(Property);
    void confirmHousePurchases();
    void addHouse();
    int [] returnHouseHotelCount();

};


#endif // PLAYER_H
