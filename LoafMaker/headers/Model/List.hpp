#ifndef LIST_HPP
#define LIST_HPP


#include "Task.hpp"
#include "common.h"


class List {

	public:
        List(string name, Time* creationDate, bool ordered);
        List(string name, Time* creationDate, bool ordered, List* parent);
		~List();

        string getName();
        void setName(string name);

        string toString();
		
		
	private:
        string name;
        List* parent;
        Time* creationDate;
		
        bool ordered;
};

#endif
