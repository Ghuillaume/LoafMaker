#include <string>
#include <vector>

#include "Task.hpp"
#include "../common.h"


typedef vector<Task*> ListOfTask;

class List {

	public:
		List();
		~List();
		
		
	private:
        string name;
        List* parent;
        string creationDate;
		
        bool ordered;
};
