#include <QtGui/QApplication>
#include "Window.hpp"
#include "Model.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
/*
    Model* m = new Model();

    m->createBaseList("test1", 5, 1, 2013);
    m->createBaseList("test2", 5, 2, 2013);
    m->createBaseList("test3", 6, 2, 2013);

    ListOfList l = m->getBaseLists();

    for(ListOfList::iterator it = l.begin() ; it != l.end() ; it++) {
        cout << (*it)->toString() << endl;
    }*/
    
    return a.exec();
}
