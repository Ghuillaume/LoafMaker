#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T13:30:50
#
#-------------------------------------------------

QT       += core gui

TARGET = LoafMaker
TEMPLATE = app

DEPENDPATH += . \
              headers/Controller \
              headers/Model \
              headers/Parser \
              headers/View \
              src/Controller \
              src/Model \
              src/Parser \
              src/View
<<<<<<< HEAD
INCLUDEPATH += . headers/Model headers/Controller headers/View headers/Parser
=======
INCLUDEPATH += . headers/Model headers/Controller headers/View headers/Parser headers
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40

SOURCES += main.cpp \
    src/View/Window.cpp \
    src/Controller/Controller.cpp \
    src/Model/List.cpp \
    src/Model/Task.cpp \
<<<<<<< HEAD
    src/View/ListOfTasks.cpp \
    src/View/ListsAndTemplates.cpp
=======
    src/Model/Model.cpp \
    src/Model/Time.cpp
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40

HEADERS  += Window.hpp \
    headers/Model/List.hpp \
    headers/View/Window.hpp \
<<<<<<< HEAD
    headers/Controller/Controller.hpp \
    headers/common.h \
    headers/View/ListOfTasks.hpp \
    headers/View/ListsAndTemplates.hpp
=======
    Controller.hpp \
    headers/Controller/Controller.hpp \
    headers/common.h \
    headers/Model/Task.hpp \
    headers/Model/Model.hpp \
    headers/Model/Time.hpp
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
