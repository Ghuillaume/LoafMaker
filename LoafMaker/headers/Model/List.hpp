#ifndef LIST_HPP
#define LIST_HPP


#include "common.h"
#include "Task.hpp"

class List {

public:
        List(string name, Time* creationDate, bool ordered);
        List(string name, Time* creationDate, bool ordered, List* parent);
        ~List();

        void setName(string name);
        string getName();
        Time* getDate();
        vector<List*> getAllLists();
        vector<Task*> getAllTasks();
        List* getList(int row);
        Task* getTask(int row);

        int getNbTasks();
        int getNbFinishedTasks();
        int getProgression();

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
