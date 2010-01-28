#ifndef BOARD_H
#define BOARD_H

#include <QString>
#include <vector>
#include "square.h"
#include "card.h"
#include "player.h"
#include "lib/sqlitewrapper.h"

class Board
{
    std::vector<Square> square;
    CardStack *communityChest;
    CardStack *chance;
    SQLiteWrapper conn;
    SQLiteStatement *statement;


public:
    std::vector<Player> players;
    CardStack *createCardStack(QString type);
    Board(QString locale);
    Square getSquare(int id);
    HouseSet getSet(int id);
    HouseSet getSet(Property property);
    std::vector<Player> *returnOtherPlayers(Player *player);
};


#endif // BOARD_H
