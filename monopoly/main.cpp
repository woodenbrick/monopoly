#include <QApplication>
#include <vector>
#include <iostream>

#include "player.h"
#include "card.h"
#include "square.h"
#include "board.h"
#include "gui/lobby.h"
#include "gui/boardgui.h"

int main(int argc, char* argv[])
{
    //variables that should be built on the fly
    //we will hard code them here for testing purposes
    QApplication app(argc, argv);
    QString locale = "UK";



    std::vector<std::vector<QString> > players;
    std::vector<QString> player;
    player.push_back("Daniel");
    player.push_back("Hat");
    players.push_back(player);
    player.clear();
    player.push_back("Lewis");
    player.push_back("Dog");
    BoardData *board = new BoardData(locale, players);

    //create windows
    BoardGui *boardgui = new BoardGui(locale, board);
    boardgui->show();

    //Lobby *lobby= new Lobby;
    //lobby->show();
    //int total = board->getCurrentPlayer()->dice->roll();
    //std::cout << total;
    //std::cout << board->getCurrentPlayer()->dice->getLastRollString().toStdString();
    return app.exec();
}
