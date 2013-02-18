#include <QtGui/QApplication>

#include "Window.hpp"
#include "TaskDialog.hpp"
#include "Model.hpp"
#include "Controller.hpp"
#include "Time.hpp"
#include "XmlParser.hpp"
#include "XmlWriter.hpp"

using namespace std;

void testing(Model* m) {

    m->createBaseList("test1", 5, 1, 2013, false);
    m->createBaseList("test2", 5, 2, 2013, false);
    m->createBaseList("test3", 6, 2, 2013, false);

    m->createSubList(m->getList(0), "subtest1", 10, 5, 2013, false);
    m->createSubList(m->getList(0), "subtest2", 11, 5, 2013, true);
    m->createSubList(m->getList(0), "subtest3", 12, 5, 2013, false);

    m->createSubList(m->getList(0)->getList(1), "subsubtest1", 10, 5, 2013, false);
    m->createSubList(m->getList(0)->getList(1), "subsubtest2", 11, 5, 2013, false);

    m->createTask(m->getList(0)->getList(1), "task1", 6, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task2", 5, 6, 6666);
    m->createTask(m->getList(0)->getList(1), "task3", 4, 6, 6666);

    m->getList(0)->getList(1)->getTask(1)->setFinished();

    m->getList(0)->getList(1)->getTask(2)->setRelativeDate(m->getList(0)->getList(1)->getTask(1), +3);

    m->deleteList(2);

    m->debug();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model* m = new Model();

    testing(m);

    Window w;
    Controller c(m, &w);
    c.displayLists();

    w.show();

    
    return a.exec();
}
