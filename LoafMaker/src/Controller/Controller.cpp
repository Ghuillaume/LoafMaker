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

    // ListAndTemplates widget connections
    QObject::connect(this->view->getListsView()->getTree(), SIGNAL(itemSelectionChanged()), this/*->view->getListsView()*/, SLOT(setCurrentList()));


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
    // Checking if current local changes are saved

    bool ok = true;
    switch(this->checkIfSaved()) {
        // Not saved but continue
        case 0:
            ok = true;
            break;

            // Not saved, stop
        case 1:
            ok = false;
            break;

            // Saved, ok
        case 2:
            ok = true;
            break;
    }

    if(ok) {
        this->model = new Model();
        /*
        this->model->cleanList();
        this->view->menubar->setVisible(false);
        this->view->mainFrame->setVisible(false);
        this->view->horizontalLayoutWidgetNewModel->setVisible(true);
        */
    }
}

void Controller::saveModel() {
    // TODO
    string fileName = "TODO"; //this->config->getFileName();
    cout << "Filename : " << fileName << endl;
    if(fileName.compare("") == 0) {
        cout << "parse with file name" << endl;
        this->parseModel(fileName);
    }
    else {
        cout << "Going to ask filename" << endl;
        this->saveModelAs();
    }
}

void Controller::loadModel() {
    // TODO

}

void Controller::close() {
    // TODO

    /* switch(this->checkIfSaved()) {

        // Not saved but continue
        case 0:
            this->view->close();
            break;

            // Not saved and stop exiting
        case 1:
            break;

            // Saved, ok
        case 2:
            if(QMessageBox::question(this, "Warning", "Are you sure ?", QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok) {
                this->view->close();
            }
            break;
    } */
    if(QMessageBox::question(this->view, "Avertissement", QString::fromUtf8("Êtes-vous sûr(e) de vouloir quitter l'application ?"),
                             QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok) {
        this->view->close();
    }
}

void Controller::parseModel(string fileName) {
    // TODO
}

void Controller::saveModelAs() {

    string fileName = QFileDialog::getSaveFileName(this->view, tr("Save File"), "/home", tr("XML Document (*.xml)")).toStdString();
    if(fileName.find(".xml") == string::npos)
        fileName += ".xml";
    //this->config->setFileName(fileName);
    this->parseModel(fileName);
}

int Controller::checkIfSaved() {
    // TODO : A CHANGER !!!
    if(true) {
        if(QMessageBox::warning(this->view, "Avertissement", QString::fromUtf8("Toutes les modifications n'ont pas été sauvegardées. Continuer ?"),
                                QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Cancel) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else
        return 2;

}
