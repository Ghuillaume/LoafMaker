#include "List.hpp"


List::List(string name, Time* creationDate, bool ordered)
    : name(name), creationDate(creationDate), parent(NULL), ordered(ordered) {
}

List::List(string name, Time* creationDate, bool ordered, List* parent)
    : name(name), creationDate(creationDate), parent(parent), ordered(ordered) {
}

List::~List() {
    for(vector<List*>::iterator it = subLists.begin() ; it != subLists.end() ; it++) {
        delete (*it);
    }
    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        delete (*it);
    }
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

vector<List*> List::getAllLists() {
    return this->subLists;
}

List* List::getList(int row) {

    if(row > this->subLists.size()-1) {
        return NULL;
    }
    else {
        return this->subLists.at(row);
    }
}

vector<Task*> List::getAllTasks() {
    return this->tasks;
}

Task* List::getTask(int row) {

    if(row > this->tasks.size()-1) {
        return NULL;
    }
    else {
        return this->tasks.at(row);
    }
}

int List::getNbTasks() {
    int nbTasks = this->tasks.size();

    for(vector<List*>::iterator it = subLists.begin() ; it != subLists.end() ; it++) {
        nbTasks += (*it)->getNbTasks();
    }

    return nbTasks;
}

int List::getNbFinishedTasks() {
    int nbFinishedTasks = 0;

    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        if((*it)->isFinished())
            nbFinishedTasks++;
    }

    for(vector<List*>::iterator it = subLists.begin() ; it != subLists.end() ; it++) {
        nbFinishedTasks += (*it)->getNbFinishedTasks();
    }

    return nbFinishedTasks;
}

int List::getProgression() {

    int finishedTasks = 0;
    int nbTasks = 0;

    finishedTasks = this->getNbFinishedTasks();
    nbTasks = this->getNbTasks();

    int progression;

    if(finishedTasks == 0)
        progression = 0;
    else
        progression = (finishedTasks * 100) / nbTasks;

    return progression;
}

void List::addSubList(List* subList) {
    this->subLists.push_back(subList);
}

void List::addTask(Task* task) {
    this->tasks.push_back(task);
}

/*
void List::addTask(Task *task, int number) {
    this->tasks.insert(number, task);
}*/

string List::toString() {
    return this->name + " (" + this->creationDate->getReadableDate() + ")";
}


void List::debug(string indent) {

    indent += "\t";

    // Affichage de la liste courante
    cout << indent << this->toString() << " ### " << this << endl;

    // Recherche de sous listes
    for(vector<List*>::iterator it = subLists.begin() ; it != subLists.end() ; it++) {
        (*it)->debug(indent);
    }

    // Recherche de tâches
    for(vector<Task*>::iterator it = tasks.begin() ; it != tasks.end() ; it++) {
        (*it)->debug(indent);
    }

}
