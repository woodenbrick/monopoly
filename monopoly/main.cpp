#include "gui/ui_board.h"
#include <QApplication>
#include "player.h"
#include "card.h"
#include "square.h"
#include "board.h"
#include <vector>
#include <iostream>
int main(int argc, char *argv[])
{
    //variables that should be built on the fly
    //we will hard code them here for testing purposes
    QString locale = "UK";

    QApplication app(argc, argv);
    QMainWindow* win = new QMainWindow();
    Ui::MainWindow gui;
    gui.setupUi(win);
    win->show();
    std::vector<std::vector<QString> > players;
    std::vector<QString> player;
    player.push_back("Daniel");
    player.push_back("Hat");
    players.push_back(player);
    player.clear();
    player.push_back("Lewis");
    player.push_back("Dog");
    Board *board = new Board(locale, players);
    QPixmap bpic(":/images/locale/UK/board.png");
    gui.board_pic->setPixmap(bpic);
    gui.board_pic->show();
    int total = board->getCurrentPlayer()->dice->roll();
    std::cout << total;
    std::cout << board->getCurrentPlayer()->dice->getLastRollString().toStdString();
    return app.exec();
}
