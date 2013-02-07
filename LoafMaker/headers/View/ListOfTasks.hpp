#ifndef LISTOFTASKS_HPP
#define LISTOFTASKS_HPP

#include <iostream>

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QSpacerItem>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>

#include "List.hpp"

using namespace std;

class ListOfTasks : public QWidget
{
    Q_OBJECT

    public:
        explicit ListOfTasks(QWidget *parent = 0);
        ~ListOfTasks();

        void displayTasks();
        void setSelectedList(List* list);


        QPushButton* buttonAddTask;
        QPushButton* buttonEditTask;
        QPushButton* buttonDelTask;

    private:
        List* selectedList;

        QGridLayout* gridLayout;

        QLabel* listNameLabel;
        QProgressBar* mainProgressbar;
        QSpacerItem* spacerList;
        QLabel* dateLabel;

        QTreeWidget* tasksTree;
        QTreeWidgetItem* treeHeader1;
        QTreeWidgetItem* treeHeader2;
        QTreeWidgetItem* treeHeader3;

    signals:


    public slots:
        void taskChanged(QTreeWidgetItem* item, int row);
};

#endif
