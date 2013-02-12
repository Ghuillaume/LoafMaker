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
        void setDate(Time* date);
        void setOrdered(bool ordered);

        string getName();
        Time* getDate();
        vector<List*> getAllLists();
        vector<Task*> getAllTasks();
        List* getList(int row);
        Task* getTask(int row);

        int getNbTasks();
        int getNbFinishedTasks();
        int getProgression();
        bool isOrdered();
        List* getParent();

        void addSubList(List *subList);
        void addTask(Task* task);
        void removeTask(int row);

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
