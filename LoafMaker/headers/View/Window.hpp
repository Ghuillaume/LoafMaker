#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QSplitter>

#include <iostream>

#include "ListOfTasks.hpp"
#include "ListsOfLists.hpp"
#include "StartView.hpp"

#define APP_WIDTH 900
#define APP_HEIGHT 565
#define LIST_PANEL_WIDTH 250
#define TASK_PANEL_WIDTH (APP_WIDTH - LIST_PANEL_WIDTH - PANELS_SEPARATOR_SIZE)
#define PANELS_SEPARATOR_SIZE 20

using namespace std;

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

    void createMenuBar();

    ListsOfLists* getListsView();
    ListOfTasks* getTasksView();
    
    QMenuBar* menubar;
    QMenu* fileMenu;
    QAction* newItem;
    QAction* openItem;
    QAction* saveItem;
    QAction* quitItem;

    QMenu* listMenu;
    QAction* createListItem;
    QAction* editListItem;
    QAction* deleteListItem;

    QMenu* taskMenu;
    QAction* createTaskItem;
    QAction* editTaskItem;
    QAction* deleteTaskItem;

    QMenu* settingsMenu;

private:
    QWidget *centralWidget;
    QSplitter *splitter;
    ListOfTasks* listOfTasks;
    ListsOfLists* listsOfLists;
    StartView* startView;

public slots:
    void start();
};

#endif // WINDOW_HPP
