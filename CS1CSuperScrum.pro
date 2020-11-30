QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Shape.cpp \
    addshape.cpp \
    comments.cpp \
    contactus.cpp \
    deleteshape.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Ellipse.h \
    Line.h \
    Polygon.h \
    Rectangle.h \
    Shape.h \
    Text.h \
    addshape.h \
    comments.h \
    contactus.h \
    deleteshape.h \
    logindialog.h \
    mainwindow.h \
    vector.h

FORMS += \
    addshape.ui \
    comments.ui \
    contactus.ui \
    deleteshape.ui \
    logindialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/001-add.png \
    img/002-cancel.png \
    img/003-list.png \
    img/004-edit.png \
    img/comments \
    img/team logo.png

RESOURCES += \
    images.qrc

