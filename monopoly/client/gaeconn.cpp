#include "curlwrapper.h"
#include "rapidxml/rapidxml.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Game
{
    string id;
    string status;
    string creator;
    string locale;
    int min;
    int max;
    int current;
    string playerNames;
public:
    Game(rapidxml::xml_node<> *game);
    void printout();

};

Game::Game(rapidxml::xml_node<> *game)
{
    id = game->first_attribute("id")->value();
    status = game->first_node("status")->value();
    creator = game->first_node("creator")->value();
    locale = game->first_node("locale")->value();
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


void Game::printout()
{
    cout << "ID:" << id << "\nStatus:" << status << "\nCreator:" << creator << "\nLocale:" <<
            locale << "\nMin:" <<
            min << "\nMax:" << max << "\nCurrent Players:" << current << "\nPlayer Names:\n" <<
            playerNames << endl;
}


int main(int argc, char* argv[])
{

    string xml = urlRetrieve("http://localhost:8080/game/list");
    char *a=new char[xml.size()+1];
    a[xml.size()]=0;
    memcpy(a, xml.c_str(), xml.size());
    //cout << xml;
    rapidxml::xml_document<> doc;
    doc.parse<0>(a);
    rapidxml::xml_node<>* root = doc.first_node("games");
    //cout << node->first_node()->first_attribute()->value();
    Game *g;
    for (rapidxml::xml_node<> *game = root->first_node();
         game; game = game->next_sibling())
    {
        g = new Game(game);
        g->printout();
    }

    return 0;
}
