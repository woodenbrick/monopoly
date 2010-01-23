#include "gui/playerframe.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow *win = new QMainWindow();
    PlayerFrame::PlayerFrame *player = new PlayerFrame(win, "Daniel");
    win->show();
    return app.exec();
}
