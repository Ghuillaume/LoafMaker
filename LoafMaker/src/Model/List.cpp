#include "List.hpp"


List::List(string name, Time* creationDate, bool ordered)
    : name(name), creationDate(creationDate), parent(NULL), ordered(ordered) {
}

List::List(string name, Time* creationDate, bool ordered, List* parent)
    : name(name), creationDate(creationDate), parent(parent), ordered(ordered) {
}


string List::getName() {
    return this->name;
}

void List::setName(string name) {
    this->name = name;
}

Time* List::getDate() {
    return this->creationDate;
}

List* List::getList(int row) {

    if(row > this->subLists.size()-1) {
        return NULL;
    }
    else {
        return this->subLists.at(row);
    }
}

Task* List::getTask(int row) {

    if(row > this->tasks.size()-1) {
        return NULL;
    }
    else {
        return this->tasks.at(row);
    }
}

void List::addSubList(List* subList) {
    this->subLists.push_back(subList);
}

void List::addTask(Task* task) {
    this->tasks.push_back(task);
}

string List::toString() {
    return this->name + " (" + this->creationDate->getReadableDate() + ")";
}


void List::debug(string indent) {

    indent += "\t";

    // Affichage de la liste courante
    cout << indent << this->toString() << endl;

    // Recherche de sous listes
    for(vector<List*>::iterator it = subLists.begin() ; it != subLists.end() ; it++) {
        (*it)->debug(indent);
    }

    // Recherche de tâches
    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        (*it)->debug(indent);
    }

}
