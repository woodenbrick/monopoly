#include "square.h"
#include "player.h"
#include "board.h"

Square::Square(int id, QString &name, QString &set)
{
    this->id = id;
    this->name = name;
    this->set = set;
    fgColor = QColor("black");
    bgColor = QColor("white");
    image = QPixmap(":/images/TitleDeedBackTemp.png");
}

int Square::getId()
{
    return id;
}

QString Square::getName()
{
    return name;
}

QString Square::getSet()
{
    return set;
}


bool Square::isStreet()
{
    if(set == "None") return false;
    if(set == "RR") return false;
    if(set == "UT") return false;
    return true;
}

bool Square::isEqual(Square *otherSquare)
{
    //XXX dummy return
    //true if these squares refer to the same object
    return true;
}

Street* Square::toStreet()
{
    return static_cast<Street*>(this);
}

QColor Square::getBackgroundColor()
{
    return bgColor;
}

QColor Square::getForegroundColor()
{
    return fgColor;
}

QPixmap Square::getPixmap()
{
    return image;
}

QString Square::printDetails()
{
    return QString("");
}

Property::Property(int &id, QString &name, int &purchasePrice, QString &set, QString currency)
    : Square(id, name, set)
{
    this->purchasePrice = purchasePrice;
    this->currency = currency;
    image = QPixmap(":/images/TitleDeedTemp.png");

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




Street::Street(int id, QString &name, int purchasePrice, QString &set, QString currency,
               QList <int> &rent, QString bgColor, QString fgColor)
    : Property(id, name, purchasePrice, set, currency)
{
    this->rent = rent;
    this->fgColor = QColor("#" + fgColor);
    this->bgColor = QColor("#" + bgColor);
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

int Street::getHouseCount()
{
    return houses;
}

int Street::getHouseCost()
{
    return houseCost;
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

void Street::setOthersInSet(HouseSet *houseset)
{
    othersInSet = houseset;
}

QString Street::printDetails()
{
    QString s;
    s= QString(
            "Rent:\t%1\n"
              "1 House:\t%2\n"
              "2 Houses:\t%3\n"
              "3 Houses:\t%4\n"
              "4 Houses:\t%5\n"
              "Hotel:\t%6\n");
    for(QList<int>::const_iterator iter = rent.begin(); iter != rent.end(); iter++)
    {
        s = s.arg(currency + QString::number(*iter));
    }
    return s;
}

HouseSet::HouseSet(QList<Street*> set)
{
    propSet = set;
}


bool HouseSet::canAddHouse(Street *street)
{
    //check that other properties have equal or 1 more house

    for(QList<Street*>::const_iterator iter=propSet.begin(); iter != propSet.end(); iter++)
    {
        if((*iter)->getHouseCount() < street->getHouseCount() ||
           (*iter)->getHouseCount() > street->getHouseCount() + 1)
        {
            return false;
        }
    }
    //check owner has money
    if(! street->owner->getMoney() >= street->getHouseCost())
    {
        return false;
    }
    return true;

}


bool HouseSet::canRemoveHouse(Street *street)
{
    //check that other properties have equal or 1 less house
    for(QList<Street*>::const_iterator iter=propSet.begin(); iter != propSet.end(); iter++)
    {
        if((*iter)->getHouseCount() > street->getHouseCount() ||
           (*iter)->getHouseCount() < street->getHouseCount() - 1)
        {
            return false;
        }
    }
    return true;
}




Railway::Railway(int id, QString name, int purchasePrice, QString set, QString currency, int rent)
        : Property(id, name, purchasePrice, set, currency)
{
    this->rent = rent;
    multiplier.push_back(1);
    multiplier.push_back(2);
    multiplier.push_back(4);
    multiplier.push_back(8);

}


int Railway::returnRent()
{
    return 25 * multiplier.at(owner->propertiesInSetOwned(getSet()) - 1);
}

QString Railway::printDetails()
{
    QString s;
    s = QString(
              "1 Station:\t%1\n"
              "2 Stations:\t%2\n"
              "3 Stations:\t%3\n"
              "4 Stations:\t%4\n");
    for(QList<int>::const_iterator iter = multiplier.begin(); iter != multiplier.end(); iter++)
    {
        s = s.arg(currency + QString::number(25 * (*iter)));
    }
    return s;
}


Utility::Utility(int id, QString name, int purchasePrice, QString set, QString currency, int rent) :
        Property(id, name, purchasePrice, set, currency)
{
    this->rent = rent;
}


int Utility::returnRent(int lastRoll)
{
    //XXX This assumes the multipler is 4 or 10, in newer version of the game
    //it may be 4000 or 10000
    if(owner->propertiesInSetOwned(getSet()) == 1)
    {
        multiplier = 4;
    }
    else
    {
        multiplier = 10;
    }
    return lastRoll * multiplier;

}

QString Utility::printDetails()
{
    QString s = QString("If one Utility is owned rent is 4 times the amount on the dice."
              "If both Utilities are owned rent is 10 times the amount on the dice."
              "Mortgage Value: %1").arg(QString::number(this->purchasePrice / 2));
    return s;
}

