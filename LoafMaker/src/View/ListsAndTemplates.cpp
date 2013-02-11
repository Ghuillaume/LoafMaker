#include "../../headers/View/ListsAndTemplates.hpp"

ListsAndTemplates::ListsAndTemplates(QWidget *parent) : QWidget(parent) {

    //this->resize(800, 400);
    gridLayout = new QGridLayout(this);

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8(":edit.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8(":trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddList = new QPushButton(iconAdd, QString(""), this);
    buttonAddList->setIcon(iconAdd);
    gridLayout->addWidget(buttonAddList,0, 0, 1, 1);

    buttonEditList = new QPushButton(iconAdd, QString(""), this);
    buttonEditList->setIcon(iconEdit);
    gridLayout->addWidget(buttonEditList,0, 1, 1, 1);

    buttonDelList = new QPushButton(iconDelete, QString(""), this);
    buttonDelList->setIcon(iconDelete);
    gridLayout->addWidget(buttonDelList,0, 2, 1, 1);

    listsTree = new QTreeWidget(this);
    listsTree->setGeometry(QRect(10, 60, 300, 0));
    listsTree->setAnimated(true);
    gridLayout->addWidget(listsTree,1, 0, 1, 3);

}

ListsAndTemplates::~ListsAndTemplates() {
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
