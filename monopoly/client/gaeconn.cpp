#include "curlwrapper.h"
#include "../lib/rapidxml.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "gaeconn.h"

using namespace std;




Game::Game(rapidxml::xml_node<> *game)
{
    id = QString(game->first_attribute("id")->value());
    status = game->first_node("status")->value();
    creator = QString(game->first_node("creator")->value());
    locale = QString(game->first_node("locale")->value());
    min = atoi(game->first_node("min_players")->value());
    max = atoi(game->first_node("max_players")->value());
    rapidxml::xml_node<> *players = game->first_node("players");
    current = atoi(players->first_attribute()->value());
    players = players->first_node();
    while(players != 0)
    {
        playerNames.append(players->value());
        playerNames.append("\n");
        players = players->next_sibling();
    }
}


//void Game::printout()
//{
//    cout << "ID:" << id.toStdString() << "\nStatus:" << status << "\nCreator:" << creator.toStdString()
//            << "\nLocale:" <<
//            locale << "\nMin:" <<
//            min << "\nMax:" << max << "\nCurrent Players:" << current << "\nPlayer Names:\n" <<
//            playerNames << endl;
//}


QString Game::getId()
{
    return id;
}

QString Game::getData()
{
    QString s = QString(id + "\nCreator: " + creator + "\nLocale: " + locale +
                        "\nMin/Max: %1/%2\nStatus: " + status + "\nCurrent Players (%3): "
                        + playerNames).arg(min).arg(max).arg(current);
    return s;

}

Games::Games()
{
    //string xml = urlRetrieve(REMOTEHOST);
/*    char *a=new char[xml.size()+1];
    a[xml.size()]=0;
    memcpy(a, xml.c_str(), xml.size());
    doc.parse<0>(a);
    gameIter = doc.first_node("games")->first_node()*/;
}

void Games::createGame()
{
    currentGame = new Game(gameIter);
}

bool Games::hasNext()
{
    if(gameIter->next_sibling()) return false;
    else return true;

}

void Games::next(){ gameIter++; }


