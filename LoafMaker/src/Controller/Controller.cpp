#include "Controller.hpp"

Controller::Controller(Model* model, Window* window)
{
    this->model = model;
    this->view = window;

    // Menubar connections


    // ListAndTemplates widget connections


    // ListOfTasks widget connection

}

Controller::~Controller() {

}


void Controller::displayLists() {
    this->view->getListsView()->clearList();
    this->view->getListsView()->displayList(this->model->getBaseLists(), NULL);
}

void Controller::displayTemplates() {

}
