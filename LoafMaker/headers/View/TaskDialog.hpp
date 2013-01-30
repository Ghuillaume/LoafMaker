#ifndef TASKDIALOG_HPP
#define TASKDIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGridLayout>

class TaskDialog : public QDialog {
    Q_OBJECT
public:
    explicit TaskDialog(QWidget *parent = 0);
    ~TaskDialog();

private:
    QDialogButtonBox* buttonBox;
    QFormLayout* formLayout;
    QLineEdit* nameLineEdit;
    QCheckBox* dateCheckbox;
    QLabel* timeRemainingLabel;
    QComboBox* numberCombobox;
    QComboBox* durationCombobox;
    QLabel* dependencyLabel;
    QHBoxLayout* timeHorizontalLayout;
    QGridLayout* dependencyLayout;
    QComboBox* dependencyCombobox1;
    QComboBox* dependencyCombobox2;
    QComboBox* dependencyCombobox3;

signals:

public slots:
};

#endif
