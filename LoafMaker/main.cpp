#include <QtGui/QApplication>
#include "Window.hpp"
#include "TaskDialog.hpp"
#include "Model.hpp"
#include "Controller.hpp"


void testing(Model* m) {

    m->createBaseList("test1", 5, 1, 2013);
    m->createBaseList("test2", 5, 2, 2013);
    m->createBaseList("test3", 6, 2, 2013);

    m->createSubList(m->getList(0), "subtest1", 10, 5, 2013);
    m->createSubList(m->getList(0), "subtest2", 11, 5, 2013);
    m->createSubList(m->getList(0), "subtest3", 12, 5, 2013);
    /*m->createSubList(m->getList(0), "subtest4", 13, 5, 2013);
    m->createSubList(m->getList(0), "subtest5", 14, 5, 2013);
    m->createSubList(m->getList(0), "subtest6", 15, 5, 2013);       BUG ICI !!!! pas possible d'ajouter d'autre sous listes, WHY??
    m->createSubList(m->getList(0), "subtest7", 16, 5, 2013);
    m->createSubList(m->getList(0), "subtest8", 17, 5, 2013);
    m->createSubList(m->getList(0), "subtest9", 18, 5, 2013);*/

    m->createSubList(m->getList(0)->getList(1), "subsubtest1", 10, 5, 2013);
    m->createSubList(m->getList(0)->getList(1), "subsubtest2", 11, 5, 2013);

    m->createTask(m->getList(0)->getList(1), "task1", 6, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task2", 5, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task3", 4, 6, 6666);

    m->getList(0)->getList(1)->getTask(1)->setFinished();

    //m->deleteList(1);

    m->debug();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Model* m = new Model();

    //testing(m);

    Window w;
    //Controller c(m, &w);
    //c.displayLists();

    /*
    TaskDialog taskDialog;
    taskDialog.exec();
    */
    w.show();

    
    return a.exec();
}
