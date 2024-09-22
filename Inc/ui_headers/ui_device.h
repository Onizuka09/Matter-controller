/********************************************************************************
** Form generated from reading UI file 'device.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_H
#define UI_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QPushButton *btn_onneworkPair;
    QPushButton *btn_BLE_pair;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_deviceID;
    QLineEdit *lineEdit_DeviceName;
    QLabel *label_DeviceType;
    QPushButton *btn_control;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(284, 212);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(Form);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btn_onneworkPair = new QPushButton(frame);
        btn_onneworkPair->setObjectName("btn_onneworkPair");
        btn_onneworkPair->setGeometry(QRect(10, 120, 101, 22));
        btn_BLE_pair = new QPushButton(frame);
        btn_BLE_pair->setObjectName("btn_BLE_pair");
        btn_BLE_pair->setGeometry(QRect(150, 120, 80, 22));
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
        label_DeviceType->setGeometry(QRect(140, 10, 71, 21));
        btn_control = new QPushButton(frame);
        btn_control->setObjectName("btn_control");
        btn_control->setGeometry(QRect(90, 160, 80, 22));

        verticalLayout->addWidget(frame);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        btn_onneworkPair->setText(QCoreApplication::translate("Form", "Onnetwork pair", nullptr));
        btn_BLE_pair->setText(QCoreApplication::translate("Form", "BLE pairing", nullptr));
        label->setText(QCoreApplication::translate("Form", "Device ID", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Device name", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Device type", nullptr));
        label_DeviceType->setText(QCoreApplication::translate("Form", "TextLabel", nullptr));
        btn_control->setText(QCoreApplication::translate("Form", "control", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_H
