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
              headers/View \
              src/Controller \
              src/Model \
              src/View

INCLUDEPATH += . headers/Model headers/Controller headers/View headers/Parser headers

SOURCES += main.cpp \
    src/View/Window.cpp \
    src/View/ListOfTasks.cpp \
    src/View/ListsAndTemplates.cpp
    src/Controller/Controller.cpp \
    src/Model/List.cpp \
    src/Model/Task.cpp \
    src/Model/Model.cpp \
    src/Model/Time.cpp

HEADERS  += headers/View/Window.hpp \
    headers/View/ListOfTasks.hpp \
    headers/View/ListsAndTemplates.hpp \
    headers/Controller/Controller.hpp \
    headers/common.h \
    headers/Model/List.hpp \
    headers/Model/Task.hpp \
    headers/Model/Model.hpp \
    headers/Model/Time.hpp
