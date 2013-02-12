#ifndef _TASKDIALOG_HPP_
#define _TASKDIALOG_HPP_

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


class TaskDialog: public QDialog
{
    Q_OBJECT

    public:
        TaskDialog(QWidget *parent);
       ~TaskDialog();

        QWidget *formLayoutWidget;
        QFormLayout *formLayout;
        QLineEdit *intituleEdit;
        QRadioButton *absoluteRadio;
        QRadioButton *relativeRadio;
        QDateEdit *absoluteDateEdit;

        QHBoxLayout *relativeLayout;
        QLineEdit *nbDays;
        QLabel *daysLabel;
        QComboBox *relativeComboBox;
        QComboBox *taskComboBox;

        //vector<QComboBox> requiredTasks;

        /*QLineEdit *titleEdit;
        QLineEdit *descriptionEdit;
        QLineEdit *locationEdit;*/
        QDialogButtonBox *buttonBox;

        //void setArgs(Time* dateStart, Time* dateEnd, string intitule, string description);

    private:
        //Time time;

        QWidget *frame;

        QLabel *intituleLabel;
        QLabel *dateLabel;
        QLabel *requiredLabel;

        QHBoxLayout *checkboxLayout;

    public slots:
        void checkFields();
        void setRelativeDeadline();
        void setAbsoluteDeadline();

    signals:
        void acceptedAndOk();
};

#endif
