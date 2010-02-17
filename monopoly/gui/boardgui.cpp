#include "boardgui.h"

BoardGui::BoardGui(QString locale, QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    QPixmap bpic(QString(":/images/locale/%1/board.png").arg(locale));
    this->board_pic->setPixmap(bpic);
    board_pic->show();
}
