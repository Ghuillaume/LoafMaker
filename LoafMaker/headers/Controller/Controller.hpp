#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP


#include <QtGui>
#include <QObject>

#include <stack>

#include "Model.hpp"
#include "Window.hpp"

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

};

#endif // CONTROLLER_HPP
