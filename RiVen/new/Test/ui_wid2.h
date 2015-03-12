/********************************************************************************
** Form generated from reading UI file 'wid2.ui'
**
** Created: Thu May 9 13:16:06 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WID2_H
#define UI_WID2_H

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

class Ui_wid2
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *wid2)
    {
        if (wid2->objectName().isEmpty())
            wid2->setObjectName(QString::fromUtf8("wid2"));
        wid2->resize(400, 300);
        layoutWidget = new QWidget(wid2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 401, 301));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 2, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 4, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 6, 1, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        pushButton_4->setFont(font);

        gridLayout_2->addWidget(pushButton_4, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout_2->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout_2->addWidget(pushButton_6, 5, 1, 1, 1);


        retranslateUi(wid2);
        QObject::connect(pushButton_5, SIGNAL(clicked()), wid2, SLOT(close()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), wid2, SLOT(close()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), wid2, SLOT(close()));

        QMetaObject::connectSlotsByName(wid2);
    } // setupUi

    void retranslateUi(QWidget *wid2)
    {
        wid2->setWindowTitle(QApplication::translate("wid2", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("wid2", "Medium", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("wid2", "Easy", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("wid2", "Hard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wid2: public Ui_wid2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WID2_H
