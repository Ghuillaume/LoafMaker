#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

#include "ListOfTasks.hpp"
#include "ListsAndTemplates.hpp"

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    
private:
    ListOfTasks* listOfTasks;
    ListsAndTemplates* listsAndTemplates;
};

#endif // WINDOW_HPP
