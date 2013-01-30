#include "../../headers/View/ListOfTasks.hpp"

ListOfTasks::ListOfTasks(int width, QWidget *parent) : QWidget(parent) {

    gridLayout = new QGridLayout(this);
    gridLayout->setColumnMinimumWidth(0, width/3);
    gridLayout->setColumnMinimumWidth(1, width/3);
    gridLayout->setColumnMinimumWidth(2, width/3);

    /* List presentation */
    QFont font;
    font.setBold(true);
    listNameLabel = new QLabel("", this);
    listNameLabel->setFont(font);
    gridLayout->addWidget(listNameLabel, 0, 0, 1, 2);

    /*
    spacerList = new QSpacerItem(width/3, 5);
    gridLayout->addItem(spacerList, 0, 1, 1, 1);
    */

    mainProgressbar = new QProgressBar(this);
    mainProgressbar->setValue(0);
    mainProgressbar->setVisible(false);
    gridLayout->addWidget(mainProgressbar, 0, 2, 1, 1);

    dateLabel = new QLabel("", this);
    dateLabel->setStyleSheet("QLabel { color : green; }");
    gridLayout->addWidget(dateLabel, 1, 0, 1, 3);


    tasksTree = new QTreeWidget(this);
    tasksTree->setGeometry(0, 0, width, 400);
    gridLayout->addWidget(tasksTree, 2, 0, 5, 3);
    QTreeWidgetItem* treeHeader1;
    treeHeader1 = tasksTree->headerItem();
    treeHeader1->setText(0, QString::fromUtf8("Intitulé"));
    QTreeWidgetItem* treeHeader2;
    treeHeader2 = tasksTree->headerItem();
    treeHeader2->setText(1, QString::fromUtf8("Échéance"));
    QTreeWidgetItem* treeHeader3;
    treeHeader3 = tasksTree->headerItem();
    treeHeader3->setText(2, QString::fromUtf8("État"));

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8("resources/edit-paste.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8("resources/applications-office.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8("resources/user-trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddTask = new QPushButton(iconAdd, QString::fromUtf8("Ajouter"), this);
    buttonAddTask->setIcon(iconAdd);
    buttonAddTask->setGeometry(1, 1, width/3, 20);
    gridLayout->addWidget(buttonAddTask, 8, 0, 1, 1);

    buttonEditTask = new QPushButton(iconAdd, QString::fromUtf8("Éditer"), this);
    buttonEditTask->setIcon(iconEdit);
    buttonEditTask->setGeometry(1, 1, width/3, 20);
    gridLayout->addWidget(buttonEditTask, 8, 1, 1, 1);

    buttonDelTask = new QPushButton(iconDelete, QString::fromUtf8("Enlever"), this);
    buttonDelTask->setIcon(iconDelete);
    buttonDelTask->setGeometry(1, 1, width/3, 20);
    gridLayout->addWidget(buttonDelTask, 8, 2, 1, 1);
}

ListOfTasks::~ListOfTasks(){
    delete listNameLabel;
    delete mainProgressbar;
    delete dateLabel;
    delete spacerList;

    delete tasksTree;
    delete treeHeader1;
    delete treeHeader2;
    delete treeHeader3;

    delete buttonAddTask;
    delete buttonEditTask;
    delete buttonDelTask;

    delete gridLayout;
}


void ListOfTasks::displayTasks() {

    listNameLabel->setText(QString(selectedList->getName().c_str()));
    mainProgressbar->setVisible(true);
    tasksTree->clear();

    dateLabel->setText(selectedList->getDate()->getReadableDate().c_str());

    vector<Task*> tasks = selectedList->getAllTasks();

    QTreeWidgetItem* taskItem;
    int level = 0;
    int finishedTasks = 0;
    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        taskItem = new QTreeWidgetItem(tasksTree);
        taskItem = tasksTree->topLevelItem(level);
        taskItem->setText(0, tr((*it)->getName().c_str()));
        taskItem->setText(1, tr((*it)->getDate().c_str()));
        taskItem->setText(2, tr((*it)->getState().c_str()));

        if((*it)->isFinished())
            finishedTasks++;

        level++;
    }

    int progression;

    if(finishedTasks == 0)
        progression = 0;
    else
        progression = (finishedTasks * 100) / tasks.size();

    mainProgressbar->setValue(progression);
}


void ListOfTasks::setSelectedList(List *list) {
    this->selectedList = list;
}
