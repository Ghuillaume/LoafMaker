
#include "../../headers/View/TaskDialog.hpp"

TaskDialog::TaskDialog(QWidget* parent) : QDialog(parent) {
    this->setObjectName("Dialog");
    this->resize(350,200);
    this->setWindowTitle(QString::fromUtf8("Éditer une tâche"));

    formLayout = new QFormLayout(this);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setContentsMargins(0, 0, 0, 0);

    nameLineEdit = new QLineEdit(this);
    formLayout->addRow(QString::fromUtf8("Nom"), nameLineEdit);

    dateCheckbox = new QCheckBox("Date", this);
    dateCheckbox->setChecked(false);
    formLayout->addWidget(dateCheckbox);

    timeHorizontalLayout = new QHBoxLayout(this);
    timeRemainingLabel = new QLabel("Temps restant :", this);
    timeHorizontalLayout->addWidget(timeRemainingLabel);
    numberCombobox = new QComboBox(this);
    for(int i = 1; i <= 30; i++) {
        numberCombobox->addItem(QString::number(i));
    }
    timeHorizontalLayout->addWidget(numberCombobox);
    durationCombobox = new QComboBox(this);
    durationCombobox->addItem("Jours");
    durationCombobox->addItem("Semaines");
    timeHorizontalLayout->addWidget(durationCombobox);
    if (!dateCheckbox->isChecked()) {
        timeRemainingLabel->setEnabled(false);
        numberCombobox->setEnabled(false);
        durationCombobox->setEnabled(false);
    }
    formLayout->addItem(timeHorizontalLayout);

    dependencyLayout = new QGridLayout(this);
    dependencyLabel = new QLabel(QString::fromUtf8("Dépend de :"), this);
    dependencyLayout->addWidget(dependencyLabel, 0, 0, 1, 1);
    dependencyCombobox1 = new QComboBox(this);
    dependencyCombobox1->addItem("Aucune");
    dependencyLayout->addWidget(dependencyCombobox1, 0, 1, 1, 1);
    dependencyCombobox2 = new QComboBox(this);
    dependencyCombobox2->addItem("Aucune");
    dependencyLayout->addWidget(dependencyCombobox2, 1, 1, 1, 1);
    dependencyCombobox3 = new QComboBox(this);
    dependencyCombobox3->addItem("Aucune");
    dependencyLayout->addWidget(dependencyCombobox3, 2, 1, 1, 1);
    formLayout->addItem(dependencyLayout);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    formLayout->addWidget(buttonBox);
}


TaskDialog::~TaskDialog() {
    delete nameLineEdit;
    delete dateCheckbox;
    delete timeRemainingLabel;
    delete numberCombobox;
    delete durationCombobox;
    delete dependencyLabel;
    delete dependencyCombobox1;
    delete dependencyCombobox2;
    delete dependencyCombobox3;
    delete buttonBox;

    delete timeHorizontalLayout;
    delete dependencyLayout;

    delete formLayout;
}
