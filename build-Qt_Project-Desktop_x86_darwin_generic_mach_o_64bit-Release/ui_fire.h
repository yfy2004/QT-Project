/********************************************************************************
** Form generated from reading UI file 'fire.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRE_H
#define UI_FIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fire
{
public:

    void setupUi(QWidget *Fire)
    {
        if (Fire->objectName().isEmpty())
            Fire->setObjectName(QStringLiteral("Fire"));
        Fire->resize(1512, 1134);
        Fire->setMinimumSize(QSize(1512, 1134));
        Fire->setMaximumSize(QSize(1512, 1134));

        retranslateUi(Fire);

        QMetaObject::connectSlotsByName(Fire);
    } // setupUi

    void retranslateUi(QWidget *Fire)
    {
        Fire->setWindowTitle(QApplication::translate("Fire", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fire: public Ui_Fire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRE_H
