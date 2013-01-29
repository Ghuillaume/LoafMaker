#include <QtGui/QApplication>
#include "Window.hpp"
#include "Model.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();

    Model* m = new Model();

    m->createBaseList("test1", 5, 1, 2013);
    m->createBaseList("test2", 5, 2, 2013);
    m->createBaseList("test3", 6, 2, 2013);

    m->createSubList(m->getList(0), "subtest1", 10, 5, 2013);
    m->createSubList(m->getList(0), "subtest2", 11, 5, 2013);
    m->createSubList(m->getList(0), "subtest3", 12, 5, 2013);

    m->createSubList(m->getList(0)->getList(1), "subsubtest1", 10, 5, 2013);
    m->createSubList(m->getList(0)->getList(1), "subsubtest2", 11, 5, 2013);

    m->createTask(m->getList(0)->getList(1), "task1", 6, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task2", 5, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task3", 4, 6, 6666);

    m->debug();
    
    return a.exec();
}
