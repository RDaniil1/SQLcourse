QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addentrydestination.cpp \
    addentrydriver.cpp \
    addentryroutesheet.cpp \
    addentryvehicle.cpp \
    deleteentrydestination.cpp \
    deleteentrydriver.cpp \
    deleteentryroutesheet.cpp \
    deleteentryvehicle.cpp \
    editentrydestination.cpp \
    editentrydriver.cpp \
    editentryroutesheet.cpp \
    editentryvehicle.cpp \
    entry1dialog.cpp \
    entry2dialog.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    addentrydestination.h \
    addentrydriver.h \
    addentryroutesheet.h \
    addentryvehicle.h \
    deleteentrydestination.h \
    deleteentrydriver.h \
    deleteentryroutesheet.h \
    deleteentryvehicle.h \
    editentrydestination.h \
    editentrydriver.h \
    editentryroutesheet.h \
    editentryvehicle.h \
    entry1dialog.h \
    entry2dialog.h \
    login.h \
    mainwindow.h

FORMS += \
    addentrydestination.ui \
    addentrydriver.ui \
    addentryroutesheet.ui \
    addentryvehicle.ui \
    deleteentrydestination.ui \
    deleteentrydriver.ui \
    deleteentryroutesheet.ui \
    deleteentryvehicle.ui \
    editentrydestination.ui \
    editentrydriver.ui \
    editentryroutesheet.ui \
    editentryvehicle.ui \
    entry1dialog.ui \
    entry2dialog.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

