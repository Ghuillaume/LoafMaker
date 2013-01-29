#include "Window.hpp"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    this->resize(800, 600);

    listOfTasks = new ListOfTasks(this);
    //listOfTasks->setGeometry(30, 5, 500,200);

    listsAndTemplates = new ListsAndTemplates(this);
}

Window::~Window()
{
}
