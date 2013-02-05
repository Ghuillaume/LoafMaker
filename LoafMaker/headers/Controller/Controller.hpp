#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QtGui>
#include <QObject>

#include <stack>
#include <cstring>

#include "Model.hpp"
#include "Window.hpp"

using namespace std;

class Controller : public QObject
{

    Q_OBJECT

    public:
        Controller(Model* model, Window* window);
        ~Controller();


    private:
        Model* model;
        Window* view;

    signals:

    public slots:
        void displayLists();
        void displayTemplates();
        void setCurrentList();
        void newModel();
        void saveModel();
        void loadModel();
        void close();
        void parseModel(string fileName);
        void saveModelAs();

};

#endif // CONTROLLER_HPP
