QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogajoutproduit.cpp \
    dialogajoutrayon.cpp \
    dialogancienmdp.cpp \
    dialogmodifproduit.cpp \
    dialogmodifrayon.cpp \
    dialogmodifuser.cpp \
    dialognouveaumdp.cpp \
    dialogrejet.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialogajoutproduit.h \
    dialogajoutrayon.h \
    dialogancienmdp.h \
    dialogmodifproduit.h \
    dialogmodifrayon.h \
    dialogmodifuser.h \
    dialognouveaumdp.h \
    dialogrejet.h \
    mainwindow.h

FORMS += \
    dialogajoutproduit.ui \
    dialogajoutrayon.ui \
    dialogancienmdp.ui \
    dialogmodifproduit.ui \
    dialogmodifrayon.ui \
    dialogmodifuser.ui \
    dialognouveaumdp.ui \
    dialogrejet.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
