#ifndef _TASKDIALOG_HPP_
#define _TASKDIALOG_HPP_

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QDialogButtonBox>
#include <QMessageBox>

class TaskDialog: public QDialog
{
    Q_OBJECT

    public:
        TaskDialog(QWidget *parent);
       ~TaskDialog();

        QWidget *formLayoutWidget;
        QFormLayout *formLayout;
        QDateTimeEdit *dateStartEdit;
        QDateTimeEdit *dateEndEdit;
        QLineEdit *titleEdit;
        QLineEdit *descriptionEdit;
        QLineEdit *locationEdit;
        QDialogButtonBox *buttonBox;

        //void setArgs(Time* dateStart, Time* dateEnd, string intitule, string description);

    private:
        //Time time;

        QWidget *frame;

        QLabel *dateStartLabel;
        QLabel *dateEndLabel;
        QLabel *titleLabel;
        QLabel *descriptionLabel;
        QLabel *locationLabel;

    public slots:
        void checkFields();

    signals:
        void acceptedAndOk();
};

#endif
