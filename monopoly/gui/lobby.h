#ifndef LOBBY_H
#define LOBBY_H

#include <QtGui>
#include <QtNetwork>
#include "ui_lobby.h"

class Lobby : public QDialog, public Ui::Lobby
{
    Q_OBJECT
private:
    QStandardItemModel* model;
    QUrl url;
    QXmlStreamReader doc;
    QXmlStreamReader::TokenType token;
    QNetworkAccessManager conn;
    QNetworkRequest request;
    QNetworkReply* reply;
signals:
    void parseComplete();
public:
    Lobby(QWidget* parent=0);
    void checkGameServer();        
public slots:
    void on_buttonExit_clicked();
private slots:
    void parseGameList(QNetworkReply*);
};

class Game
{
    QString id;
    QString status;
    QString creator;
    QString locale;
    int min;
    int max;
    int current;
    QString playerNames;
public:
    Game(QXmlStreamReader& game);
    QString getId();
    QStandardItem* getData();
};


#endif // LOBBY_H
