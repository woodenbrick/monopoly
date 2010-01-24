#ifndef BOARD_H
#define BOARD_H

#include <QString>
#include <vector>
#include "square.h"
#include "card.h"
#include "player.h"

class Board
{
    std::vector<Square> square;
    CardStack *communityChest;
    CardStack *chance;


public:
    std::vector<Player> players;
    Board(QString locale);
    Square getSquare(int id);
    HouseSet getSet(int id);
    HouseSet getSet(Property property);
    std::vector<Player> *returnOtherPlayers(Player *player);
};


#endif // BOARD_H
