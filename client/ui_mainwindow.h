/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
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
    QFrame *sidemenu;
    QPushButton *recentActivityBtn;
    QPushButton *downloadsBtn;
    QPushButton *myDriveBtn;
    QPushButton *trashBtn;
    QPushButton *sharedBtn;
    QPushButton *exitBtn;
    QFrame *filesContainer;
    QListWidget *filelist;
    QPushButton *listTitleLabel;
    QFrame *filesControls;
    QPushButton *openBtn;
    QPushButton *downloadBtn;
    QPushButton *deleteBtn;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sidemenu = new QFrame(centralwidget);
        sidemenu->setObjectName(QStringLiteral("sidemenu"));
        sidemenu->setGeometry(QRect(20, 80, 141, 451));
        sidemenu->setStyleSheet(QLatin1String("background: #fff;\n"
"border: 1px solid #ddd;\n"
"border-radius: 4px;"));
        sidemenu->setFrameShape(QFrame::StyledPanel);
        sidemenu->setFrameShadow(QFrame::Raised);
        recentActivityBtn = new QPushButton(sidemenu);
        recentActivityBtn->setObjectName(QStringLiteral("recentActivityBtn"));
        recentActivityBtn->setGeometry(QRect(10, 90, 121, 41));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        recentActivityBtn->setFont(font);
        recentActivityBtn->setCursor(QCursor(Qt::OpenHandCursor));
        recentActivityBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"border-bottom: 1px solid #ddd;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"color: #004159;\n"
"border-radius: 0;"));
        recentActivityBtn->setAutoDefault(false);
        downloadsBtn = new QPushButton(sidemenu);
        downloadsBtn->setObjectName(QStringLiteral("downloadsBtn"));
        downloadsBtn->setGeometry(QRect(10, 130, 121, 41));
        downloadsBtn->setFont(font);
        downloadsBtn->setCursor(QCursor(Qt::OpenHandCursor));
        downloadsBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"color: #004159;"));
        downloadsBtn->setAutoDefault(false);
        myDriveBtn = new QPushButton(sidemenu);
        myDriveBtn->setObjectName(QStringLiteral("myDriveBtn"));
        myDriveBtn->setGeometry(QRect(10, 10, 121, 41));
        myDriveBtn->setFont(font);
        myDriveBtn->setCursor(QCursor(Qt::OpenHandCursor));
        myDriveBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"border-bottom: 1px solid #ddd;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"border-radius: 0;\n"
"color: #004159;"));
        myDriveBtn->setAutoDefault(false);
        trashBtn = new QPushButton(sidemenu);
        trashBtn->setObjectName(QStringLiteral("trashBtn"));
        trashBtn->setGeometry(QRect(10, 360, 121, 41));
        trashBtn->setFont(font);
        trashBtn->setCursor(QCursor(Qt::OpenHandCursor));
        trashBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"border-bottom: 1px solid #ddd;\n"
"color: #004159;\n"
"border-radius: 0;"));
        trashBtn->setAutoDefault(false);
        sharedBtn = new QPushButton(sidemenu);
        sharedBtn->setObjectName(QStringLiteral("sharedBtn"));
        sharedBtn->setGeometry(QRect(10, 50, 121, 41));
        sharedBtn->setFont(font);
        sharedBtn->setCursor(QCursor(Qt::OpenHandCursor));
        sharedBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"border-bottom: 1px solid #ddd;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"border-radius: 0;\n"
"color: #004159;"));
        sharedBtn->setAutoDefault(false);
        exitBtn = new QPushButton(sidemenu);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(10, 400, 121, 41));
        exitBtn->setFont(font);
        exitBtn->setCursor(QCursor(Qt::OpenHandCursor));
        exitBtn->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"padding: 12px 0;\n"
"text-align: center;\n"
"font-weight: 400;\n"
"color: #004159;"));
        exitBtn->setAutoDefault(false);
        filesContainer = new QFrame(centralwidget);
        filesContainer->setObjectName(QStringLiteral("filesContainer"));
        filesContainer->setGeometry(QRect(180, 80, 601, 381));
        filesContainer->setStyleSheet(QLatin1String("background: #fff;\n"
"border: 1px solid #ddd;\n"
"border-radius: 4px;"));
        filesContainer->setFrameShape(QFrame::StyledPanel);
        filesContainer->setFrameShadow(QFrame::Raised);
        filelist = new QListWidget(filesContainer);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font1;
        font1.setPointSize(12);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(filelist);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setForeground(brush);
        new QListWidgetItem(filelist);
        new QListWidgetItem(filelist);
        new QListWidgetItem(filelist);
        new QListWidgetItem(filelist);
        new QListWidgetItem(filelist);
        filelist->setObjectName(QStringLiteral("filelist"));
        filelist->setGeometry(QRect(10, 50, 581, 321));
        filelist->viewport()->setProperty("cursor", QVariant(QCursor(Qt::OpenHandCursor)));
        filelist->setStyleSheet(QLatin1String("border: none;\n"
"padding: 6px 8px;\n"
"border: 1px solid #fafafa;\n"
"border-radius: 6px;"));
        listTitleLabel = new QPushButton(filesContainer);
        listTitleLabel->setObjectName(QStringLiteral("listTitleLabel"));
        listTitleLabel->setGeometry(QRect(20, 10, 131, 31));
        listTitleLabel->setFont(font);
        listTitleLabel->setCursor(QCursor(Qt::OpenHandCursor));
        listTitleLabel->setStyleSheet(QLatin1String("background: none;\n"
"border: none;\n"
"text-align: left;\n"
"font-weight: 400;\n"
"border-radius: 0;\n"
"font-size: 18px;\n"
"padding-bottom: 4px;"));
        listTitleLabel->setAutoDefault(false);
        filesControls = new QFrame(centralwidget);
        filesControls->setObjectName(QStringLiteral("filesControls"));
        filesControls->setGeometry(QRect(180, 480, 601, 51));
        filesControls->setStyleSheet(QLatin1String("background: #fff;\n"
"border: 1px solid #ddd;\n"
"border-radius: 4px;"));
        filesControls->setFrameShape(QFrame::StyledPanel);
        filesControls->setFrameShadow(QFrame::Raised);
        openBtn = new QPushButton(filesControls);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setGeometry(QRect(400, 10, 89, 31));
        openBtn->setCursor(QCursor(Qt::OpenHandCursor));
        openBtn->setStyleSheet(QLatin1String("color: #fafafa;\n"
"background: #00c590;"));
        downloadBtn = new QPushButton(filesControls);
        downloadBtn->setObjectName(QStringLiteral("downloadBtn"));
        downloadBtn->setGeometry(QRect(10, 10, 81, 31));
        downloadBtn->setCursor(QCursor(Qt::OpenHandCursor));
        downloadBtn->setStyleSheet(QLatin1String("background: #00adce;\n"
"color: #fff;"));
        deleteBtn = new QPushButton(filesControls);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setGeometry(QRect(500, 10, 89, 31));
        deleteBtn->setCursor(QCursor(Qt::OpenHandCursor));
        deleteBtn->setStyleSheet(QLatin1String("color: #fafafa;\n"
"background: crimson;"));
        openBtn->raise();
        deleteBtn->raise();
        downloadBtn->raise();
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 30, 89, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menubar->setAcceptDrops(true);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Collaborative Notepad", Q_NULLPTR));
        recentActivityBtn->setText(QApplication::translate("MainWindow", "Recent activity", Q_NULLPTR));
        downloadsBtn->setText(QApplication::translate("MainWindow", "Downloads", Q_NULLPTR));
        myDriveBtn->setText(QApplication::translate("MainWindow", "My drive", Q_NULLPTR));
        trashBtn->setText(QApplication::translate("MainWindow", "Trash", Q_NULLPTR));
        sharedBtn->setText(QApplication::translate("MainWindow", "Shared", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));

        const bool __sortingEnabled = filelist->isSortingEnabled();
        filelist->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = filelist->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "file-1.txt", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = filelist->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "file-2.txt", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = filelist->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "file-3.txt", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = filelist->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "file-4.txt", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = filelist->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "photo-1.png", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem5 = filelist->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "photo-2.jpg", Q_NULLPTR));
        filelist->setSortingEnabled(__sortingEnabled);

        listTitleLabel->setText(QApplication::translate("MainWindow", "Your drive", Q_NULLPTR));
        openBtn->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        downloadBtn->setText(QApplication::translate("MainWindow", "Download", Q_NULLPTR));
        deleteBtn->setText(QApplication::translate("MainWindow", "Delete", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
