#include "List.hpp"


<<<<<<< HEAD
List::List() {
    parent = NULL;
    ordered = false;
=======
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

string List::toString() {
    return "lol"; //this->name + " - " + this->creationDate->getDay() + "/" + this->creationDate->getMonth() + "/" + this->creationDate->getYear();
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
}
