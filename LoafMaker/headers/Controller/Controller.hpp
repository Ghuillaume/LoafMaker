#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QtGui>
#include <QObject>
#include <QTimer>

#include <stack>
#include <string>

#include "Model.hpp"
#include "Window.hpp"
#include "TaskDialog.hpp"
#include "ListDialog.hpp"
#include "XmlParser.hpp"
#include "XmlWriter.hpp"

#define SAVE_MS 1000*6*5 // 5min

using namespace std;

class Controller : public QObject
{

    Q_OBJECT

    public:
        Controller(Model* model, Window* window);
        ~Controller();

        Task* getCurrentTask();


    private:
        Model* model;
        Window* view;

        QTimer* saveTimer;

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

        void addList();
        void editList();
        void delList();
        void addTask();
        void delTask();
        void editTask();

};

#endif // CONTROLLER_HPP
