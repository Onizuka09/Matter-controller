/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_3;
    QPushButton *Home_btn;
    QPushButton *Control_btn;
    QPushButton *settings_btn;
    QPushButton *mydevice_btn;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_11;
    QLabel *label;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_3;
    QWidget *Control;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *discover_btn;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QGridLayout *gridLayout;
    QWidget *devices;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *devicesW_label;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget;
    QWidget *main_tab;
    QGridLayout *gridLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser;
    QLabel *label_gif;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 790);
        MainWindow->setMinimumSize(QSize(750, 790));
        MainWindow->setMaximumSize(QSize(750, 790));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 400));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName("horizontalLayout");
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(100, 100));
        frame_3->setMaximumSize(QSize(100, 16777215));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        Home_btn = new QPushButton(frame_3);
        Home_btn->setObjectName("Home_btn");
        Home_btn->setGeometry(QRect(10, 20, 80, 22));
        Control_btn = new QPushButton(frame_3);
        Control_btn->setObjectName("Control_btn");
        Control_btn->setGeometry(QRect(9, 70, 81, 22));
        settings_btn = new QPushButton(frame_3);
        settings_btn->setObjectName("settings_btn");
        settings_btn->setGeometry(QRect(10, 350, 80, 22));
        mydevice_btn = new QPushButton(frame_3);
        mydevice_btn->setObjectName("mydevice_btn");
        mydevice_btn->setGeometry(QRect(10, 120, 81, 22));

        horizontalLayout->addWidget(frame_3);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(frame_4);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setFrameShape(QFrame::NoFrame);
        Home = new QWidget();
        Home->setObjectName("Home");
        verticalLayout_10 = new QVBoxLayout(Home);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(Home);
        frame_5->setObjectName("frame_5");
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_5);
        verticalLayout_11->setObjectName("verticalLayout_11");
        label = new QLabel(frame_5);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("backround-color green"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label);


        verticalLayout_10->addWidget(frame_5);

        frame_10 = new QFrame(Home);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_10);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_3 = new QLabel(frame_10);
        label_3->setObjectName("label_3");
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/images/matter-logo.png")));
        label_3->setScaledContents(true);

        verticalLayout_12->addWidget(label_3);


        verticalLayout_10->addWidget(frame_10);

        stackedWidget->addWidget(Home);
        Control = new QWidget();
        Control->setObjectName("Control");
        verticalLayout_3 = new QVBoxLayout(Control);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(Control);
        frame_6->setObjectName("frame_6");
        frame_6->setMinimumSize(QSize(0, 50));
        frame_6->setMaximumSize(QSize(16777215, 50));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(frame_6);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        discover_btn = new QPushButton(frame_6);
        discover_btn->setObjectName("discover_btn");
        discover_btn->setMinimumSize(QSize(30, 30));
        discover_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(discover_btn);


        verticalLayout_3->addWidget(frame_6);

        scrollArea = new QScrollArea(Control);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 606, 325));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(scrollAreaWidgetContents);
        frame_7->setObjectName("frame_7");
        frame_7->setMinimumSize(QSize(606, 325));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_7);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(9, -1, -1, -1);

        verticalLayout_5->addWidget(frame_7);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        stackedWidget->addWidget(Control);
        devices = new QWidget();
        devices->setObjectName("devices");
        verticalLayout_7 = new QVBoxLayout(devices);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_8 = new QFrame(devices);
        frame_8->setObjectName("frame_8");
        frame_8->setMinimumSize(QSize(0, 50));
        frame_8->setMaximumSize(QSize(16777215, 50));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_8);
        verticalLayout_8->setObjectName("verticalLayout_8");
        devicesW_label = new QLabel(frame_8);
        devicesW_label->setObjectName("devicesW_label");

        verticalLayout_8->addWidget(devicesW_label);


        verticalLayout_7->addWidget(frame_8);

        frame_9 = new QFrame(devices);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::NoFrame);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_9);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(frame_9);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setMinimumSize(QSize(606, 325));
        scrollArea_2->setFrameShape(QFrame::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 606, 325));
        verticalLayout_9 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(scrollAreaWidgetContents_2);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMinimumSize(QSize(606, 325));
        main_tab = new QWidget();
        main_tab->setObjectName("main_tab");
        gridLayout_2 = new QGridLayout(main_tab);
        gridLayout_2->setObjectName("gridLayout_2");
        tabWidget->addTab(main_tab, QString());

        verticalLayout_9->addWidget(tabWidget);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_6->addWidget(scrollArea_2);


        verticalLayout_7->addWidget(frame_9);

        stackedWidget->addWidget(devices);

        verticalLayout_4->addWidget(stackedWidget);


        horizontalLayout->addWidget(frame_4);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(870, 300));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(frame_2);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(0, 300));
        textBrowser->setMaximumSize(QSize(16777215, 300));

        verticalLayout_2->addWidget(textBrowser);


        verticalLayout->addWidget(frame_2);

        label_gif = new QLabel(centralwidget);
        label_gif->setObjectName("label_gif");
        label_gif->setMaximumSize(QSize(30, 30));
        label_gif->setFrameShape(QFrame::WinPanel);
        label_gif->setFrameShadow(QFrame::Sunken);
        label_gif->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_gif);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Matter-Controller", nullptr));
        Home_btn->setText(QCoreApplication::translate("MainWindow", "Home ", nullptr));
        Control_btn->setText(QCoreApplication::translate("MainWindow", "Control", nullptr));
        settings_btn->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        mydevice_btn->setText(QCoreApplication::translate("MainWindow", "My devices", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Matter Controller (Using CHIP-TOOL)", nullptr));
        label_3->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Discover devices", nullptr));
        discover_btn->setText(QCoreApplication::translate("MainWindow", "discover", nullptr));
        devicesW_label->setText(QCoreApplication::translate("MainWindow", "My paired devices", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(main_tab), QCoreApplication::translate("MainWindow", "Main", nullptr));
        label_gif->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
