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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *blue;
    QLabel *red;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

    void setupUi(QWidget *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName(QStringLiteral("record"));
        record->resize(1322, 987);
        record->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/main_standard.png);"));
        pushButton = new QPushButton(record);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(520, 780, 265, 92));
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/return_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}\n"
""));
        pushButton->setFlat(true);
        label = new QLabel(record);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 290, 350, 450));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/first.png);"));
        label_2 = new QLabel(record);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 395, 350, 345));
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/second.png);"));
        label_3 = new QLabel(record);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(840, 475, 350, 265));
        label_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/third.png);"));
        label_4 = new QLabel(record);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(520, 130, 265, 61));
        label_4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_time.png);"));
        label_5 = new QLabel(record);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 190, 77, 91));
        label_5->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_diamond.png);"));
        label_6 = new QLabel(record);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(180, 230, 265, 61));
        label_6->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_time.png);"));
        label_7 = new QLabel(record);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(180, 290, 77, 91));
        label_7->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_diamond.png);"));
        label_8 = new QLabel(record);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(880, 310, 265, 63));
        label_8->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_time.png);"));
        label_9 = new QLabel(record);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(880, 370, 77, 91));
        label_9->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/record_diamond.png);"));
        blue = new QLabel(record);
        blue->setObjectName(QStringLiteral("blue"));
        blue->setGeometry(QRect(600, 185, 36, 51));
        blue->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));
        red = new QLabel(record);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(600, 235, 36, 51));
        red->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));
        label1 = new QLabel(record);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(640, 135, 36, 51));
        label1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));
        label2 = new QLabel(record);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(675, 135, 36, 51));
        label2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));
        label3 = new QLabel(record);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(720, 135, 36, 51));
        label3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));
        label4 = new QLabel(record);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(755, 135, 36, 51));
        label4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/zero_new.png);"));

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QWidget *record)
    {
        record->setWindowTitle(QApplication::translate("record", "Form", nullptr));
        pushButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        blue->setText(QString());
        red->setText(QString());
        label1->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
