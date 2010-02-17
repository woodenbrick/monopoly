#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include "ui_lobby.h"

class Lobby : public QDialog, public Ui::Lobby
{
    Q_OBJECT

public:
    Lobby(QWidget* parent=0);

public slots:
    void on_buttonExit_clicked();
};



#endif // LOBBY_H
