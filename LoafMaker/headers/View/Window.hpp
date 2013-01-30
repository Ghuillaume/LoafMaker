#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMenu>

#include "ListOfTasks.hpp"
#include "ListsAndTemplates.hpp"

#define APP_WIDTH 900
#define APP_HEIGHT 600
#define LIST_PANEL_WIDTH 350
#define TASK_PANEL_WIDTH (APP_WIDTH - LIST_PANEL_WIDTH - PANELS_SEPARATOR_SIZE)
#define PANELS_SEPARATOR_SIZE 20

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    
private:
    QMenuBar* menubar;
    QMenu* fileMenu;
    QAction* newItem;
    QAction* openItem;
    QAction* saveItem;
    QAction* quitItem;

    QMenu* editMenu;
    QMenu* settingsMenu;

    QWidget *centralwidget;
    ListOfTasks* listOfTasks;
    ListsAndTemplates* listsAndTemplates;
};

#endif // WINDOW_HPP
