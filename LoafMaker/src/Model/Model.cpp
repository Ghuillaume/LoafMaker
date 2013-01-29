#include "Model.hpp"

Model::Model() {


}

Model::~Model() {


}



void Model::createBaseList(string name, int day, int month, int year) {
    Time date = new Time(-1, -1 , day, month, year);
    this->lists.push_back(new List(name, date, false));
}

void Model::createList(string name, int day, int month, int year, List* parent) {
    Time date = new Time(-1, -1 , day, month, year);
    this->lists.push_back(new List(name, date, false, parent));

}

void Model::deleteList(string name) {

}

void Model::createTask(List list, string name, Time date) {

}

void Model::deleteTask(List list, string name) {

}
