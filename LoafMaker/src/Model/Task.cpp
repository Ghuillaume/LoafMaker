#include "Task.hpp"

Task::Task(string name, Time* deadline) {
    this->name = name;
    this->deadline = deadline;
    this->finished = false;
}

Task::~Task() {


}


string Task::getName() {
    return this->name;
}

string Task::getDate() {
    return this->deadline->getReadableDate();
}

string Task::getState() {
    return (this->finished ? "OK" : "");
}


void Task::setFinished() {
    this->finished = true;
}

void Task::setUnfinished() {
    this->finished = false;
}

bool Task::isFinished() {
    return this->finished;
}

void Task::debug(string indent) {
    indent += "\t";
    cout << indent << this->name << " - " << this->deadline->getReadableDate() << " -> " << (finished ? "finished" : "not finished") << " ### " << this << endl;
}
