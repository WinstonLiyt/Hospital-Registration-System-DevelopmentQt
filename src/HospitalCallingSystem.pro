QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bscan.cpp \
    callingqueue.cpp \
    digitalclock.cpp \
    doctor.cpp \
    main.cpp \
    mainwindow.cpp \
    patient.cpp \
    welcomewindow.cpp

HEADERS += \
    bscan.h \
    callingqueue.h \
    digitalclock.h \
    doctor.h \
    mainwindow.h \
    patient.h \
    welcomewindow.h

FORMS += \
    mainwindow.ui \
    welcomewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic/doc.qrc \
    pic/hos2.qrc \
    pic/hospital.qrc \
    pic/logo.qrc \
    pic/nurse.qrc

RC_ICONS = pic/logo.ico
