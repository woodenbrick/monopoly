#include "board.h"
#include "stdio.h"
#include "printf.h"

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
}

Board::Board(QString locale, std::vector<std::vector<QString> > namesAndImages)
{
    QString database = "resources/db/";
    database.append(locale).append(".sqlite");
    std::string db = std::string(database.toLatin1());
    conn.Open(db);
    statement = conn.Statement("select cash, go, super, currency from settings");
    QString currency(statement->ValueString(3).c_str());
    settings = new Settings(statement->ValueInt(0), statement->ValueInt(1), statement->ValueInt(2), currency);
    communityChest = createCardStack("community_chest");
    chance = createCardStack("chance");
    squareFactory();

    //get Go square for players to start on
    Square &go = getSquare(0);
    std::vector<std::vector<QString> >::iterator it;
    Player * playerPtr;
    for(it = namesAndImages.begin(); it < namesAndImages.end(); it++)
        playerPtr = new Player(QString("Daniel"), go, settings->getCash(), QString("Hat.png"));
        players.push_back(playerPtr);


}

CardStack *Board::createCardStack(QString type)
{
    CardStack *stack = new CardStack;
    bool pl, goj;
    statement = conn.Statement("select id, text, isGojfc, streetRepairs, money, playerTrans, square, from ?");
    std::string t = std::string(type.toLatin1());
    statement->Bind(0, t);
    while (statement->NextRow())
    {
        (statement->ValueInt(2) == 1) ? goj = true : goj = false;
        (statement->ValueInt(5) == 1) ? pl = true : pl = false;
        Card *card = new Card(statement->ValueInt(0), QString(statement->ValueString(1).c_str()), goj,
                         statement->ValueInt(3), statement->ValueInt(4), pl, statement->ValueInt(6));
        stack->addToStack(card);
    }
    return stack;

}

void Board::squareFactory()
{
    statement = conn.Statement(
            "select id, name, price, _set, street.rent, street.one, street.two, street.three, street.four, "
            "street.five from squares LEFT OUTER JOIN street ON squares.id = street.square_id");
    Square *sqrPtr;
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
        }
        squares.push_back(sqrPtr);
    }
    //give references to each street about other houses in its set
    for(int i=0; i<squares.size(); i++)
    {
        if(squares.at(i)->isStreet())
        {
            squares.at(i)->setOthersInSet(getSet(squares.at(i)));
        }
    }
    //give references to each player about the other players

}

Square& Board::getSquare(int id)
{
    return *squares.at(id);
//    std::vector<Square*>::iterator it;
//    for(it=squares.begin(); it<squares.end(); it++)
//    {
//        if(it->getId() == id)
//        {
//            return &it;
//        }
//    }
}

HouseSet* Board::getSet(Square* thisStreet)
{
    HouseSet* houseset;
    Street* otherStreet;
    std::vector<Street *> streetPtr;
    for(int i=0; i<squares.size(); i++)
    {
        if(squares.at(i)->getSet() == thisStreet->getSet() && ! thisStreet->isEqual(squares.at(i)))
        {
            //convert Square pointers to Street pointers
            otherStreet = static_cast<Street*>(squares.at(i));
            streetPtr.push_back(otherStreet);
        }
    }
    houseset = new HouseSet(streetPtr);
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
