#ifndef _LISTDIALOG_HPP_
#define _LISTDIALOG_HPP_

#include <vector>

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>

#include "List.hpp"

using namespace std;

typedef vector<List*> ListOfList;

class ListDialog: public QDialog
{
    Q_OBJECT

    public:
        //ListDialog(QWidget *parent);
        ListDialog(QWidget *parent, ListOfList listOfList);
       ~ListDialog();


        vector<List*> listsAdded;

        QWidget *formLayoutWidget;
        QFormLayout *formLayout;
        QLineEdit *intituleEdit;
        QDateEdit *absoluteDateEdit;

        QLineEdit *nbDays;
        QCheckBox *orderedCheckBox;
        QComboBox *listComboBox;

        QDialogButtonBox *buttonBox;

        //void setArgs(Time* dateStart, Time* dateEnd, string intitule, string description);

    private:
        //Time time;

        QWidget *frame;

        QLabel *orderedLabel;
        QLabel *intituleLabel;
        QLabel *dateLabel;
        QLabel *requiredLabel;

        QHBoxLayout *checkboxLayout;

        void fillComboBox(ListOfList *listOfList, int level);

    public slots:
        void checkFields();

    signals:
        void acceptedAndOk();
};

#endif
