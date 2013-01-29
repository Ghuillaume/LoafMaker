#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>

<<<<<<< HEAD
#include "ListOfTasks.hpp"
#include "ListsAndTemplates.hpp"
=======
namespace Ui {
class Window;
}
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40

class Window : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Window(QWidget *parent = 0);
    ~Window();
    
private:
<<<<<<< HEAD
    ListOfTasks* listOfTasks;
    ListsAndTemplates* listsAndTemplates;
=======
    Ui::Window *ui;
>>>>>>> 502dce7a137c0e1279e49f74e95a889cf99bdb40
};

#endif // WINDOW_HPP
