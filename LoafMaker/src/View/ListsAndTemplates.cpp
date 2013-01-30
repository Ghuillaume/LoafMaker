#include "../../headers/View/ListsAndTemplates.hpp"

ListsAndTemplates::ListsAndTemplates(QWidget *parent) : QWidget(parent) {

    //this->resize(800, 400);
    gridLayout = new QGridLayout(this);

    /* List part */
    listLabel = new QLabel("Mes listes", this);
    listLabel->setGeometry(QRect(10, 30, 300, 20));
    gridLayout->addWidget(listLabel,0, 0, 1, 1);

    QIcon iconAdd;
    iconAdd.addFile(QString::fromUtf8("resources/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
    QIcon iconDelete;
    iconDelete.addFile(QString::fromUtf8("resources/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);

    buttonAddList = new QPushButton(iconAdd, QString("Ajouter"), this);
    buttonAddList->setIcon(iconAdd);
    gridLayout->addWidget(buttonAddList,0, 1, 1, 1);

    buttonDelList = new QPushButton(iconDelete, QString("Enlever"), this);
    buttonDelList->setIcon(iconDelete);
    gridLayout->addWidget(buttonDelList,0, 2, 1, 1);

    listsTree = new QTreeWidget(this);
    treewidgetitem = new QTreeWidgetItem();
    listsTree->setHeaderItem(treewidgetitem);
    listsTree->header()->setVisible(false);
    listsTree->setGeometry(QRect(10, 60, 300, 290));
    gridLayout->addWidget(listsTree,1, 0, 1, 3);

    horizontalLine = new QFrame(this);
    horizontalLine->setObjectName(QString::fromUtf8("line"));
    horizontalLine->setGeometry(QRect(320, 150, 300, 4));
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setFrameShadow(QFrame::Sunken);
    gridLayout->addWidget(horizontalLine,2, 0, 1, 3);

    /* Template part */
    templateLabel = new QLabel("Mes templates", this);
    templateLabel->setGeometry(QRect(10, 400, 300, 20));
    gridLayout->addWidget(templateLabel,3, 0, 1, 1);

    buttonAddTemplate = new QPushButton(iconAdd, QString("Ajouter"), this);
    gridLayout->addWidget(buttonAddTemplate,3, 1, 1, 1);
    buttonDelTemplate = new QPushButton(iconDelete, QString("Enlever"), this);
    gridLayout->addWidget(buttonDelTemplate,3, 2, 1, 1);

    templatesList = new QListWidget(this);
    templatesList->setGeometry(QRect(10, 390, 300, 200));
    gridLayout->addWidget(templatesList,4, 0, 1, 3);
}


ListsAndTemplates::~ListsAndTemplates() {
    delete listLabel;
    delete listsTree;
    delete templateLabel;
    delete templatesList;
    delete treewidgetitem;
    delete gridLayout;
}
