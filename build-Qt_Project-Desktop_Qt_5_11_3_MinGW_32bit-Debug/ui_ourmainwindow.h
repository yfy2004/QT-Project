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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OurMainWindow
{
public:
    QWidget *centralWidget;
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
        OurMainWindow->setStyleSheet(QStringLiteral("#OurMainWindow{background-image: url(:/new/prefix1/picture/background.png);}"));
        centralWidget = new QWidget(OurMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
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
    } // retranslateUi

};

namespace Ui {
    class OurMainWindow: public Ui_OurMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OURMAINWINDOW_H
