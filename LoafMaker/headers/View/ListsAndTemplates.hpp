#ifndef LISTOFTEMPLATES_HPP
#define LISTOFTEMPLATES_HPP

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

class ListsAndTemplates : public QWidget {
    Q_OBJECT
public:
    explicit ListsAndTemplates(QWidget *parent = 0);
    ~ListsAndTemplates();

private:
    QGridLayout* gridLayout;
    QFrame* horizontalLine;
    QLabel* listLabel;
    QTreeWidget* listsTree;
    QLabel* templateLabel;
    QListWidget* templatesList;
    QTreeWidgetItem* treewidgetitem;
    QPushButton* buttonAddList;
    QPushButton* buttonDelList;
    QPushButton* buttonAddTemplate;
    QPushButton* buttonDelTemplate;

signals:

public slots:

};

#endif
