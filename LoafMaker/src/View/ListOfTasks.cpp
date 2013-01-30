#include "../../headers/View/ListOfTasks.hpp"

ListOfTasks::ListOfTasks(int width, QWidget *parent) : QWidget(parent) {
    gridLayout = new QGridLayout(this);

    /* List presentation */
    QFont font;
    font.setBold(true);
    listNameLabel = new QLabel("Liste", this);
    listNameLabel->setFont(font);
    gridLayout->addWidget(listNameLabel, 0, 0, 1, 1);

    spacerList = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout->addItem(spacerList, 0, 1, 1, 1);

    mainProgressbar = new QProgressBar(this);
    mainProgressbar->setValue(0);
    gridLayout->addWidget(mainProgressbar, 0, 2, 1, 1);

    dateLabel = new QLabel("01/01/1970", this);
    dateLabel->setStyleSheet("QLabel { color : green; }");
    gridLayout->addWidget(dateLabel, 1, 0, 1, 3);

    tasksTable = new QTableWidget(0, 3, this);
    tasksTable->setGeometry(0, 0, width, 1000);
    taskColumn1 = new QTableWidgetItem(QString::fromUtf8("Nom"));
    tasksTable->setHorizontalHeaderItem(0, taskColumn1);
    tasksTable->setColumnWidth(0,300);
    taskColumn2 = new QTableWidgetItem(QString::fromUtf8("Échéance"));
    tasksTable->setHorizontalHeaderItem(1, taskColumn2);
    tasksTable->setColumnWidth(1,105);
    taskColumn3 = new QTableWidgetItem(QString::fromUtf8("État"));
    tasksTable->setHorizontalHeaderItem(2, taskColumn3);
    tasksTable->setColumnWidth(2,103);
    gridLayout->addWidget(tasksTable, 2, 0, 5, 3);

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8("resources/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8("resources/applications-office.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8("resources/user-trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddTask = new QPushButton(iconAdd, QString::fromUtf8("Ajouter"), this);
    buttonAddTask->setIcon(iconAdd);
    gridLayout->addWidget(buttonAddTask, 8, 0, 1, 1);

    buttonEditTask = new QPushButton(iconAdd, QString::fromUtf8("Éditer"), this);
    buttonEditTask->setIcon(iconEdit);
    gridLayout->addWidget(buttonEditTask, 8, 1, 1, 1);

    buttonDelTask = new QPushButton(iconDelete, QString::fromUtf8("Enlever"), this);
    buttonDelTask->setIcon(iconDelete);
    gridLayout->addWidget(buttonDelTask, 8, 2, 1, 1);
}

ListOfTasks::~ListOfTasks(){
    delete listNameLabel;
    delete mainProgressbar;
    delete dateLabel;
    delete spacerList;

    delete tasksTable;
    delete taskColumn1;
    delete taskColumn2;
    delete taskColumn3;

    delete buttonAddTask;
    delete buttonEditTask;
    delete buttonDelTask;

    delete gridLayout;
}
