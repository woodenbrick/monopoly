#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "ui_board.h"

class BoardGui : public QMainWindow, public Ui::Board
{
    Q_OBJECT

public:
    BoardGui(QString locale, QWidget* parent=0);
};

#endif // BOARDGUI_H
