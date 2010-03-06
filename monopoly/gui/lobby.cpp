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
            token = doc.readNext();
            if(token == QXmlStreamReader::StartDocument)
                continue;
            if(token == QXmlStreamReader::StartElement)
            {
                if(doc.name() == "game")
                {
                Game* game = new Game(doc);
                model->appendRow(game->getData());
                qDebug() << game->getData();
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
    while(game.name() != "game")
    {        
        if(game.tokenType() != QXmlStreamReader::StartElement)
        {
            game.readNext();
            continue;
        }
        if(game.name() == "status")
            status = game.readElementText();
        if(game.name() == "creator")
            creator = game.readElementText();
        if(game.name() == "locale")
            locale = game.readElementText();
        if(game.name() == "min_players")
            min = game.readElementText().toInt();
        if(game.name() == "max_players")
            max = game.readElementText().toInt();
        if(game.name() == "ip")
            ip = game.readElementText();
        if(game.name() == "players")
        {
            current = game.attributes().value("count").toString().toInt();
            game.readNext();
            while(game.name() != "players")
            {
                if(game.tokenType() != QXmlStreamReader::StartElement)
                    game.readNext();
                playerNames.append(game.readElementText());
                playerNames.append("\n");
            }
        }
    }
}


QString Game::getId()
{
    return id;
}

QStandardItem* Game::getData()
{
    QString s = QString(id + " " + ip + "\nCreator: " + creator + "\nLocale: " + locale +
                        "\nMin/Max: %1/%2\nStatus: " + status + "\nCurrent Players (%3): "
                        + playerNames).arg(min).arg(max).arg(current);
    QStandardItem *item = new QStandardItem(s);
    return item;

}
