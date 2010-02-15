#include "gui/playerframe.h"
#include <QApplication>
#include "player.h"
#include "card.h"
#include "square.h"
#include "board.h"
#include <vector>
#include <iostream>
int main(int argc, char *argv[])
{
//    QApplication app(argc, argv);
//    QMainWindow *win = new QMainWindow();
//    PlayerFrame::PlayerFrame *player = new PlayerFrame(win, "Daniel");
//    win->show();
//    return app.exec();
    std::vector<std::vector<QString> > players;
    std::vector<QString> player;
    player.push_back("Daniel");
    player.push_back("Hat");
    players.push_back(player);
    player.clear();
    player.push_back("Lewis");
    player.push_back("Dog");
    Board *board = new Board("UK", players);
    int total = board->getCurrentPlayer()->dice->roll();
    std::cout << total;
    std::cout << board->getCurrentPlayer()->dice->getLastRollString().toStdString();
}
