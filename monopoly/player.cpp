#include "player.h"
#include "square.h"
#include "card.h"


using namespace std;

Player::Player(QString name, Square *currentSquare, int money, QString counter)
{
    this->name = name;
    this->currentSquare = currentSquare;
    this->money = money;
    this->counter = QImage(counter);
    inJail = false;
    hasTurn = false;
    pauseTurn = false;
    dice = new Dice();
}

void Player::makeOffer(Offer *offer)
{

}

bool Player::hasSet()
{

}

int Player::propertiesInSetOwned(const QString setName)
{
    int counter = 0;
    for(int i=0; i<properties.size(); i++)
    {
        if(properties.at(i)->getSet() == setName)
        {
            counter ++;
        }
    }
    return counter;
}



void Player::confirmHousePurchases()
{
    currentPurchases.makePurchases();
}



int Player::getMoney()
{
    return money;
}

void Player::createDebt(int amount, Player *player)
{
    if(money >= amount)
    {
        makePayment(amount);
        player->receivePayment(amount);

    }
    else
    {
        pauseTurn = true;
        debt = amount;
        creditor = player;
    }
}



void Player::createDebt(int amount)
{
    if(money >= amount)
    {
        makePayment(amount);

    }
    else
    {
        debt = amount;
        creditor = NULL;
        pauseTurn = true;
    }
}

void Player::acquireGojfc(Card *card)
{
    gojfc.push_back(card);
}

void Player::useGojfc(CardStack *stack)
{
    Card *card = gojfc.at(0);
    gojfc.erase(gojfc.begin());
    stack->useGojfc(card);

}

void Player::makePayment(int amount){ money -= amount; }

void Player::receivePayment(int amount){ money += amount; }

int Player::returnBuildingCount(bool isHotelCount=false)
{
    Street* strPtr;
    int counter = 0;
    int houses;
    for(int i=0; i<sizeof(properties); i++)
    {
        //get a Street pointer from the property pointer
        if(properties.at(i)->isStreet()){continue;} //railway or utility
        strPtr = static_cast<Street*>(properties.at(i));
        houses = strPtr->getHouseCount();
        if(!isHotelCount)
        {
            counter += houses;
        }
        else if(houses == 5)
        {
            counter += houses;
        }
    }
    return counter;
}

int Player::returnHotelCount()
{
    return returnBuildingCount(true);
}

int Player::returnHouseCount()
{
    returnBuildingCount();
}



void Player::move(Square *destination)
{
    //this is the main move function which will call moveForward successive times to simulate movement around the board
    while(! destination->isEqual(currentSquare)){ moveForward(); }
}

void Player::moveForward()
{

}



void Player::moveToNearestRailroad()
{
    //railroads exist at ids 5 15 25 and 35

}

void Player::moveToNearestUtility()
{
    //utilities exist at ids 12 and 28
}

void Player::moveBack3Spaces()
{

}

void Player::sendToJail()
{

}



Purchase::Purchase(Property *property)
{
    this->property = property;
    this->houseCount = 0;
}


Property* Purchase::getProperty()
{
    return property;
}

int Purchase::getHouseCount()
{
    return houseCount;
}

void Purchase::addHouse()
{
    houseCount++;
}

void Purchase::removeHouse()
{
    houseCount--;
}

void makePurchases()
{
    //pay for this
}

PurchaseTracker::PurchaseTracker()
{
    houses = 0;
}

void PurchaseTracker::addPurchase(Property* property)
{
    //check if purchase exists then increment its housecount

    currentPurchase = getPurchase(property);
    if(!currentPurchase)
    {
        currentPurchase = &Purchase(property);
        purchases.push_back(currentPurchase);
    }
    currentPurchase->addHouse();
    houses++;
}

void PurchaseTracker::removePurchase(Property* property)
{
    currentPurchase = getPurchase(property);
    currentPurchase->removeHouse();
    houses--;

}

void PurchaseTracker::cancelPurchases()
{
    purchases.clear();
}

Purchase* PurchaseTracker::getPurchase(Property *property)
{
    for(int i=0; i<sizeof(purchases); i++)
    {
        if(purchases.at(i)->getProperty() == property)
        {
            return purchases.at(i);
        }
    }
}

void PurchaseTracker::makePurchases()
{
    //add/remove houses deduct money from players account.
}

