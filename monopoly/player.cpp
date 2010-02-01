#include "player.h"
#include "square.h"
#include "card.h"


using namespace std;

Player::Player(QString name, Square &currentSquare, int money, QString counter)
{
    this->name = name;
    this->currentSquare = &currentSquare;
    this->money = money;
    this->counter = QImage(counter);
    inJail = false;
    hasTurn = false;
    pauseTurn = false;
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



//int Player::returnHouseCount()
//{
//    int counter;
//    int i;
//    vector<Square*>::iterator propIter;
//    for(propIter = properties.begin(); propIter < properties.end(); propIter++)
//    {
//        i = *propIter->getHouseCount();
//        if ( i < 5)
//        {
//            counter += i;
//        }
//    }
//    return counter;
//}

//int Player::returnHotelCount()
//{
//    int counter;
//    vector<Square>::iterator propIter;
//    for(propIter = properties.begin(); propIter < properties.end(); propIter++)
//    {
//        if (*propIter.houses == 5)
//        {
//            counter += 5;
//        }
//    }
//    return counter;
//}

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


