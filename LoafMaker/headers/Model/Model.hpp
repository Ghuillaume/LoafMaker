#ifndef MODEL_HPP
#define MODEL_HPP

#include "common.h"

class Model
{
    public:
        Model();
        ~Model();

        void createBaseList(string name, int day, int month, int year);
        void createList(string name, int day, int month, int year, List* parent);
        void deleteList(string name);

        void createTask(List list, string name, Time date);
        void deleteTask(List list, string name);

        ListOfList getBaseLists();


    private:
        ListOfList lists;

};

#endif // MODEL_HPP
