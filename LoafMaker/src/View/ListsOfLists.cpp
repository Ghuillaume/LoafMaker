#include "ListsOfLists.hpp"

ListsOfLists::ListsOfLists(QWidget *parent) : QWidget(parent) {

    currentList = NULL;

    mainLayout = new QVBoxLayout(this);
    gridLayout = new QHBoxLayout();

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8(":edit.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8(":user-trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddList = new QPushButton(iconAdd, QString(""), this);
    buttonAddList->setIcon(iconAdd);
    buttonAddList->setIconSize(QSize(BUTTON_SIZE-15,BUTTON_SIZE-15));
    buttonAddList->setMinimumSize(BUTTON_SIZE,BUTTON_SIZE);
    buttonAddList->setMaximumSize(BUTTON_SIZE,BUTTON_SIZE);
    gridLayout->addWidget(buttonAddList);

    buttonEditList = new QPushButton(iconAdd, QString(""), this);
    buttonEditList->setIcon(iconEdit);
    buttonEditList->setMinimumSize(BUTTON_SIZE,BUTTON_SIZE);
    buttonEditList->setMaximumSize(BUTTON_SIZE,BUTTON_SIZE);
    buttonEditList->setIconSize(QSize(BUTTON_SIZE-15,BUTTON_SIZE-15));
    gridLayout->addWidget(buttonEditList);

    buttonDelList = new QPushButton(iconDelete, QString(""), this);
    buttonDelList->setIcon(iconDelete);
    buttonDelList->setMinimumSize(BUTTON_SIZE,BUTTON_SIZE);
    buttonDelList->setMaximumSize(BUTTON_SIZE,BUTTON_SIZE);
    buttonDelList->setIconSize(QSize(BUTTON_SIZE-15,BUTTON_SIZE-15));
    gridLayout->addWidget(buttonDelList);

    mainLayout->addLayout(gridLayout);

    listsTree = new QTreeWidget(this);
    listsTree->setGeometry(QRect(10, 60, 300, 0));
    listsTree->setAnimated(true);
    /* To allow drag & drop, use this :
    listsTree->dragDropOverwriteMode();
    listsTree->setDragEnabled(true);
    listsTree->setDragDropMode(QAbstractItemView ::InternalMove);
    */
    mainLayout->addWidget(listsTree);

    // Ajout du header
    QTreeWidgetItem* treewidgetitem;
    treewidgetitem = listsTree->headerItem();
    treewidgetitem->setText(0, QString::fromUtf8("Mes Listes de tâches"));

    this->setContextMenu();
}

ListsOfLists::~ListsOfLists() {
    delete listsTree;
    delete gridLayout;
}

void ListsOfLists::setContextMenu() {
    this->listsTree->setContextMenuPolicy(Qt::ActionsContextMenu);


    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconEdit;
    iconEdit.addFile(QString::fromUtf8(":edit.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8(":user-trash.png"), QSize(), QIcon::Normal, QIcon::Off);

    contextMenu = new QMenu(listsTree);
    addListAction = new QAction(iconAdd, QString::fromUtf8("Nouvelle liste"), contextMenu);
    addListAction->setIcon(iconAdd);
    this->listsTree->addAction(addListAction);

    editListAction = new QAction(iconEdit, QString::fromUtf8("Éditer"), contextMenu);
    editListAction->setIcon(iconEdit);
    editListAction->setEnabled(false);
    this->listsTree->addAction(editListAction);

    deleteListAction = new QAction(iconDelete, QString::fromUtf8("Supprimer"), contextMenu);
    deleteListAction->setIcon(iconDelete);
    deleteListAction->setEnabled(false);
    this->listsTree->addAction(deleteListAction);

}

void ListsOfLists::displayList(vector<List *> lists, QTreeWidgetItem *parent) {

    int level = 0;

    for(vector<List*>::iterator it = lists.begin() ; it != lists.end() ; it++) {

        cout << "Displaying " << (*it)->getName() << endl;

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

void ListsOfLists::clearList() {
    this->listsTree->clear();
}

QTreeWidget* ListsOfLists::getTree() {
    return this->listsTree;
}

void ListsOfLists::setCurrentList(List* list) {
    this->currentList = list;
}
