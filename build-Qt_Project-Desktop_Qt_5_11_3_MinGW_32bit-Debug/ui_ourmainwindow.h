/********************************************************************************
** Form generated from reading UI file 'ourmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OURMAINWINDOW_H
#define UI_OURMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OurMainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OurMainWindow)
    {
        if (OurMainWindow->objectName().isEmpty())
            OurMainWindow->setObjectName(QStringLiteral("OurMainWindow"));
        OurMainWindow->resize(1512, 1134);
        OurMainWindow->setMinimumSize(QSize(1512, 1134));
        OurMainWindow->setMaximumSize(QSize(1512, 1134));
        OurMainWindow->setStyleSheet(QStringLiteral("#OurMainWindow{background-image: url(:/new/prefix1/picture/background_new.png);}"));
        centralWidget = new QWidget(OurMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 610, 408, 135));
        pushButton->setMinimumSize(QSize(406, 134));
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/start_new.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
"padding:0px;\n"
"pressed{border:1px solid rgba(255,255,255,0);\n"
"padding:0px;}"));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 820, 240, 75));
        pushButton_2->setMinimumSize(QSize(240, 75));
        pushButton_2->setMaximumSize(QSize(240, 75));
        pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_new_new.png);"));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 950, 240, 75));
        pushButton_3->setMinimumSize(QSize(240, 75));
        pushButton_3->setMaximumSize(QSize(240, 75));
        pushButton_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/gameover_new.png);"));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1400, 9, 32, 40));
        pushButton_4->setMinimumSize(QSize(32, 40));
        pushButton_4->setMaximumSize(QSize(32, 40));
        pushButton_4->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/help.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
""));
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1444, 7, 45, 38));
        pushButton_5->setMinimumSize(QSize(45, 38));
        pushButton_5->setMaximumSize(QSize(45, 38));
        pushButton_5->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/music_on.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
""));
        pushButton_5->setIconSize(QSize(45, 38));
        pushButton_5->setCheckable(false);
        pushButton_5->setFlat(true);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);
        pushButton_6->setGeometry(QRect(1445, 7, 24, 38));
        pushButton_6->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/music_off.png);\n"
"border:1px solid rgba(255,255,255,0);"));
        OurMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OurMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1512, 17));
        OurMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OurMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OurMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OurMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OurMainWindow->setStatusBar(statusBar);

        retranslateUi(OurMainWindow);

        QMetaObject::connectSlotsByName(OurMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *OurMainWindow)
    {
        OurMainWindow->setWindowTitle(QApplication::translate("OurMainWindow", "OurMainWindow", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OurMainWindow: public Ui_OurMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OURMAINWINDOW_H
