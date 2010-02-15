#include "board.h"
#include "stdio.h"
#include "printf.h"
#include <stdio.h>
#include <iostream>
//    std::vector<Square> square;
//    CardStack *communityChest;
//   CardStack *chance;
//std::vector<Player> players;


Settings::Settings(int cash, int goMoney, int superTax, QString currencySymbol)
{
    this->cash = cash;
    this->goMoney = goMoney;
    this->superTax = superTax;
    this->currencySymbol = currencySymbol;
    std::cout << "Settings:\n" << "Starting cash: " << cash << "\nGo Money: "
            << goMoney << "\nSuper tax: " << superTax << "\nCurrency symbol: "
            << currencySymbol.toStdString() << std::endl;
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

Board::Board(QString locale, std::vector<std::vector<QString> > namesAndImages)
{
    QString database = "resources/db/";
    database.append(locale).append(".sqlite");
    std::string db = std::string(database.toLatin1());
    if(conn.Open(db))
    {
        std::cout << "database loaded" << std::endl;
    }
    else
    {
        std::cout << "Couldn't load database: " << std::endl;
    }
    statement = conn.Statement("select cash, go, super, currency from settings");
    statement->NextRow();
    QString currency = statement->ValueQString(3);
    settings = new Settings(statement->ValueInt(0), statement->ValueInt(1), statement->ValueInt(2), currency);
    squareFactory();
    communityChest = createCardStack("community_chest");
    chance = createCardStack("chance");
    //get Go square for players to start on
    Square* go = getSquare(0);
    std::vector<std::vector<QString> >::iterator it;
    Player* playerPtr;
    for(it = namesAndImages.begin(); it < namesAndImages.end(); it++)
        playerPtr = new Player(QString("Daniel"), go, settings->getCash(), QString("Hat.png"));
        players.push_back(playerPtr);


}

CardStack *Board::createCardStack(std::string type)
{
    CardStack *stack = new CardStack;
    if(type == "chance"){ statement = conn.Statement("select id, text, isGojfc, streetRepairs, money, playerTrans, square from chance");}
    else{statement = conn.Statement("select id, text, isGojfc, streetRepairs, money, playerTrans, square from community_chest");}
    while (statement->NextRow())
    {
        Card *card = new Card(statement->ValueInt(0), statement->ValueQString(1),
                              statement->ValueBool(2), statement->ValueInt(3),
                              statement->ValueInt(4), statement->ValueBool(5),
                              statement->ValueInt(6));
        stack->addToStack(card);
        //if the card requires movement, set the destination square
        if(statement->ValueInt(6) >= 0)
        {
            card->setDestinationSquare(getSquare(statement->ValueInt(6)));
        }

    }
    return stack;

}

void Board::squareFactory()
{
    statement = conn.Statement(
            "select id, name, price, _set, street.rent, street.one, street.two, street.three, street.four, "
            "street.five from squares LEFT OUTER JOIN street ON squares.id = street.square_id");
    Square* sqrPtr;
    Street* ptyPtr;
    std::vector<int> rents;
    //_set is one of None|B|LB|P|O|R|Y|G|DB|RR|UT
    while(statement->NextRow())
    {
        QString name = QString(statement->ValueString(1).c_str());
        QString set = QString(statement->ValueString(3).c_str());
        if(statement->ValueString(2) == "None")
        {
            sqrPtr = new Square(statement->ValueInt(0), name, set);
        }

        else if(statement->ValueString(2) == "RR")
        {
            sqrPtr = new Railway(statement->ValueInt(0), name, statement->ValueInt(2),
                              set, statement->ValueInt(4));
        }
        else if(statement->ValueString(2) == "UT")
        {
            sqrPtr = new Utility(statement->ValueInt(0), name, statement->ValueInt(2),
                               set, statement->ValueInt(4));
        }
        else
        {
             rents.clear();
             for(int i=4; i<10; i++)
             {
                 rents.push_back(statement->ValueInt(i));;
             }
             sqrPtr = new Street(statement->ValueInt(0), name, statement->ValueInt(2),
                                set, rents);
             ptyPtr = static_cast<Street*>(sqrPtr);
             streets.push_back(ptyPtr);
        }
        squares.push_back(sqrPtr);
    }
    //give references to each street about other houses in its set
    for(int i=0; i<streets.size(); i++)
    {
        if(streets.at(i)->isStreet())
        {
            streets.at(i)->setOthersInSet(getSet(streets.at(i)));
        }
    }
    //give references to each player about the other players

}

Square* Board::getSquare(int id)
{
    return squares.at(id);
}

HouseSet* Board::getSet(Street *thisStreet)
{
    HouseSet* houseset;
    std::vector<Street *> streetList;
    for(int i=0; i<streets.size(); i++)
    {
        if(streets.at(i)->getSet() == thisStreet->getSet() &&
           ! thisStreet->isEqual(streets.at(i)))
        {
            streetList.push_back(streets.at(i));
        }
    }
    houseset = new HouseSet(streetList);
    return houseset;

}

std::vector<Player*>* Board::getOtherPlayers(Player *player)
{
    std::vector<Player*> *otherPlayers;
    for(int i=0; i<players.size(); i++)
    {
        if(&players.at(i) != &player)
        {
            otherPlayers->push_back(players.at(i));
        }
    }
    return otherPlayers;

}
