#ifndef LOBBY_H
#define LOBBY_H

#include <QtGui>
#include "ui_lobby.h"
#include "../client/gaeconn.h"
#include "../lib/rapidxml.hpp"

class Lobby : public QDialog, public Ui::Lobby
{
    Q_OBJECT
private:
    QStandardItemModel* model;
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<>* xmlIter;
public:
    Lobby(QWidget* parent=0);
    void checkGameServer();

public slots:
    void on_buttonExit_clicked();
};



#endif // LOBBY_H
