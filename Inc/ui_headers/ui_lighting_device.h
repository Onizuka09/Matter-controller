/********************************************************************************
** Form generated from reading UI file 'lighting_device.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTING_DEVICE_H
#define UI_LIGHTING_DEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lighting_device
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QPushButton *unpair_btn;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_5;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *category_edit;
    QLineEdit *devName_edit;
    QLineEdit *instName_edit;
    QLineEdit *IPaddr_edit;
    QFrame *frame_4;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QPushButton *toggle_btn;
    QLabel *label_2;
    QSlider *horizontalSlider;

    void setupUi(QWidget *Lighting_device)
    {
        if (Lighting_device->objectName().isEmpty())
            Lighting_device->setObjectName("Lighting_device");
        Lighting_device->resize(605, 280);
        horizontalLayout = new QHBoxLayout(Lighting_device);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Lighting_device);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(606, 325));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setMaximumSize(QSize(16777215, 50));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");

        horizontalLayout_3->addWidget(label_5);

        unpair_btn = new QPushButton(frame_2);
        unpair_btn->setObjectName("unpair_btn");
        unpair_btn->setMaximumSize(QSize(100, 35));

        horizontalLayout_3->addWidget(unpair_btn);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_5);
        formLayout_2->setObjectName("formLayout_2");
        label_6 = new QLabel(frame_5);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName("label_8");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        label_10 = new QLabel(frame_5);
        label_10->setObjectName("label_10");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_10);

        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_12);

        label_14 = new QLabel(frame_5);
        label_14->setObjectName("label_14");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_14);

        label_15 = new QLabel(frame_5);
        label_15->setObjectName("label_15");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_15);

        category_edit = new QLineEdit(frame_5);
        category_edit->setObjectName("category_edit");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, category_edit);

        devName_edit = new QLineEdit(frame_5);
        devName_edit->setObjectName("devName_edit");

        formLayout_2->setWidget(2, QFormLayout::FieldRole, devName_edit);

        instName_edit = new QLineEdit(frame_5);
        instName_edit->setObjectName("instName_edit");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, instName_edit);

        IPaddr_edit = new QLineEdit(frame_5);
        IPaddr_edit->setObjectName("IPaddr_edit");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, IPaddr_edit);


        horizontalLayout_2->addWidget(frame_5);

        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName("frame_4");
        frame_4->setMaximumSize(QSize(280, 280));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_4);
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::FieldRole, label_4);

        label = new QLabel(frame_4);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        toggle_btn = new QPushButton(frame_4);
        toggle_btn->setObjectName("toggle_btn");

        formLayout->setWidget(1, QFormLayout::FieldRole, toggle_btn);

        label_2 = new QLabel(frame_4);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        horizontalSlider = new QSlider(frame_4);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, horizontalSlider);


        horizontalLayout_2->addWidget(frame_4);


        verticalLayout->addWidget(frame_3);


        horizontalLayout->addWidget(frame);


        retranslateUi(Lighting_device);

        QMetaObject::connectSlotsByName(Lighting_device);
    } // setupUi

    void retranslateUi(QWidget *Lighting_device)
    {
        Lighting_device->setWindowTitle(QCoreApplication::translate("Lighting_device", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Lighting_device", "Device", nullptr));
        unpair_btn->setText(QCoreApplication::translate("Lighting_device", "unpair", nullptr));
        label_6->setText(QCoreApplication::translate("Lighting_device", "Device category", nullptr));
        label_8->setText(QCoreApplication::translate("Lighting_device", "Device Name", nullptr));
        label_10->setText(QCoreApplication::translate("Lighting_device", "Device InstanceName", nullptr));
        label_12->setText(QCoreApplication::translate("Lighting_device", "Device IPaddr", nullptr));
        label_14->setText(QCoreApplication::translate("Lighting_device", "Device info", nullptr));
        label_15->setText(QString());
        label_3->setText(QCoreApplication::translate("Lighting_device", "Control panel", nullptr));
        label_4->setText(QString());
        label->setText(QCoreApplication::translate("Lighting_device", "Toggle (OnOff)", nullptr));
        toggle_btn->setText(QCoreApplication::translate("Lighting_device", "Toogle (On)", nullptr));
        label_2->setText(QCoreApplication::translate("Lighting_device", "set lighting value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lighting_device: public Ui_Lighting_device {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTING_DEVICE_H
