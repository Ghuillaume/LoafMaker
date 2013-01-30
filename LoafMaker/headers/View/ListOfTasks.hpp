#ifndef LISTOFTASKS_HPP
#define LISTOFTASKS_HPP

#include <iostream>

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QSpacerItem>
#include <QTableWidget>
#include <QPushButton>
#include <QTableWidgetItem>

using namespace std;

class ListOfTasks : public QWidget
{
    Q_OBJECT
public:
    explicit ListOfTasks(int width, QWidget *parent = 0);
    ~ListOfTasks();

private:
    QGridLayout* gridLayout;

    QLabel* listNameLabel;
    QProgressBar* mainProgressbar;
    QSpacerItem* spacerList;
    QLabel* dateLabel;

    QTableWidget* tasksTable;
    QTableWidgetItem* taskColumn1;
    QTableWidgetItem* taskColumn2;
    QTableWidgetItem* taskColumn3;

    QPushButton* buttonAddTask;
    QPushButton* buttonEditTask;
    QPushButton* buttonDelTask;

signals:
    
public slots:
    
};

#endif
