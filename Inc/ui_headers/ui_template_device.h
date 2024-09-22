/********************************************************************************
** Form generated from reading UI file 'template_device.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATE_DEVICE_H
#define UI_TEMPLATE_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_template_device
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QPushButton *onnetworkPair_btn;
    QPushButton *BLE_pair_btn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_deviceID;
    QLineEdit *lineEdit_DeviceName;
    QLabel *label_DeviceType;
    QPushButton *control_btn;
    QPushButton *info_btn;
    QPushButton *unpair_btn;

    void setupUi(QWidget *template_device)
    {
        if (template_device->objectName().isEmpty())
            template_device->setObjectName("template_device");
        template_device->resize(283, 212);
        verticalLayout = new QVBoxLayout(template_device);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(template_device);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(280, 210));
        frame->setMaximumSize(QSize(280, 210));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        onnetworkPair_btn = new QPushButton(frame);
        onnetworkPair_btn->setObjectName("onnetworkPair_btn");
        onnetworkPair_btn->setGeometry(QRect(10, 120, 101, 22));
        BLE_pair_btn = new QPushButton(frame);
        BLE_pair_btn->setObjectName("BLE_pair_btn");
        BLE_pair_btn->setGeometry(QRect(150, 120, 80, 22));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 81, 21));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 81, 21));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 91, 21));
        lineEdit_deviceID = new QLineEdit(frame);
        lineEdit_deviceID->setObjectName("lineEdit_deviceID");
        lineEdit_deviceID->setGeometry(QRect(130, 40, 91, 22));
        lineEdit_deviceID->setReadOnly(true);
        lineEdit_DeviceName = new QLineEdit(frame);
        lineEdit_DeviceName->setObjectName("lineEdit_DeviceName");
        lineEdit_DeviceName->setGeometry(QRect(130, 70, 91, 22));
        lineEdit_DeviceName->setReadOnly(true);
        label_DeviceType = new QLabel(frame);
        label_DeviceType->setObjectName("label_DeviceType");
        label_DeviceType->setGeometry(QRect(140, 10, 111, 21));
        control_btn = new QPushButton(frame);
        control_btn->setObjectName("control_btn");
        control_btn->setEnabled(true);
        control_btn->setGeometry(QRect(10, 120, 101, 21));
        info_btn = new QPushButton(frame);
        info_btn->setObjectName("info_btn");
        info_btn->setGeometry(QRect(10, 160, 101, 22));
        unpair_btn = new QPushButton(frame);
        unpair_btn->setObjectName("unpair_btn");
        unpair_btn->setGeometry(QRect(150, 120, 80, 22));

        verticalLayout->addWidget(frame);


        retranslateUi(template_device);

        QMetaObject::connectSlotsByName(template_device);
    } // setupUi

    void retranslateUi(QWidget *template_device)
    {
        template_device->setWindowTitle(QCoreApplication::translate("template_device", "Form", nullptr));
        onnetworkPair_btn->setText(QCoreApplication::translate("template_device", "Onnetwork pair", nullptr));
        BLE_pair_btn->setText(QCoreApplication::translate("template_device", "BLE pairing", nullptr));
        label->setText(QCoreApplication::translate("template_device", "Device ID", nullptr));
        label_2->setText(QCoreApplication::translate("template_device", "Device name", nullptr));
        label_3->setText(QCoreApplication::translate("template_device", "Device type", nullptr));
        label_DeviceType->setText(QString());
        control_btn->setText(QCoreApplication::translate("template_device", "control", nullptr));
        info_btn->setText(QCoreApplication::translate("template_device", "More info", nullptr));
        unpair_btn->setText(QCoreApplication::translate("template_device", "unpair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class template_device: public Ui_template_device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATE_DEVICE_H
