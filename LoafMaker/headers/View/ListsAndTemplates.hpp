#ifndef LISTOFTEMPLATES_HPP
#define LISTOFTEMPLATES_HPP

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <QTreeWidget>
#include <QListWidget>
#include <QTreeWidgetItem>
#include <QHeaderView>
#include <QIcon>
#include <QPushButton>

#include "List.hpp"

class ListsAndTemplates : public QWidget {

    Q_OBJECT

    public:
        explicit ListsAndTemplates(QWidget *parent = 0);
        ~ListsAndTemplates();

        void displayList(vector<List*> lists, QTreeWidgetItem* parent);
        void clearList();

        QTreeWidget* getTree();
        void setCurrentList(List* list);

        List* currentList;

        QPushButton* buttonAddList;
        QPushButton* buttonDelList;

    private:
        QGridLayout* gridLayout;
        QFrame* horizontalLine;
        QLabel* listLabel;
        QTreeWidget* listsTree;

    signals:

    public slots:

};

#endif
