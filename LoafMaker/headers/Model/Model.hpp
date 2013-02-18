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

        void clearModel();

        string current_filename;

        void createRootList(List* rootList);
        void createBaseList(string name, int day, int month, int year, bool ordered);
        void createTemplate(string name, int day, int month, int year, bool ordered);
        void createSubList(List* parent, string name, int day, int month, int year, bool ordered);
        void deleteList(int row);

        void createTask(List* parent, string name, int day, int month, int year);
        void deleteTask(List* list, int row);

        ListOfList getBaseLists();
        ListOfList getTemplates();
        List* getList(int row);

        void debug();

    private:
        ListOfList lists;
        ListOfList templates;

};

#endif // MODEL_HPP
