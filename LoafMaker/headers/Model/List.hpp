<<<<<<< HEAD
#include <string>
#include <vector>

#include "Task.hpp"
#include "../common.h"


typedef vector<Task*> ListOfTask;
=======
#ifndef LIST_HPP
#define LIST_HPP


#include "common.h"
<<<<<<< HEAD
#include "Task.hpp"
=======

>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
>>>>>>> 48280e334b5294ef7abb442c222166d82466a0a4

class List {

	public:
<<<<<<< HEAD
		List();
		~List();
=======
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
<<<<<<< HEAD

        void debug(string indent);
=======
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
>>>>>>> 48280e334b5294ef7abb442c222166d82466a0a4
		
		
	private:
        string name;
        List* parent;
<<<<<<< HEAD
        string creationDate;
		
        bool ordered;
};
=======
        Time* creationDate;
        bool ordered;

        vector<Task*> tasks;
        vector<List*> subLists;
};

#endif
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
