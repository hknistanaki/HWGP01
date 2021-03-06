QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    RenderArea.cpp \
    Shape.cpp \
    addshape.cpp \
    circle.cpp \
    comments.cpp \
    contactus.cpp \
    deleteshape.cpp \
    ellipse.cpp \
    line.cpp \
    logindialog.cpp \
    main.cpp \
    mainwindow.cpp \
    modifyshapes.cpp \
    parser.cpp \
    polygon.cpp \
    polyline.cpp \
    rectangle.cpp \
    serializer.cpp \
    shapelisting.cpp \
    square.cpp \
    text.cpp

HEADERS += \
    Ellipse.h \
    Line.h \
    Polygon.h \
    Rectangle.h \
    RenderArea.h \
    Shape.h \
    Text.h \
    addshape.h \
    circle.h \
    comments.h \
    contactus.h \
    deleteshape.h \
    logindialog.h \
    mainwindow.h \
    modifyshapes.h \
    parser.h \
    polyline.h \
    serializer.h \
    shapelisting.h \
    square.h \
    vector.h

FORMS += \
    addshape.ui \
    comments.ui \
    contactus.ui \
    deleteshape.ui \
    logindialog.ui \
    mainwindow.ui \
    modifyshapes.ui \
    shapelisting.ui

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

