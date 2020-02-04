TEMPLATE = app
TARGET = SaaqGUI
QT += core \
    gui
HEADERS += confirmationsuppression.h \
    suppressioninterface.h \
    vehiculepromenadeinterface.h \
    camioninterface.h \
    saaqgui.h
SOURCES += confirmationsuppression.cpp \
    suppressioninterface.cpp \
    vehiculepromenadeinterface.cpp \
    camioninterface.cpp \
    main.cpp \
    saaqgui.cpp
FORMS += confirmationsuppression.ui \
    suppressioninterface.ui \
    vehiculepromenadeinterface.ui \
    camioninterface.ui \
    saaqgui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source"
