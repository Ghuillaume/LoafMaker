#include "Task.hpp"

Task::Task(string name, Time* deadline) {
    this->name = name;
    this->deadline = deadline;
    this->finished = false;
    this->relativeDeadline = NULL;
    this->dayInterval = 0;
}

Task::~Task() {


}


string Task::getName() {
    return this->name;
}

Time* Task::getDeadline() {

    Time* deadline;

    if(this->relativeDeadline == NULL)
        deadline = new Time(this->deadline->getMinute(), this->deadline->getHour(), this->deadline->getDay(), this->deadline->getMonth(), this->deadline->getYear());

    else {
        deadline = this->relativeDeadline->getDeadline();
        if(dayInterval < 0) {
            for(int i = 0 ; i > dayInterval ; i--) {
                deadline->previousDay();
            }
        }
        else if(dayInterval > 0) {
            for(int i = 0 ; i < dayInterval ; i++) {
                deadline->nextDay();
            }
        }
    }

    return deadline;
}

string Task::getDate() {
    return this->getDeadline()->getReadableDate();
}

int Task::getRelativeDate() {
    return this->dayInterval;
}

string Task::getState() {
    return (this->finished ? "OK" : "");
}

int Task::getDayInterval() {
    return this->dayInterval;
}

vector<Task*> Task::getRequiredTasks() {
    return this->requiredTasks;
}

void Task::setName(string name) {
    this->name = name;
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

void Task::setRelativeDate(Task* relativeDeadline, int dayInterval) {
    this->deadline = NULL;

    this->relativeDeadline = relativeDeadline;
    this->dayInterval = dayInterval;
}

void Task::setAbsoluteDate(Time* deadline) {
    this->relativeDeadline = NULL;

    this->deadline = deadline;
}

void Task::addRequiredTask(Task* task) {
    this->requiredTasks.push_back(task);
}

void Task::removeRequiredTask(int row) {
    this->requiredTasks.erase(this->requiredTasks.begin()+row);
}

bool Task::isDeadlineRelative() {
    return (dayInterval != 0);
}

void Task::debug(string indent) {
    indent += "\t";
    cout << indent << this->name << " - " << this->getDeadline()->getReadableDate() << " -> " << (finished ? "finished" : "not finished") << " ### " << this << endl;
}
