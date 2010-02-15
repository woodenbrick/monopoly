#ifndef BOARD_H
#define BOARD_H

#include <QString>
#include <vector>
#include "square.h"
#include "card.h"
#include "player.h"
#include "lib/sqlitewrapper.h"

class Settings
{
    int cash;
    int goMoney; //also income tax
    int superTax;
    QString currencySymbol;

public:
    Settings(int cash, int goMoney, int superTax, QString currencySymbol);
    int getCash();
    int getGoMoney();
    int getSuperTax();
    QString getCurrencySymbol();
};

class Board
{
    std::vector<Square*> squares;
    std::vector<Street*> streets;
    std::vector<Player*> players;
    int turn; //keeps track of whose turn it is
    CardStack *communityChest;
    CardStack *chance;
    SQLiteWrapper conn;
    SQLiteStatement *statement;
    Settings *settings;


public:
    CardStack *createCardStack(std::string type);
    Board(QString locale, std::vector<std::vector<QString> > namesAndImages);
    Square* getSquare(int id);
    HouseSet* getSet(Street *thisStreet);
    void squareFactory();
    Player* getCurrentPlayer();
    Player* nextPlayer();
    std::vector<Player*>* getOtherPlayers(Player *player);
};


#endif // BOARD_H
