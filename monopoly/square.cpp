#include "square.h"
#include "player.h"

Square::Square(int &id, QString &name, QString &set)
{
    this->id = id;
    this->name = name;
    this->set = set;

}

int Square::getId()
{
    return id;
}

QString Square::getName()
{
    return name;
}

bool Square::isStreet()
{
    if(set == "None") return False;
    if(set == "RR") return False;
    if(set == "UT") return False;
    return true;
}

bool Square::isEqual(Square *otherSquare)
{
    //return true if these squares refer to the same object
    return true;
}


Property::Property(int &id, QString &name, int &purchasePrice, QString &set) : Square(id, name, set)
{
    this->purchasePrice = purchasePrice;
}


bool Property::purchase(Player *purchaser)
{
    if(purchaser->getMoney() >= purchasePrice)
    {
        purchaser->makePayment(purchasePrice);
        owner = purchaser;
        return true;
    }
    return false;
}


void Property::mortgage()
{

    owner->receivePayment(purchasePrice / 2);
    isMortgaged = true;
}


bool Property::unmortgage()
{
    if(owner->getMoney() >= purchasePrice / 2)
    {
        owner->makePayment(purchasePrice / 2);
        isMortgaged = false;
        return true;
    }
    return false;
}




Street::Street(int id, QString &name, int purchasePrice, QString &set, std::vector <int> &rent)
    : Property(id, name, purchasePrice, set)
{
    //this->rent[0] = rent;
    this->rent = rent;
    //this->rent[5] = rent;
}


bool Street::buyHouses(int amount)
{
    owner->makePayment(houseCost * amount);
    houses += amount;
    return true;

}


void Street::sellHouses(int amount)
{
    owner->receivePayment(houseCost / 2 * amount);
    houses -= amount;
}


int Street::returnRent()
{
    if(owner->hasSet())
    {
        if(houses == 0)
        {
            return rent[0] * 2;
        }
        else
        {
            return rent[houses];
        }
    }
    else
    {
        return rent[0];
    }
}




HouseSet::HouseSet(std::vector<Square> set)
{
    propSet = set;
}


bool HouseSet::canAddHouse(Square *street)
{
    //check that other properties have equal or 1 more house

    for(int i=0; i <=propSet.size(); i++)
    {
        if(propSet.at(i).houses < street->houses || propSet.at(i).houses > street->houses + 1)
        {
            return false;
        }
    }
    //check owner has money
    if(! street->owner->getMoney() >= street->houseCost)
    {
        return false;
    }
    return true;

}


bool HouseSet::canRemoveHouse(Square *street)
{
    //check that other properties have equal or 1 less house
    for(int i=0; i <=propSet.size(); i++)
    {
        if(propSet.at(i).houses > street->houses || propSet.at(i).houses < street->houses - 1)
        {
            return false;
        }
    }
    return true;
}




Railway::Railway(int id, QString name, int purchasePrice, QString set, int rent)
        : Property(id, name, purchasePrice, set)
{
    this->rent = rent;
    multiplier.push_back(1);
    multiplier.push_back(2);
    multiplier.push_back(4);
    multiplier.push_back(8);

}


int Railway::returnRent()
{
    return 25 * multiplier.at(owner->propertiesInSetOwned(this) - 1);
}




Utility::Utility(int id, QString name, int purchasePrice, QString set, int rent) :
        Property(id, name, purchasePrice, set)
{
    this->rent = rent;
}


int Utility::returnRent(int lastRoll)
{
    if(owner->propertiesInSetOwned(this) == 1)
    {
        multiplier = 4;
    }
    else
    {
        multiplier = 10;
    }
    return rent * multiplier;

}



