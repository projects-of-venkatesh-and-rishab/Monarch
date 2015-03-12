/********************************************************************************
** Form generated from reading UI file 'wid1.ui'
**
** Created: Wed May 15 13:57:55 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WID1_H
#define UI_WID1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_wid1
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *wid1)
    {
        if (wid1->objectName().isEmpty())
            wid1->setObjectName(QString::fromUtf8("wid1"));
        wid1->resize(400, 300);
        wid1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        layoutWidget = new QWidget(wid1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 401, 297));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 4, 1, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        retranslateUi(wid1);
        QObject::connect(pushButton, SIGNAL(clicked()), pushButton, SLOT(hide()));
        QObject::connect(pushButton, SIGNAL(clicked()), pushButton_2, SLOT(hide()));
        QObject::connect(pushButton, SIGNAL(clicked()), pushButton_3, SLOT(hide()));

        QMetaObject::connectSlotsByName(wid1);
    } // setupUi

    void retranslateUi(QWidget *wid1)
    {
        wid1->setWindowTitle(QApplication::translate("wid1", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("wid1", "Help", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("wid1", "Play", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("wid1", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wid1: public Ui_wid1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WID1_H
