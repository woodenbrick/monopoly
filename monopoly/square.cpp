#include "square.h"

Square::Square(int id, QString name)
{
    this->id = id;
    this->name = name;

}




Property::Property(int id, QString name, int purchasePrice, QString set) : Square(id, name)
{
    this->purchasePrice = purchasePrice;
    this->set = set;
}


bool Property::purchase(Player *purchaser)
{
    if(purchaser->money >= purchasePrice)
    {
        purchaser->money -= purchasePrice;
        owner = purchaser;
        return true;
    }
    return false;
}


bool Property::mortgage()
{

    owner->money += purchasePrice / 2;
    isMortgaged = true;
}


bool Property::unmortgage()
{
    if(owner->money >= purchasePrice / 2)
    {
        owner->money -= purchasePrice / 2;
        isMortgaged = false;
        return true;
    }
    return false;
}




Street::Street(int id, QString name, int purchasePrice, QString set, int *rent[]) : Property(purchasePrice, set),
Square(id, name)
{
    this->rent = rent;
}


bool Street::buyHouses(int amount)
{
    owner->money -= houseCost * amount;
    houses += amount;
}


void Street::sellHouses(int amount)
{
    owner->money += houseCost / 2 * amount;
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




HouseSet::HouseSet(Street *set[])
{
    this->set = set;
}


bool HouseSet::canAddHouse(Street *street)
{
    //check that other properties have equal or 1 more house
    for(int i=0; i <=sizeof(set); i++)
    {
        if(set[i]->houses < street->houses || set[i]->houses > street->houses + 1)
        {
            return false;
        }
    }
    //check owner has money
    if(! street->owner->money >= street->houseCost)
    {
        return false;
    }
    return true;

}


bool HouseSet::canRemoveHouse(Street *street)
{
    //check that other properties have equal or 1 less house
    for(int i=0; i <=sizeof(set); i++)
    {
        if(set[i]->houses > street->houses || set[i]->houses < street->houses - 1)
        {
            return false;
        }
    }
    return true;
}




Railway::Railway(int id, QString name, int purchasePrice, QString set, int rent) : Property(purchasePrice, set),
Square(id, name)
{
    this->rent = rent;
    multiplier = [1, 2, 4, 8];
}


int Railway::returnRent()
{
    return 25 * multiplier[owner->propertiesInSetOwned(this) - 1];
}




Utility::Utility(int id, QString name, int purchasePrice, QString set, int rent) : Property(purchasePrice, set),
Square(id, name)
{
    this->rent = rent;
}


int Utility::returnRent(int lastRoll)
{
    if(owner->propertiesInSetOwned(this) == 1)
    {
        multipler = 4;
    }
    else
    {
        multipler = 10;
    }
    return rent * multipler;

}



