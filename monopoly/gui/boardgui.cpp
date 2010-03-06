#include "boardgui.h"
#include "board.h"
BoardGui::BoardGui(QString locale, BoardData* board, QWidget *parent) :
        QMainWindow(parent)
{
    setupUi(this);
    boardPtr = board;
    QPixmap bpic(QString(":/images/locale/%1/board.png").arg(locale));
    this->board_pic->setPixmap(bpic);
    board_pic->show();
    PropertyImage img(":/images/TitleDeedTemp.png");
    currentProperty->setPixmap(img);
    //board_pic->setMouseTracking(true);
    currentProperty->setAutoFillBackground(true);
    currentProperty->setPalette(QPalette(QColor("black")));


}

void BoardGui::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->pos();
    Square* square = boardPtr->getSquare(1);
    square->getName();
currentProperty->setPalette(QPalette(QColor("blue")));


}


PropertyImage::PropertyImage(QString filename) : QPixmap(filename)
{

}



void PropertyImage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    qDebug() << "running painter";
    painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    painter.drawRect(0, 0, 100, 30);
    painter.end();
}
