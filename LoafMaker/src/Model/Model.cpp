#include "Model.hpp"

Model::Model() {
    this->current_filename = "./default.xml";
}

Model::~Model() {


}


void Model::clearModel() {
    this->lists.clear();
}


void Model::createRootList(List* rootList) {
    this->lists.push_back(rootList);
}

void Model::createBaseList(string name, int day, int month, int year, bool ordered) {
    Time* date = new Time(-1, -1 , day, month, year);
    this->lists.push_back(new List(name, date, ordered));
}


void Model::createTemplate(string name, int day, int month, int year, bool ordered) {
    Time* date = new Time(-1, -1 , day, month, year);
    this->templates.push_back(new List(name, date, ordered));
}

void Model::createSubList(List* parent, string name, int day, int month, int year, bool ordered) {
    Time* date = new Time(-1, -1 , day, month, year);
    parent->addSubList(new List(name, date, ordered, parent));

}

void Model::deleteList(int row) {
    //delete this->lists.at(row);
    if(row >= lists.size()) {
        cout << "Bug while deleting list. Row " << row << " but only " << lists.size() << "lists" << endl;
    }
    else {
        cout << "Deleting list" << endl;
        this->lists.erase(this->lists.begin()+row);
    }
}

void Model::createTask(List* parent, string name, int day, int month, int year) {
    Time* date = new Time(-1, -1 , day, month, year);
    parent->addTask(new Task(name, date));

}

void Model::deleteTask(List* list, int row) {
    cout << "Deleting task " << list->getTask(row)->getName() << " in list " << list->getName() << endl;

    list->removeTask(row);
}

ListOfList Model::getBaseLists() {
    return this->lists;
}

ListOfList Model::getTemplates() {
    return this->templates;
}

List* Model::getList(int row) {
    if(row > this->lists.size()-1) {
        return NULL;
    }
    else {
        return this->lists.at(row);
    }
}


void Model::debug() {

    cout << "Debugging model. Length is " << lists.size() << endl;

    for(ListOfList::iterator it = lists.begin() ; it != lists.end() ; it++) {
        (*it)->debug("");
    }

}
