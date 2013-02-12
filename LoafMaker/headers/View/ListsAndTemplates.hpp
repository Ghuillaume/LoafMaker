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
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "List.hpp"

#define BUTTON_SIZE 50

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
        QPushButton* buttonEditList;
        QPushButton* buttonDelList;

    private:
        QVBoxLayout* mainLayout;
        QHBoxLayout* gridLayout;
        QFrame* horizontalLine;
        QTreeWidget* listsTree;

    signals:

    public slots:

};

#endif
