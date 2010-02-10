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
    std::vector<Player*> players;
    CardStack *communityChest;
    CardStack *chance;
    SQLiteWrapper conn;
    SQLiteStatement *statement;
    Settings *settings;


public:
    CardStack *createCardStack(QString type);
    Board(QString locale, std::vector<std::vector<QString> > namesAndImages);
    Square* getSquare(int id);
    HouseSet* getSet(Square *thisStreet);
    void squareFactory();
    std::vector<Player*>* getOtherPlayers(Player *player);
};


#endif // BOARD_H
