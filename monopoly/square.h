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



class Property : Square
{
    int purchasePrice;
    Player owner;
    bool isMortgaged;
    QString set;

public:
    purchase(Player player);
    void mortgage();
    void unmortgage();

};


class Street : Property
{
    int baseRent;
    int rent1;
    int rent2;
    int rent3;
    int rent4;
    int rent5;
    int houses;

public:
    void buyHouses(int amount);
    void sellHouses(int amount);
    int returnRent();
};

class Railway : Property
{
public:
    int returnRent();
};


class Utility : Property
{
public:
    int returnRent(int lastRoll);
};

#endif // SQUARE_H
