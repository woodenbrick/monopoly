#include "playerframe.h"
#include <QtGui>

PlayerFrame::PlayerFrame(QMainWindow *parent, QString name) : QGroupBox(parent)
{
    setTitle(name);
    label = new QLabel("Cash:");
    money_label = new QLabel("");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label);
    layout->addWidget(money_label);
    setLayout(layout);

}

void PlayerFrame::setCash(int cash)
{
    label->setText(QString::number(cash));
}

void PlayerFrame::setPropertyOwnership(int id, bool owned)
{

}

