/********************************************************************************
** Form generated from reading UI file 'ice.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICE_H
#define UI_ICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ice
{
public:
    QLabel *labelImg;

    void setupUi(QWidget *Ice)
    {
        if (Ice->objectName().isEmpty())
            Ice->setObjectName(QStringLiteral("Ice"));
        Ice->resize(1512, 1134);
        Ice->setMinimumSize(QSize(1512, 1134));
        Ice->setMaximumSize(QSize(1512, 1134));
        labelImg = new QLabel(Ice);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setGeometry(QRect(290, 190, 41, 61));
        labelImg->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/ice.png);"));

        retranslateUi(Ice);

        QMetaObject::connectSlotsByName(Ice);
    } // setupUi

    void retranslateUi(QWidget *Ice)
    {
        Ice->setWindowTitle(QApplication::translate("Ice", "Form", nullptr));
        labelImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Ice: public Ui_Ice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICE_H
