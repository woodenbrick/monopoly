#ifndef SQUARE_H
#define SQUARE_H

#include <QString>
#include <vector>

class Player;
class HouseSet;

class Square
{
protected:
    int id;
    QString name;
    QString set;

public:
    Square(int id, QString &name, QString &set);
    int getId();
    QString getName();
    QString getSet();
    bool isStreet();
    void setOthersInSet(HouseSet* houseSet);

};


class Property : public Square
{
protected:
    int purchasePrice;
    bool isMortgaged;

public:
    Property(int &id, QString &name, int &purchasePrice, QString &set);
    Player *owner;
    bool purchase(Player *player);
    //Player *getOwner();
    void mortgage();
    bool unmortgage();
};

class HouseSet;

class Street : public Property
{
protected:
    std::vector <int> rent;
    int houseCost;
    HouseSet *othersInSet;

public:
    int houses;
    Street(int id, QString &name, int purchasePrice, QString &set, std::vector <int> &rent);
    bool buyHouses(int amount);
    void sellHouses(int amount);
    int returnRent();
    HouseSet* getOthersInSet();
};

class HouseSet
{
    std::vector<Street*> propSet;
    friend class Street;

public:
    HouseSet(std::vector<Street*> set);
    bool canAddHouse(Street *street);
    bool canRemoveHouse(Street *street);

};

class Railway : public Property
{
    int rent;
    std::vector<int> multiplier;
public:
    Railway(int id, QString name, int purchasePrice, QString set, int rent);
    int returnRent();
};


class Utility : public Property
{
    int rent;
    int multiplier;

public:
    Utility(int id, QString name, int purchasePrice, QString set, int rent);
    int returnRent(int lastRoll);
};

#endif // SQUARE_H
