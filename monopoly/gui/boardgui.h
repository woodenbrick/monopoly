#ifndef BOARDGUI_H
#define BOARDGUI_H

#include "ui_board.h"
#include "board.h"
#include <QDebug>
#include <QMouseEvent>
class BoardGui : public QMainWindow, public Ui::Board
{
    Q_OBJECT
private:
    BoardData* boardPtr;
public:
    BoardGui(QString locale, BoardData* board, QWidget* parent=0);
    void mouseMoveEvent(QMouseEvent* event);

};


class PropertyImage : public QPixmap
{
public:
    PropertyImage(QString filename);
    void paintEvent(QPaintEvent *event);
};

#endif // BOARDGUI_H
