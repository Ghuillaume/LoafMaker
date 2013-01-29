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
INCLUDEPATH += . headers/Model headers/Controller headers/View headers/Parser headers

SOURCES += main.cpp \
    src/View/Window.cpp \
    src/Controller/Controller.cpp \
    src/Model/List.cpp \
    src/Model/Task.cpp \
    src/Model/Model.cpp \
    src/Model/Time.cpp

HEADERS  += Window.hpp \
    headers/Model/List.hpp \
    headers/View/Window.hpp \
    Controller.hpp \
    headers/Controller/Controller.hpp \
    headers/common.h \
    headers/Model/Task.hpp \
    headers/Model/Model.hpp \
    headers/Model/Time.hpp
