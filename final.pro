QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += ./Inc


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Src/main.cpp \
    Src/mainwindow.cpp\
    Src/Device.cpp \
    Src/template_device.cpp \
    Src/Matter_commands.cpp \ 
    Src/utils.cpp  \
    Src/Lighting_window.cpp

HEADERS += \
    Inc/mainwindow.h \
    Inc/Device.h \
    Inc/template_device.h \
    Inc/Matter_commands.h \ 
    Inc/utils.h \
    Inc/Lighting_window.h

FORMS += \
    Ui/mainwindow.ui
    Ui/device.ui
    Ui/lighting_device.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
OBJECTS_DIR = $$PWD/build/obj
UI_DIR = $$PWD/Inc/ui_headers
MOC_DIR = $$PWD/build/moc_dir
RCC_DIR = $$PWD/build/qrc_sources
RESOURCES += \
    resources/resources.qrc
