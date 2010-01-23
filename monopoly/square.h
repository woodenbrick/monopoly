#ifndef SQUARE_H
#define SQUARE_H

#include <QString>
#include "player.h"

class Square
{
    int id;
    QString name;

public:
    Square(int id, QString name);

};


class Set
{
    Property *set[];
};

class Property : public Square
{
    int purchasePrice;
    Player *owner;
    bool isMortgaged;
    QString set;

public:
    Property(int purchasePrice, QString set);
    bool purchase(Player *player);
    void mortgage();
    bool unmortgage();

};



class Street : public Property
{
    int *rent[];
    int houseCost;
    int houses;

public:
    Street(int rent[]);
    bool buyHouses(int amount);
    void sellHouses(int amount);
    int returnRent();
};

class HouseSet
{
    Street *set[];

public:
    HouseSet(Street *set[]);
    bool canAddHouse(Street *street);
    bool canRemoveHouse(Street *street);

};

class Railway : public Property
{
    int rent;
    int multiplier[];
public:
    Railway(int rent);
    int returnRent();
};


class Utility : public Property
{
    int rent;

public:
    Utility(int rent);
    int returnRent(int lastRoll);
};

#endif // SQUARE_H