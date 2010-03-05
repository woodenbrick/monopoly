#include "lobby.h"
#include <vector>
#include <QtGui>
#include <cstdlib>



using namespace std;
Lobby::Lobby(QWidget *parent) : QDialog(parent)
{
    url = "http://monopolyserver.appspot.com/game/list";
    setupUi(this);
    show();
    model = new QStandardItemModel(this);
    gameList->setModel(model);
    show();
    connect(&conn, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseGameList(QNetworkReply*)));
    checkGameServer();

}

void Lobby::checkGameServer()
{
    statusBar->setText("Updating game list");
    request.setUrl(url);
    reply = conn.get(request);
}

void Lobby::parseGameList(QNetworkReply *)
{
    if(reply->error() != QNetworkReply::NoError)
        statusBar->setText(reply->errorString());
    else
    {
        statusBar->setText("Last updated at :" + QTime().currentTime().toString());
        QXmlStreamReader doc(reply);
        while(!doc.atEnd())
        {
            qDebug() << "T" << doc.name().toString();
            token = doc.readNext();
            if(token == QXmlStreamReader::StartDocument)
                continue;
            if(token == QXmlStreamReader::StartElement)
            {
                if(doc.name() == "game")
                {
                Game* game = new Game(doc);
                model->appendRow(game->getData());
                }
            }
        }
    }
    emit parseComplete();
    qDebug("Parsing complete");
}

void Lobby::on_buttonExit_clicked()
{
    this->destroy();
}



Game::Game(QXmlStreamReader &game)
{

    id = game.attributes().value("id").toString();
    game.readNext();
    status = game.text().toString();
    game.readNext();
    creator = game.text().toString();
    game.readNext();
    locale = game.text().toString();
    game.readNext();
    min = game.text().toString().toInt();
    game.readNext();
    max = game.text().toString().toInt();
    game.readNext();
    current = game.text().toString().toInt();
    QXmlStreamReader::TokenType token = game.readNext();
    while(token != QXmlStreamReader::EndElement && game.name() != "players")
    {
        playerNames.append(game.text());
        playerNames.append("\n");
        token = game.readNext();
    }
}


QString Game::getId()
{
    return id;
}

QStandardItem* Game::getData()
{
    QString s = QString(id + "\nCreator: " + creator + "\nLocale: " + locale +
                        "\nMin/Max: %1/%2\nStatus: " + status + "\nCurrent Players (%3): "
                        + playerNames).arg(min).arg(max).arg(current);
    QStandardItem *item = new QStandardItem(s);
    return item;

}
