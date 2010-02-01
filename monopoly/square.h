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
    bool isEqual(Square* otherSquare);
    void setOthersInSet(HouseSet* houseSet);
    virtual int getHouseCount();

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
    int houses;
    int houseCost;
    HouseSet *othersInSet;

public:
    Street(int id, QString &name, int purchasePrice, QString &set, std::vector <int> &rent);
    bool buyHouses(int amount);
    void sellHouses(int amount);
    int getHouseCount();
    int returnRent();
    HouseSet* getOthersInSet();
};

class HouseSet
{
    std::vector<Street*> propSet;
    friend class Street;

public:
    HouseSet(std::vector<Square*> set);
    bool canAddHouse(Square *street);
    bool canRemoveHouse(Square *street);

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
