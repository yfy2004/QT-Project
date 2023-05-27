/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName(QStringLiteral("record"));
        record->resize(1322, 987);
        record->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/main_standard.png);"));
        pushButton = new QPushButton(record);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 730, 265, 92));
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/return_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}\n"
""));
        pushButton->setFlat(true);

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QWidget *record)
    {
        record->setWindowTitle(QApplication::translate("record", "Form", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
