#include "../../headers/View/ListsAndTemplates.hpp"

ListsAndTemplates::ListsAndTemplates(QWidget *parent) : QWidget(parent) {

    //this->resize(800, 400);
    gridLayout = new QGridLayout(this);

    /* List part */
    listLabel = new QLabel("Mes listes", this);
    listLabel->setGeometry(QRect(10, 30, 300, 20));
    gridLayout->addWidget(listLabel,0, 0, 1, 1);

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8(":list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddList = new QPushButton(iconAdd, QString("Ajouter"), this);
    buttonAddList->setIcon(iconAdd);
    gridLayout->addWidget(buttonAddList,0, 1, 1, 1);

    buttonDelList = new QPushButton(iconDelete, QString("Enlever"), this);
    buttonDelList->setIcon(iconDelete);
    gridLayout->addWidget(buttonDelList,0, 2, 1, 1);

    listsTree = new QTreeWidget(this);
    /*QTreeWidgetItem* treeHeader1;
    treeHeader1 = listsTree->headerItem();
    treeHeader1->setHidden(true);*/
    listsTree->setGeometry(QRect(10, 60, 300, 290));
    listsTree->setAnimated(true);
    gridLayout->addWidget(listsTree,1, 0, 1, 3);

}

ListsAndTemplates::~ListsAndTemplates() {
    delete listLabel;
    delete listsTree;
    delete gridLayout;
}

void ListsAndTemplates::displayList(vector<List *> lists, QTreeWidgetItem *parent) {

    // Ajout du header
    QTreeWidgetItem* treewidgetitem;
    treewidgetitem = listsTree->headerItem();
    treewidgetitem->setText(0, QString::fromUtf8("Mes Listes de tâches"));

    int level = 0;

    for(vector<List*>::iterator it = lists.begin() ; it != lists.end() ; it++) {

        QTreeWidgetItem* listItem;

        // Si pas de parent, alors ce sont des listes de niveau 0
        if(parent == NULL) {
            listItem = new QTreeWidgetItem(listsTree);
            listItem = listsTree->topLevelItem(level);
        }

        // Sinon, ce sont des enfants de QTreeWidget
        else {
            listItem = new QTreeWidgetItem(parent);
            listItem = parent->child(level);
        }

        ostringstream taskLabel;
        taskLabel << (*it)->getName() << " (" << (*it)->getNbTasks() << ")";

        listItem->setText(0, tr(taskLabel.str().c_str()));

        // Recherche de sous listes sur la liste courante
        this->displayList((*it)->getAllLists(), listItem);

        level++;
    }
}

void ListsAndTemplates::clearList() {
    this->listsTree->clear();
}

QTreeWidget* ListsAndTemplates::getTree() {
    return this->listsTree;
}

void ListsAndTemplates::setCurrentList(List* list) {
    this->currentList = list;
}
