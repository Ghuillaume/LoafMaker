#include "Controller.hpp"

Controller::Controller(Model* model, Window* window)
{
    this->model = model;
    this->view = window;

    // Menubar connections
    QObject::connect(view -> newItem, SIGNAL(activated()), this, SLOT(newModel()));
    QObject::connect(view -> saveItem, SIGNAL(activated()), this, SLOT(saveModel()));
    QObject::connect(view -> openItem, SIGNAL(activated()), this, SLOT(loadModel()));
    QObject::connect(view -> quitItem, SIGNAL(activated()), this, SLOT(close()));

    QObject::connect(view->createListItem, SIGNAL(triggered()), this, SLOT(addList()));
    QObject::connect(view->editListItem, SIGNAL(triggered()), this, SLOT(editList()));
    QObject::connect(view->deleteListItem, SIGNAL(triggered()), this, SLOT(delList()));

    QObject::connect(view->createTaskItem, SIGNAL(triggered()), this, SLOT(addTask()));
    QObject::connect(view->editTaskItem, SIGNAL(triggered()), this, SLOT(editTask()));
    QObject::connect(view->deleteTaskItem, SIGNAL(triggered()), this, SLOT(delTask()));

    // ListAndTemplates widget connections
    QObject::connect(this->view->getListsView()->getTree(), SIGNAL(itemSelectionChanged()), this, SLOT(setCurrentList()));
    QObject::connect(this->view->getListsView()->buttonAddList, SIGNAL(clicked()), this, SLOT(addList()));
    QObject::connect(this->view->getListsView()->buttonDelList, SIGNAL(clicked()), this, SLOT(delList()));


    // ListOfTasks widget connection
    QObject::connect(this->view->getTasksView()->buttonAddTask, SIGNAL(clicked()), this, SLOT(addTask()));
    QObject::connect(this->view->getTasksView()->buttonDelTask, SIGNAL(clicked()), this, SLOT(delTask()));
    QObject::connect(this->view->getTasksView()->buttonEditTask, SIGNAL(clicked()), this, SLOT(editTask()));

}

Controller::~Controller() {

}


void Controller::displayLists() {
    this->view->getListsView()->clearList();
    this->view->getListsView()->displayList(this->model->getBaseLists(), NULL);
}

void Controller::displayTemplates() {

}

void Controller::setCurrentList() {

    stack<int> path;

    QTreeWidget* tree = this->view->getListsView()->getTree();
    QTreeWidgetItem* current = tree->currentItem();
    QTreeWidgetItem* previous;

    // Retrieving path
    while(tree->indexOfTopLevelItem(current) == -1) {
        previous = current->parent();
        for(int i = 0 ; i < previous->childCount() ; i++) {
            if(previous->child(i) == current)
                path.push(i);
        }
        current = previous;
    }
    path.push(tree->indexOfTopLevelItem(current));


    // Retrieving list
    List* list = this->model->getList(path.top());
    List* selectedList = list;

    path.pop();

    while (!path.empty()) {
        selectedList = list->getList(path.top());
        path.pop();
        list = selectedList;
    }

    this->view->getListsView()->setCurrentList(selectedList);
    this->view->getTasksView()->setSelectedList(selectedList);
    this->view->getTasksView()->displayTasks();
}

void Controller::newModel() {
    // TODO : demander un fichier pour la nouvelle liste
    this->saveModel();
    this->model = new Model();

}

void Controller::saveModel() {
    string fileName = this->model->current_filename;
    this->parseModel(fileName);
}

void Controller::loadModel() {
    // TODO
}

void Controller::close() {
    if(QMessageBox::question(this->view, "Avertissement", QString::fromUtf8("Êtes-vous sûr(e) de vouloir quitter l'application ?"),
                             QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok) {
        this->saveModel();
        this->view->close();
    }
}

void Controller::parseModel(string fileName) {
    // TODO
    cout << "TODO : save model in " << fileName << endl;
}

void Controller::saveModelAs() {

    string fileName = QFileDialog::getSaveFileName(this->view, tr("Save File"), "/home", tr("XML Document (*.xml)")).toStdString();
    if(fileName.find(".xml") == string::npos)
        fileName += ".xml";

    if(fileName.compare(".xml") == 0)
        fileName = "default.xml";
    this->model->current_filename = fileName;
    this->parseModel(fileName);
}

void Controller::addList() {
    cout << "To finish" << endl;

    ListDialog* dialog = new ListDialog(this->view);
    dialog->show();
}

void Controller::editList() {
    cout << "To finish" << endl;

    ListDialog* dialog = new ListDialog(this->view);
    dialog->show();
}

void Controller::delList() {
    cout << "TODO : delList " << endl;
}

void Controller::addTask() {
    cout << "To Finish" << endl;

    TaskDialog* dialog = new TaskDialog(this->view);
    dialog->show();
}

void Controller::editTask() {
    cout << "To Finish" << endl;

    TaskDialog* dialog = new TaskDialog(this->view);
    dialog->show();
}

void Controller::delTask() {
    cout << "TODO : delTask" << endl;
}
