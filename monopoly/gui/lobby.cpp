#include "lobby.h"

Lobby::Lobby(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    //show();
//    model = new QStandardItemModel();
//    model->setColumnCount(5);
    //checkGameServer();
    //gui->gameList->setModel(model);
    //window->show();

}
//
//void Lobby::checkGameServer()
//{
//    for (int row = 0; row < 4; ++row) {
//        for (int column = 0; column < 4; ++column) {
//            QIcon icon(":/boot");
//            QStandardItem *item = new QStandardItem(icon, "Boot");//QString("row %0, column %1").arg(row).arg(column));
//            model->setItem(row, column, item);
//        }
//    }
//}

void Lobby::on_buttonExit_clicked()
{
    this->destroy();
}
