/********************************************************************************
** Form generated from reading UI file 'help_platform.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_PLATFORM_H
#define UI_HELP_PLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help_platform
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *help_platform)
    {
        if (help_platform->objectName().isEmpty())
            help_platform->setObjectName(QStringLiteral("help_platform"));
        help_platform->resize(1322, 987);
        help_platform->setStyleSheet(QStringLiteral("#help_platform{background-image: url(:/new/prefix1/picture/help_platform.png);}"));
        pushButton = new QPushButton(help_platform);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(530, 810, 271, 79));
        pushButton->setMinimumSize(QSize(271, 79));
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/help_return_hovering.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
""));
        pushButton->setFlat(true);

        retranslateUi(help_platform);

        QMetaObject::connectSlotsByName(help_platform);
    } // setupUi

    void retranslateUi(QWidget *help_platform)
    {
        help_platform->setWindowTitle(QApplication::translate("help_platform", "Form", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class help_platform: public Ui_help_platform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_PLATFORM_H
