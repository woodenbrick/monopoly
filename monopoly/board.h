#ifndef BOARD_H
#define BOARD_H

#include <QString>
#include "square.h"
#include "card.h"
#include "player.h"

class Board
{
    Square *square[];
    CardStack *communityChest;
    CardStack *chance;
    Player *players[];

public:
    Board(QString locale);
    Square getSquare(int id);
    Set getSet(int id);
    Set getSet(Property property);
};


#endif // BOARD_H
