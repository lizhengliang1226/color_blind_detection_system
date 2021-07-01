/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btn_prev;
    QPushButton *btn_next;
    QPushButton *btn_confirm;
    QPushButton *btn_c;
    QPushButton *btn_b;
    QPushButton *btn_a;
    QLabel *test_img;
    QLabel *label_show;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *answerGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"border-radius:5px;\n"
"\n"
"}\n"
"QWidget\n"
"{\n"
"background-color: #84AF9B;\n"
"}\n"
"#btn_a:checked,#btn_b:checked,#btn_c:checked\n"
"{\n"
"background-color:rgb(89, 124, 255);border:2px solid #ccc;\n"
"}\n"
"\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 20, 391, 51));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;"));
        label->setAlignment(Qt::AlignCenter);
        btn_prev = new QPushButton(centralwidget);
        btn_prev->setObjectName(QString::fromUtf8("btn_prev"));
        btn_prev->setGeometry(QRect(90, 480, 111, 61));
        QFont font1;
        font1.setPointSize(20);
        btn_prev->setFont(font1);
        btn_prev->setStyleSheet(QString::fromUtf8("background-color:#5bc0de;\n"
"border-radius:5px;"));
        btn_next = new QPushButton(centralwidget);
        btn_next->setObjectName(QString::fromUtf8("btn_next"));
        btn_next->setGeometry(QRect(540, 480, 131, 61));
        btn_next->setFont(font1);
        btn_next->setStyleSheet(QString::fromUtf8("\n"
"background-color:#5bc0de;\n"
"border-radius:5px;"));
        btn_confirm = new QPushButton(centralwidget);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(780, 450, 171, 101));
        btn_confirm->setFont(font1);
        btn_confirm->setStyleSheet(QString::fromUtf8("\n"
"#btn_confirm\n"
"{background-color:#d9534f;\n"
"border-radius:5px;\n"
"color:white;\n"
"\n"
"}\n"
""));
        btn_c = new QPushButton(centralwidget);
        answerGroup = new QButtonGroup(MainWindow);
        answerGroup->setObjectName(QString::fromUtf8("answerGroup"));
        answerGroup->addButton(btn_c);
        btn_c->setObjectName(QString::fromUtf8("btn_c"));
        btn_c->setGeometry(QRect(790, 310, 131, 61));
        btn_c->setFont(font1);
        btn_c->setCheckable(true);
        btn_b = new QPushButton(centralwidget);
        answerGroup->addButton(btn_b);
        btn_b->setObjectName(QString::fromUtf8("btn_b"));
        btn_b->setGeometry(QRect(790, 200, 131, 61));
        btn_b->setFont(font1);
        btn_b->setStyleSheet(QString::fromUtf8("\n"
"#btn_b\n"
"{\n"
"border-redius:5px;\n"
"}\n"
""));
        btn_b->setCheckable(true);
        btn_b->setChecked(false);
        btn_a = new QPushButton(centralwidget);
        answerGroup->addButton(btn_a);
        btn_a->setObjectName(QString::fromUtf8("btn_a"));
        btn_a->setGeometry(QRect(790, 90, 131, 61));
        btn_a->setFont(font1);
        btn_a->setStyleSheet(QString::fromUtf8(""));
        btn_a->setCheckable(true);
        test_img = new QLabel(centralwidget);
        test_img->setObjectName(QString::fromUtf8("test_img"));
        test_img->setGeometry(QRect(90, 90, 601, 361));
        test_img->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/\345\234\206\345\275\242.jpg);"));
        test_img->setFrameShape(QFrame::Box);
        label_show = new QLabel(centralwidget);
        label_show->setObjectName(QString::fromUtf8("label_show"));
        label_show->setGeometry(QRect(330, 490, 100, 50));
        label_show->setStyleSheet(QString::fromUtf8("font-size:20px;\n"
"border-radius:25px;\n"
"background-color:#5bc0de;"));
        label_show->setFrameShape(QFrame::Box);
        label_show->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\211\262\347\233\262\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\211\262\347\233\262\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        btn_prev->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\345\274\240", nullptr));
        btn_next->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", nullptr));
        btn_confirm->setText(QApplication::translate("MainWindow", "\350\216\267\345\217\226\347\273\223\346\236\234", nullptr));
        btn_c->setText(QApplication::translate("MainWindow", "C", nullptr));
        btn_b->setText(QApplication::translate("MainWindow", "B", nullptr));
        btn_a->setText(QApplication::translate("MainWindow", "A", nullptr));
        test_img->setText(QString());
        label_show->setText(QApplication::translate("MainWindow", "1/15\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
