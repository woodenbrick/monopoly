#include "board.h"


//    std::vector<Square> square;
//    CardStack *communityChest;
//   CardStack *chance;
//std::vector<Player> players;


Board::Board(QString locale)
{
    conn.Open("resources/db/" + locale + ".sqlite");
    communityChest = createCardStack("community_chest");
    chance = createCardStack("chance");
    squares = createSquares();

}

CardStack *Board::createCardStack(QString type)
{
    CardStack stack;
    statement = conn.Statement("select * from ?");
    statement->Bind(type);
    while (statement->NextRow())
    {
        Card card = Card(statement->ValueInt(0), statement->ValueString(1), statement->ValueInt(2),
                         statement->ValueInt(3), statement->ValueInt(4), statement->ValueInt(5), statement->ValueInt(6));
        stack.addToStack(card);
    }
    return * stack;

}

std::vector <Square> *Board::createSquares()
{
    // unfinished
    statement = conn.Statement("select * from squares");

}

Square Board::getSquare(int id)
{

}

HouseSet Board::getSet(int id)
{

}

HouseSet Board::getSet(Property property)
{

}

std::vector<Player> *returnOtherPlayers(Player *player)
{

}
