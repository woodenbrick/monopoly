#ifndef PLAYERFRAME_H
#define PLAYERFRAME_H

#include <QGroupBox>
#include <QtGui>

class PlayerFrame : public QGroupBox
{    
public:
    PlayerFrame(QMainWindow *parent, QString name);
    void setCash(int cash);
    void setPropertyOwnership(int id, bool owned);
private:
    QLabel *label;
    QLabel *money_label;

};

#endif // PLAYERFRAME_H

class OtherPlayerFrame : public QGroupBox, virtual public PlayerFrame
{
public:
    OtherPlayerFrame(QMainWindow *parent, QString name);
    void makeOffer();
private:
    QPushButton *button;
};
