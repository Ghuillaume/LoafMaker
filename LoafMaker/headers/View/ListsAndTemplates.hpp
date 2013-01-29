#ifndef LISTOFTEMPLATES_HPP
#define LISTOFTEMPLATES_HPP

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QTreeWidget>
#include <QListWidget>

class ListsAndTemplates : public QWidget
{
    Q_OBJECT
public:
    explicit ListsAndTemplates(QWidget *parent = 0);
    ~ListsAndTemplates();

private:
    QGridLayout* gridLayout;
    QLabel* listLabel;
    QTreeWidget *listsTree;
    QLabel* templateLabel;
    QListWidget *templatesList;

signals:

public slots:

};

#endif
