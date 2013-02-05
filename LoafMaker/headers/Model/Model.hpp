#ifndef MODEL_HPP
#define MODEL_HPP

#include "Task.hpp"
#include "List.hpp"

typedef vector<List*> ListOfList;
typedef vector<Task*> ListOfTask;

class Model
{
    public:
        Model();
        ~Model();

        string current_filename;

        void createBaseList(string name, int day, int month, int year);
        void createSubList(List* parent, string name, int day, int month, int year);
        void deleteList(int row);

        void createTask(List* parent, string name, int day, int month, int year);
        void deleteTask(List* list, int row);

        ListOfList getBaseLists();
        List* getList(int row);

        void debug();

    private:
        ListOfList lists;

};

#endif // MODEL_HPP
