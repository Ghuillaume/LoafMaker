#ifndef LISTOFTASKS_HPP
#define LISTOFTASKS_HPP

#include <iostream>

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>

#include "List.hpp"

using namespace std;

class ListOfTasks : public QWidget
{
    Q_OBJECT

    public:
        explicit ListOfTasks(QWidget *parent = 0);
        ~ListOfTasks();

        void setContextMenu();

        void displayTasks();
        void setSelectedList(List* list);

        QTreeWidget* getList();


        QPushButton* buttonAddTask;
        QPushButton* buttonEditTask;
        QPushButton* buttonDelTask;

        QMenu* contextMenu;
        QAction* addTaskAction;
        QAction* editTaskAction;
        QAction* deleteTaskAction;

    private:
        List* selectedList;

        QGridLayout* gridLayout;

        QLabel* listNameLabel;
        QProgressBar* mainProgressbar;
        QLabel* orderedLabel;
        QLabel* dateLabel;

        QHBoxLayout* hboxLayout;

        QTreeWidget* tasksTree;
        QTreeWidgetItem* treeHeader1;
        QTreeWidgetItem* treeHeader2;
        QTreeWidgetItem* treeHeader3;

    signals:


    public slots:
        void taskChanged(QTreeWidgetItem* item, int row);
};

#endif
