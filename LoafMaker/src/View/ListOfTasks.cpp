#include "../../headers/View/ListOfTasks.hpp"

ListOfTasks::ListOfTasks(QWidget *parent) : QWidget(parent) {

    selectedList = NULL;

    int parent_width = parent->width();
    int parent_height = parent->height();

    gridLayout = new QGridLayout(this);

    /* List presentation */
    QFont font;
    font.setBold(true);
    listNameLabel = new QLabel("", this);
    listNameLabel->setFont(font);
    listNameLabel->setMinimumSize(parent_width/3, 20);
    gridLayout->addWidget(listNameLabel, 0, 0, 1, 2);

    mainProgressbar = new QProgressBar(this);
    mainProgressbar->setValue(0);
    gridLayout->addWidget(mainProgressbar, 0, 2, 1, 1);

    dateLabel = new QLabel("Date", this);
    dateLabel->setStyleSheet("QLabel { color : green; }");
    dateLabel->setMinimumSize(parent_width/3, 20);
    gridLayout->addWidget(dateLabel, 1, 0, 1, 3);

    orderedLabel = new QLabel("", this);
    orderedLabel->setMinimumSize(parent_width/3, 20);
    gridLayout->addWidget(orderedLabel, 2, 0, 0, 0);


    tasksTree = new QTreeWidget(this);

    gridLayout->addWidget(tasksTree, 3, 0, 1, 3);
    QTreeWidgetItem* treeHeader1;
    treeHeader1 = tasksTree->headerItem();
    treeHeader1->setText(0, QString::fromUtf8("Intitulé"));
    QTreeWidgetItem* treeHeader2;
    treeHeader2 = tasksTree->headerItem();
    treeHeader2->setText(1, QString::fromUtf8("Échéance"));
    QTreeWidgetItem* treeHeader3;
    treeHeader3 = tasksTree->headerItem();
    treeHeader3->setText(2, QString::fromUtf8("Terminée"));

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8(":edit.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8(":user-trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    hboxLayout = new QHBoxLayout();

    buttonAddTask = new QPushButton(iconAdd, QString::fromUtf8("Ajouter"), this);
    buttonAddTask->setIcon(iconAdd);
    buttonAddTask->setMinimumWidth(parent_width/8);
    buttonAddTask->setMaximumWidth(parent_width/6);
    hboxLayout->addWidget(buttonAddTask);

    buttonEditTask = new QPushButton(iconAdd, QString::fromUtf8("Éditer"), this);
    buttonEditTask->setIcon(iconEdit);
    buttonEditTask->setMinimumWidth(parent_width/8);
    buttonEditTask->setMaximumWidth(parent_width/6);
    hboxLayout->addWidget(buttonEditTask);

    buttonDelTask = new QPushButton(iconDelete, QString::fromUtf8("Enlever"), this);
    buttonDelTask->setIcon(iconDelete);
    buttonDelTask->setMinimumWidth(parent_width/8);
    buttonDelTask->setMaximumWidth(parent_width/6);
    hboxLayout->addWidget(buttonDelTask);

    gridLayout->addLayout(hboxLayout, 5, 0, 1, 3);


    this->setContextMenu();
}

ListOfTasks::~ListOfTasks(){
    delete listNameLabel;
    delete mainProgressbar;
    delete dateLabel;

    delete tasksTree;
    delete treeHeader1;
    delete treeHeader2;
    delete treeHeader3;

    delete buttonAddTask;
    delete buttonEditTask;
    delete buttonDelTask;

    delete hboxLayout;
    delete gridLayout;
}

void ListOfTasks::setContextMenu() {
    this->tasksTree->setContextMenuPolicy(Qt::ActionsContextMenu);


    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);

    contextMenu = new QMenu(tasksTree);
    addTaskAction = new QAction(iconAdd, QString::fromUtf8("Nouvelle tâche"), contextMenu);
    addTaskAction->setIcon(iconAdd);
    this->tasksTree->addAction(addTaskAction);

    editTaskAction = new QAction(iconAdd, QString::fromUtf8("Éditer"), contextMenu);
    editTaskAction->setIcon(iconAdd);
    editTaskAction->setEnabled(false);
    this->tasksTree->addAction(editTaskAction);

    deleteTaskAction = new QAction(iconAdd, QString::fromUtf8("Supprimer"), contextMenu);
    deleteTaskAction->setIcon(iconAdd);
    deleteTaskAction->setEnabled(false);
    this->tasksTree->addAction(deleteTaskAction);

}

void ListOfTasks::displayTasks() {


    listNameLabel->setText(QString(selectedList->getName().c_str()));
    tasksTree->clear();

    if(this->selectedList->isOrdered()) {
        orderedLabel->setText(QString::fromUtf8("Cette liste est ordonnée. Vous devez valider chaque tâche dans l'ordre affiché"));
        //orderedLabel->setMinimumSize( 100, 20);
        tasksTree->setSortingEnabled(false);
    }
    else {
        orderedLabel->setText("");
        tasksTree->setSortingEnabled(true);
    }


    gridLayout->addWidget(orderedLabel, 1, 0, 1, 3);

    dateLabel->setText(selectedList->getDate()->getReadableDate().c_str());

    vector<Task*> tasks = selectedList->getAllTasks();

    QTreeWidgetItem* taskItem;
    int level = 0;
    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        taskItem = new QTreeWidgetItem(tasksTree);
        taskItem = tasksTree->topLevelItem(level);
        string taskName = (*it)->getName();
        if(this->selectedList->isOrdered()) {
            taskName = QString::number(level+1).toStdString() + ". " + taskName;
        }
        taskItem->setText(0, tr(taskName.c_str()));
        taskItem->setText(1, tr((*it)->getDate().c_str()));
        if((*it)->isFinished())
            taskItem->setCheckState(2, Qt::Checked);
        else
            taskItem->setCheckState(2, Qt::Unchecked);

        level++;
    }

    mainProgressbar->setValue(selectedList->getProgression());

    QObject::connect(tasksTree, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(taskChanged(QTreeWidgetItem*, int)));

}


void ListOfTasks::setSelectedList(List *list) {
    this->selectedList = list;
}


QTreeWidget* ListOfTasks::getList() {
    return this->tasksTree;
}


void ListOfTasks::taskChanged(QTreeWidgetItem *item, int row) {

    if(row == 2) {
        int line = this->tasksTree->indexOfTopLevelItem(item);
        Task* selectedTask = selectedList->getTask(line);

        if(item->checkState(row) == Qt::Checked){
            selectedTask->setFinished();
        }
        else {
            selectedTask->setUnfinished();
        }


        // maj progression
        vector<Task*> tasks = selectedList->getAllTasks();
        int finishedTasks = 0;
        for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
            if((*it)->isFinished())
                finishedTasks++;
        }

        int progression;

        if(finishedTasks == 0)
            progression = 0;
        else
            progression = (finishedTasks * 100) / tasks.size();

        mainProgressbar->setValue(progression);
    }
}
