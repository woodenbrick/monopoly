#include "boardgui.h"
#include "board.h"
BoardGui::BoardGui(QString locale, BoardData* board, QWidget *parent) :
        QMainWindow(parent)
{
    setupUi(this);
    i=0;
    boardPtr = board;
    QPixmap bpic(QString(":/images/locale/%1/board.png").arg(locale));
    this->board_pic->setPixmap(bpic.scaled(QSize(700, 700)));
    board_pic->show();
    currentPropertyPic->setAutoFillBackground(true);
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(updateCard()));

}

void BoardGui::mouseMoveEvent(QMouseEvent *event)
{
    //nothing

}

void BoardGui::updateCard()
{
    Square* square = boardPtr->getSquare(i);
    currentPropertyPic->setPixmap(square->getPixmap());
    QPalette palette(square->getBackgroundColor());
    currentPropertyPic->setPalette(palette);
    currentPropertyName->setText(square->getName());
    currentPropertyName->setPalette(palette);
    currentPropertyText->setText(square->printDetails());
    i++;
    if(i==40) i = 0;
}
