#include "lobby.h"
#include <vector>
#include <QtGui>
#include <cstdlib>


char* REMOTEHOST = "http://monopolyserver.appspot.com/game/list";

using namespace std;
Lobby::Lobby(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    show();
    model = new QStandardItemModel(this);
    gameList->setModel(model);
    checkGameServer();
    checkGameServer();
    show();

}

void Lobby::checkGameServer()
{
    string xml = urlRetrieve(REMOTEHOST);
    char *a=new char[xml.size()+1];
    a[xml.size()]=0;
    memcpy(a, xml.c_str(), xml.size());
    doc.parse<0>(a);
    xmlIter = doc.first_node("games")->first_node();
    bool isFound;
    model->clear();
    while(xmlIter)
    {
        Game *g = new Game(xmlIter);
        cout << g->getId().toStdString() << endl;
        isFound = false;
        if(!isFound)
        {
            //QIcon icon(":/boot");
            QStandardItem *item = new QStandardItem("Happ");
            model->appendRow(g->getData());

        }
        xmlIter = xmlIter->next_sibling();
    }
    //for(gameIter=games->begin(); gameIter != games->end(); gameIter++)

}

void Lobby::on_buttonExit_clicked()
{
    this->destroy();
}
