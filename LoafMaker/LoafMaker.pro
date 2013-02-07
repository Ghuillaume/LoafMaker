######################################################################
# Automatically generated by qmake (2.01a) Tue Jan 29 17:51:33 2013
######################################################################

QT       += core gui

TARGET = LoafMaker
TEMPLATE = app
RESOURCES = images.qrc

DEPENDPATH += . \
              headers \
              headers/Controller \
              headers/Model \
              headers/View \
              src/Controller \
              src/Model \
              src/View
INCLUDEPATH += . headers/View headers/Model headers headers/Controller

# Input
HEADERS += headers/common.h \
           headers/Controller/Controller.hpp \
           headers/Model/List.hpp \
           headers/Model/Model.hpp \
           headers/Model/Task.hpp \
           headers/Model/Time.hpp \
           headers/View/ListOfTasks.hpp \
           headers/View/ListsAndTemplates.hpp \
           headers/View/Window.hpp \
    headers/View/TaskDialog.hpp \
    headers/View/ListDialog.hpp
SOURCES += main.cpp \
           src/Controller/Controller.cpp \
           src/Model/List.cpp \
           src/Model/Model.cpp \
           src/Model/Task.cpp \
           src/Model/Time.cpp \
           src/View/ListOfTasks.cpp \
           src/View/ListsAndTemplates.cpp \
           src/View/Window.cpp \
    src/View/TaskDialog.cpp \
    src/View/ListDialog.cpp
