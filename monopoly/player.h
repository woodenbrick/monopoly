#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QImage>
#include "gui/playerframe.h"
#include <vector>
class Card;
class CardStack;
class Square;
class Property;
class Offer;

class PurchaseTracker
{
public:
    std::vector<std::vector <int> > properties; //multidimensional vector [squareid, number of houses]
    int houses; //this is the total number of houses for all purchases
};

class Player
{
private:
    QString name;
    Square *currentSquare;
    std::vector<Property*> properties;
    int money;
    std::vector<Card> gojfc;
    bool inJail;
    PurchaseTracker currentPurchases;
    QImage counter;
    PlayerFrame *playerFrame;
    void moveForward(Square nextPoint);


public:
    bool hasTurn;
    bool pauseTurn; //true when player needs to do something before game can continue
    Player *creditor;
    int debt;
    Player(QString name, Square &currentSquare, int money, QString counter);
    void makeOffer(Offer &offer);
    bool hasSet();
    int propertiesInSetOwned(const QString setName);
    int propertiesInSetOwned(const Property *prop);
    void confirmHousePurchases();
    int returnHouseCount();
    int returnHotelCount();
    int getMoney();
    void createDebt(int amount, Player &player);
    void createDebt(int amount);
    void aquireGojfc(Card &card);
    void useGojfc(CardStack &stack);
    void makePayment(int amount);
    void receivePayment(int amount);
    void move(int squareId);
    void move(Square destination);
    void moveToNearestRailroad();
    void moveToNearestUtility();
    void moveBack3Spaces();
    void sendToJail();



};


#endif // PLAYER_H
