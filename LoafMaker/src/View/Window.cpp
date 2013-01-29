#include "Window.hpp"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
<<<<<<< HEAD
    this->resize(800, 600);

    listOfTasks = new ListOfTasks(this);
    //listOfTasks->setGeometry(30, 5, 500,200);

    listsAndTemplates = new ListsAndTemplates(this);
=======
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
}

Window::~Window()
{
}
