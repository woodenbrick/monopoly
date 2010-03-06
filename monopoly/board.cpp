#include "board.h"
#include "stdio.h"
#include <stdio.h>
#include <iostream>


Settings::Settings(int cash, int goMoney, int superTax, QString currencySymbol)
{
    this->cash = cash;
    this->goMoney = goMoney;
    this->superTax = superTax;
    this->currencySymbol = currencySymbol;
}

int Settings::getCash()
{
    return cash;
}

int Settings::getGoMoney()
{
    return goMoney;
}

QString Settings::getCurrencySymbol()
{
    return currencySymbol;
}

int Settings::getSuperTax()
{
    return superTax;
}

BoardData::BoardData(QString locale, std::vector<std::vector<QString> > namesAndImages)
{
    QString database("resources/db/");
    database.append(locale).append(".sqlite");
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(database);
    conn.open();
    QSqlQuery query;
    query.exec("select cash, go, super, currency from settings");
    query.next();
    settings = new Settings(query.value(0).toInt(), query.value(1).toInt(),
                            query.value(2).toInt(), query.value(3).toString());
    squareFactory();
    communityChest = createCardStack(QString("community_chest"));
    chance = createCardStack(QString("chance"));
    conn.close();
    conn.removeDatabase("QSQLITE");
    //get Go square for players to start on
    Square* go = getSquare(0);
    std::vector<std::vector<QString> >::iterator it;
    Player* playerPtr;
    for(it = namesAndImages.begin(); it < namesAndImages.end(); it++)
        playerPtr = new Player(QString("Daniel"), go, settings->getCash(), QString("Hat.png"));
        players.push_back(playerPtr);
    turn = players.begin();


}

CardStack *BoardData::createCardStack(QString type)
{
    CardStack *stack = new CardStack;
    QSqlQuery query;
    query.prepare("select id, text, isGojfc, streetRepairs, money, playerTrans, square from ?");
    query.bindValue(0, type);
    query.exec();
    while (query.next())
    {
        Card *card = new Card(query.value(0).toInt(), query.value(1).toString(),
                              query.value(2).toBool(), query.value(3).toInt(),
                              query.value(4).toInt(), query.value(5).toBool(),
                              query.value(6).toInt());
        stack->addToStack(card);
        //if the card requires movement, set the destination square
        if(query.value(6).toInt() >= 0)
        {
            card->setDestinationSquare(getSquare(query.value(6).toInt()));
        }

    }
    stack->shuffle();
    return stack;

}

void BoardData::squareFactory()
{
    QSqlQuery query;
    query.exec(
            "select squares.id, squares.name, squares.price, squares._set, "
            "street.rent, street.one, street.two, street.three, street.four, "
            "street.five, property_colours.bgcolour, property_colours.fgcolour "
            "from squares LEFT OUTER JOIN street ON squares.id = street.square_id "
            "LEFT OUTER JOIN property_colours ON squares.id = property_colours.ID");
    Square* sqrPtr;
    Street* ptyPtr;
    std::vector<int> rents;
    //_set is one of None|B|LB|P|O|R|Y|G|DB|RR|UT
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString set = query.value(3).toString();
        if(set == "None")
        {
            sqrPtr = new Square(id, name, set);
        }
        else if(set == "RR")
        {
            sqrPtr = new Railway(id, name, query.value(2).toInt(),
                              set, query.value(4).toInt());
        }
        else if(set == "UT")
        {
            sqrPtr = new Utility(id, name, query.value(2).toInt(),
                               set, query.value(4).toInt());
        }
        else
        {
             rents.clear();
             for(int i=4; i<10; i++)
             {
                 rents.push_back(query.value(i).toInt());
             }
             sqrPtr = new Street(id, name, query.value(2).toInt(),
                                set, rents, query.value(10).toString(),
                                query.value(11).toString());
             ptyPtr = static_cast<Street*>(sqrPtr);
             streets.push_back(ptyPtr);
        }
        squares.push_back(sqrPtr);
    }
    //give references to each street about other houses in its set
    for(unsigned int i=0; i < streets.size(); i++)
    {
        streets.at(i)->setOthersInSet(getSet(streets.at(i)));
    }
    //XXX give references to each player about the other players

}

Square* BoardData::getSquare(int id)
{
    return squares.at(id);
}

HouseSet* BoardData::getSet(Street *thisStreet)
{
    HouseSet* houseset;
    std::vector<Street *> streetList;
    for(unsigned int i=0; i < streets.size(); i++)
    {
        if(streets.at(i)->getSet() == thisStreet->getSet() &&
            thisStreet != streets.at(i))
        {
            streetList.push_back(streets.at(i));
        }
    }
    houseset = new HouseSet(streetList);
    return houseset;

}


Player* BoardData::getCurrentPlayer()
{
    return *turn;
}

Player* BoardData::nextPlayer()
{
    turn++;
    if(turn == players.end())
    {
        turn = players.begin();
    }
    return getCurrentPlayer();
}

std::vector<Player*>* BoardData::getOtherPlayers(Player *player)
{
    std::vector<Player*> *otherPlayers;
    for(std::vector<Player*>::iterator iter=players.begin(); iter != players.end(); iter++)
    {
        if(*(*iter) != *player)
        {
            otherPlayers->push_back(player);
        }
    }
    return otherPlayers;

}
