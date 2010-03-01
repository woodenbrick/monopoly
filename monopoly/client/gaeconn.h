#ifndef GAECONN_H
#define GAECONN_H

#include <vector>
#include "curlwrapper.h"
#include "../lib/rapidxml.hpp"
#include <QtGui>

//const char* REMOTEHOST("http://monopolyserver.appspot.com/");

class Game
{
    QString id;
    string status;
    QString creator;
    string locale;
    int min;
    int max;
    int current;
    string playerNames;
public:
    Game(rapidxml::xml_node<> *game);
    QString getId();
    QList<QStandardItem*> getData();
    void printout();


};

class Games
{
public:
    rapidxml::xml_document<> doc;
    rapidxml::xml_node<>* gameIter;
    Game* currentGame;
    Games();
    void createGame();
    bool hasNext();
    void next();
};



#endif // GAECONN_H
