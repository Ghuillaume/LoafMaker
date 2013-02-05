#include "Model.hpp"

Model::Model() {
    this->current_filename = "./default.xml";
}

Model::~Model() {


}



void Model::createBaseList(string name, int day, int month, int year) {
    Time* date = new Time(-1, -1 , day, month, year);
    this->lists.push_back(new List(name, date, false));
}

void Model::createSubList(List* parent, string name, int day, int month, int year) {
    Time* date = new Time(-1, -1 , day, month, year);
    parent->addSubList(new List(name, date, false, parent));

}

void Model::deleteList(int row) {
    delete this->lists.at(row);
    this->lists.erase(this->lists.begin()+row);
}

void Model::createTask(List* parent, string name, int day, int month, int year) {
    Time* date = new Time(-1, -1 , day, month, year);
    parent->addTask(new Task(name, date));

}

void Model::deleteTask(List* list, int row) {

}

ListOfList Model::getBaseLists() {
    return this->lists;
}

List* Model::getList(int row) {
    if(row > this->lists.size()-1) {
        return NULL;
    }
    else {
        return this->lists.at(row);
    }
}


string Model::debug() {

    cout << "Debugging model. Length is " << lists.size() << endl;

    for(ListOfList::iterator it = lists.begin() ; it != lists.end() ; it++) {
        (*it)->debug("");
    }

}
