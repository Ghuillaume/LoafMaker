<<<<<<< HEAD
#include <string>
#include <vector>

#include "Task.hpp"
#include "../common.h"


typedef vector<Task*> ListOfTask;
=======
#ifndef LIST_HPP
#define LIST_HPP


#include "Task.hpp"
#include "common.h"

>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40

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

        string toString();
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
		
		
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
};

#endif
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
