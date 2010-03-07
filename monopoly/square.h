#ifndef SQUARE_H
#define SQUARE_H

#include <QString>
#include <QColor>
#include <QPixmap>
#include <QList>

class Player;
class Street;
class HouseSet;

class Square
{
protected:
    int id;
    QString name;
    QString set;
    QPixmap image;
    QColor bgColor;
    QColor fgColor;

public:
    Square(int id, QString &name, QString &set);
    int getId();
    QString getName();
    QString getSet();
    Street* toStreet();
    QPixmap getPixmap();
    bool isStreet();
    bool isEqual(Square* otherSquare);
    QColor getBackgroundColor();
    QColor getForegroundColor();
    virtual QString printDetails();

};


class Property : public Square
{
protected:
    int purchasePrice;
    bool isMortgaged;
    QString currency;

public:
    Property(int &id, QString &name, int &purchasePrice, QString &set, QString currency);
    Player *owner;
    bool purchase(Player *player);
    void mortgage();
    bool unmortgage();
};

class HouseSet;

class Street : public Property
{
protected:
    QList <int> rent;
    int houses;
    int houseCost;
    HouseSet *othersInSet;

public:
    Street(int id, QString &name, int purchasePrice, QString &set,
           QString currency, QList <int> &rent, QString bgcolor, QString fgcolor);
    bool buyHouses(int amount);
    void sellHouses(int amount);
    int getHouseCount();
    int getHouseCost();
    int returnRent();
    HouseSet* getOthersInSet();
    void setOthersInSet(HouseSet *houseSet);
    QString printDetails();
};

class HouseSet
{
    QList<Street*> propSet;
    friend class Street;

public:
    HouseSet(QList<Street*> set);
    bool canAddHouse(Street *street);
    bool canRemoveHouse(Street *street);

};

class Railway : public Property
{
    int rent;
    QList<int> multiplier;
public:
    Railway(int id, QString name, int purchasePrice, QString set, QString currency, int rent);
    int returnRent();
    QString printDetails();
};


class Utility : public Property
{
    int rent;
    int multiplier;

public:
    Utility(int id, QString name, int purchasePrice, QString set, QString currency, int rent);
    int returnRent(int lastRoll);
    QString printDetails();
};

#endif // SQUARE_H
