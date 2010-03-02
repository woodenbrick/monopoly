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
    QString status;
    QString creator;
    QString locale;
    int min;
    int max;
    QString range; //max and min in string form
    int current;
    QString playerNames;
public:
    Game(rapidxml::xml_node<> *game);
    QString getId();
    QString getData();
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
