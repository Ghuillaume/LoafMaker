#include "../../headers/View/ListsAndTemplates.hpp"

ListsAndTemplates::ListsAndTemplates(QWidget *parent) : QWidget(parent) {
    gridLayout = new QGridLayout(this);

    listLabel = new QLabel();
    listLabel->setText("Listes");
    gridLayout->addWidget(listLabel,0, 0, 1, 1);

    listsTree = new QTreeWidget();
    gridLayout->addWidget(listsTree,1, 0, 1, 2);

    templateLabel = new QLabel();
    templateLabel->setText("Templates");
    gridLayout->addWidget(templateLabel,2, 0, 1, 1);

    templatesList = new QListWidget();
    gridLayout->addWidget(templatesList,3, 0, 1, 2);


}


ListsAndTemplates::~ListsAndTemplates() {
    delete listLabel;
    delete listsTree;
    delete templateLabel;
    delete templatesList;
    delete gridLayout;
}
