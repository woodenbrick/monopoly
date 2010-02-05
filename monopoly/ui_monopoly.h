/********************************************************************************
** Form generated from reading ui file 'monopoly.ui'
**
** Created: Sat Jan 23 20:21:21 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MONOPOLY_H
#define UI_MONOPOLY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_10;
    QLabel *label_12;
    QGroupBox *groupBox_5;
    QLabel *label_13;
    QPushButton *pushButton_6;
    QLabel *label_14;
    QLabel *label_15;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QLabel *label_8;
    QGroupBox *groupBox_6;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_7;
    QLabel *label_19;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1075, 634);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(300, 10, 471, 451));
    label->setPixmap(QPixmap(QString::fromUtf8(":/images/board2.png")));
    label->setScaledContents(true);
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 0, 271, 181));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 30, 41, 17));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(70, 30, 56, 17));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(30, 50, 221, 91));
    label_4->setWordWrap(true);
    textBrowser = new QTextBrowser(centralwidget);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    textBrowser->setGeometry(QRect(360, 70, 351, 281));
    textBrowser->setAutoFillBackground(false);
    textBrowser_2 = new QTextBrowser(centralwidget);
    textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
    textBrowser_2->setGeometry(QRect(360, 350, 351, 51));
    textBrowser_3 = new QTextBrowser(centralwidget);
    textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
    textBrowser_3->setGeometry(QRect(300, 460, 471, 131));
    groupBox_3 = new QGroupBox(centralwidget);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(790, 10, 261, 201));
    label_11 = new QLabel(groupBox_3);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(20, 20, 231, 121));
    label_11->setWordWrap(true);
    pushButton_2 = new QPushButton(groupBox_3);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(20, 140, 111, 27));
    scrollArea = new QScrollArea(centralwidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    scrollArea->setGeometry(QRect(800, 250, 251, 321));
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 247, 317));
    groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 30, 221, 121));
    label_9 = new QLabel(groupBox_4);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(10, 10, 56, 17));
    pushButton_3 = new QPushButton(groupBox_4);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(10, 80, 61, 27));
    pushButton_4 = new QPushButton(groupBox_4);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(80, 80, 61, 27));
    pushButton_5 = new QPushButton(groupBox_4);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(150, 80, 61, 27));
    label_10 = new QLabel(groupBox_4);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(20, 10, 191, 51));
    label_10->setWordWrap(true);
    label_12 = new QLabel(scrollAreaWidgetContents);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(10, 10, 56, 17));
    groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(10, 170, 221, 121));
    label_13 = new QLabel(groupBox_5);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(10, 10, 56, 17));
    pushButton_6 = new QPushButton(groupBox_5);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(70, 80, 71, 27));
    label_14 = new QLabel(groupBox_5);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setGeometry(QRect(20, 10, 191, 51));
    label_14->setWordWrap(true);
    scrollArea->setWidget(scrollAreaWidgetContents);
    label_15 = new QLabel(centralwidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(40, 400, 211, 181));
    label_15->setWordWrap(true);
    scrollArea_2 = new QScrollArea(centralwidget);
    scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
    scrollArea_2->setGeometry(QRect(10, 190, 271, 231));
    scrollArea_2->setFrameShadow(QFrame::Raised);
    scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea_2->setWidgetResizable(true);
    scrollAreaWidgetContents_2 = new QWidget();
    scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
    scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 251, 227));
    groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(20, 10, 221, 181));
    label_5 = new QLabel(groupBox_2);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(20, 30, 41, 17));
    label_6 = new QLabel(groupBox_2);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(70, 30, 56, 17));
    label_7 = new QLabel(groupBox_2);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(30, 50, 171, 91));
    label_7->setWordWrap(true);
    pushButton = new QPushButton(groupBox_2);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(70, 140, 80, 27));
    label_8 = new QLabel(groupBox_2);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(120, 20, 91, 31));
    label_8->setWordWrap(true);
    groupBox_6 = new QGroupBox(scrollAreaWidgetContents_2);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    groupBox_6->setGeometry(QRect(20, 200, 221, 181));
    label_16 = new QLabel(groupBox_6);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(20, 30, 41, 17));
    label_17 = new QLabel(groupBox_6);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setGeometry(QRect(70, 30, 56, 17));
    label_18 = new QLabel(groupBox_6);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setGeometry(QRect(30, 50, 171, 91));
    label_18->setWordWrap(true);
    pushButton_7 = new QPushButton(groupBox_6);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(70, 140, 80, 27));
    label_19 = new QLabel(groupBox_6);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(120, 20, 91, 31));
    label_19->setWordWrap(true);
    scrollArea_2->setWidget(scrollAreaWidgetContents_2);
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1075, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
    groupBox->setTitle(QApplication::translate("MainWindow", "Daniel", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Cash:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "\302\2431500", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Here would be an image of all properties on the board, and ones that i dont own will be transparent.  mousing over them will show me the full title deed.", 0, QApplication::UnicodeUTF8));
    textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Boot pic) Daniel:</span> Blah Blah</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Hat pic) Lewis:</span> Blah</p></body></html>", 0, QApplication::UnicodeUTF8));
    textBrowser_3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Boot pic) Daniel </span>rolled a 7 and landed on Chance: Go to Jail</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Hat pic) Lewis </span>rolled a 4 and landed on The Angel Islington</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Boot pic) Lewis </span>called an auction for the Angel Islington</p>"
        "\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">(Hat pic) Daniel </span>won the auction with \302\24370</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This will be all the messages from the server so people know who is buying what and any dealings.</p></body></html>", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("MainWindow", "Bank", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("MainWindow", "The banks properties and perhaps a visual count of houses/hotel.  I though maybe they could fly over to the board and place themselves but ill leave that kinda thing till later.", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("MainWindow", "Buy/Sell Houses", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QString());
    label_9->setText(QString());
    pushButton_3->setText(QApplication::translate("MainWindow", "Accept", 0, QApplication::UnicodeUTF8));
    pushButton_4->setText(QApplication::translate("MainWindow", "Reject", 0, QApplication::UnicodeUTF8));
    pushButton_5->setText(QApplication::translate("MainWindow", "Counter", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("MainWindow", "This is an offer that someone has given you", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("MainWindow", "Offers", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QString());
    label_13->setText(QString());
    pushButton_6->setText(QApplication::translate("MainWindow", "Withdraw", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("MainWindow", "This is an offer that you have given to someone", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("MainWindow", "This area could hold a picture of the property that currently has the mouse over it.", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("MainWindow", "Lewis", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "Cash:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindow", "\302\2431500", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("MainWindow", "The other option is to just show the owned properties rather than all of them.", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "Make Offer", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("MainWindow", "Pic of jail cards here, if owned.", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("MainWindow", "Buzz", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("MainWindow", "Cash:", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("MainWindow", "\302\2431500", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("MainWindow", "The other option is to just show the owned properties rather than all of them.", 0, QApplication::UnicodeUTF8));
    pushButton_7->setText(QApplication::translate("MainWindow", "Make Offer", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("MainWindow", "Pic of jail cards here, if owned.", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONOPOLY_H
