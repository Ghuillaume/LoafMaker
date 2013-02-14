#ifndef LISTOFTEMPLATES_HPP
#define LISTOFTEMPLATES_HPP

#include <QApplication>
#include <QMenu>
#include <QAction>
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
#include <QMessageBox>

#include "List.hpp"

#define BUTTON_SIZE 35

class ListsOfLists : public QWidget {

    Q_OBJECT

    public:
        explicit ListsOfLists(QWidget *parent = 0);
        ~ListsOfLists();

        void setContextMenu();

        void displayList(vector<List*> lists, QTreeWidgetItem* parent);
        void clearList();

        QTreeWidget* getTree();
        void setCurrentList(List* list);

        List* currentList;

        QPushButton* buttonAddList;
        QPushButton* buttonEditList;
        QPushButton* buttonDelList;

        QMenu* contextMenu;
        QAction* addListAction;
        QAction* editListAction;
        QAction* deleteListAction;

    private:
        QVBoxLayout* mainLayout;
        QHBoxLayout* gridLayout;
        QFrame* horizontalLine;
        QTreeWidget* listsTree;

    signals:

    public slots:

};

#endif
