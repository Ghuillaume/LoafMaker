#ifndef LIST_HPP
#define LIST_HPP


#include "common.h"
#include "Task.hpp"

class List {

public:
        List(string name, Time* creationDate, bool ordered);
        List(string name, Time* creationDate, bool ordered, List* parent);
~List();

        string getName();
        void setName(string name);
        Time* getDate();
        List* getList(int row);
        Task* getTask(int row);

        void addSubList(List *subList);
        void addTask(Task* task);

        string toString();

        void debug(string indent);


private:
        string name;
        List* parent;
        Time* creationDate;
        bool ordered;

        vector<Task*> tasks;
        vector<List*> subLists;
};

#endif
