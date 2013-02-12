#ifndef STARTVIEW_HPP
#define STARTVIEW_HPP

#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>

using namespace std;

class StartView : public QWidget
{
    Q_OBJECT

    public:
        explicit StartView(QWidget *parent = 0);
        ~StartView();


    private:
        QVBoxLayout* startLayout;
        QWidget* logoWidget;
        QLabel* title;
        QLabel* text;

    signals:

    public slots:


};
#endif // STARTVIEW_HPP
