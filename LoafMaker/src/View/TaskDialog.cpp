#include "TaskDialog.hpp"

TaskDialog::TaskDialog(QWidget* parent):
    QDialog ( parent )
{

    this->setObjectName("Dialog");
    this->resize(500, 250);
    this->setWindowTitle(QString::fromUtf8("Créer une nouvelle tâche"));

    frame = new QWidget(this);
    frame->setObjectName("frame");
    frame->setGeometry(QRect(10, 10, 500, 250));

    formLayoutWidget = new QWidget(frame);
    formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
    formLayoutWidget->setGeometry(QRect(10, 10, 450, 230));
    formLayoutWidget->setMinimumSize(450, 230);
    formLayout = new QFormLayout(formLayoutWidget);
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setContentsMargins(0, 0, 0, 0);


    // Display labels
    intituleLabel = new QLabel(formLayoutWidget);
    intituleLabel->setObjectName("intituleLabel");
    intituleLabel->setText(QString::fromUtf8("Intitulé :"));
    formLayout->setWidget(0, QFormLayout::LabelRole, intituleLabel);

    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(1, QFormLayout::SpanningRole, horizontalSpacer1);

    dateLabel = new QLabel(formLayoutWidget);
    dateLabel->setObjectName("dateLabel");
    dateLabel->setText(QString::fromUtf8("Deadline :"));
    formLayout->setWidget(2, QFormLayout::LabelRole, dateLabel);

    QSpacerItem *horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(5, QFormLayout::SpanningRole, horizontalSpacer2);

    requiredLabel = new QLabel(formLayoutWidget);
    requiredLabel->setObjectName("requiredLabel");
    requiredLabel->setText(QString::fromUtf8("Dépend de :"));
    formLayout->setWidget(6, QFormLayout::LabelRole, requiredLabel);

    QSpacerItem *horizontalSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(7, QFormLayout::SpanningRole, horizontalSpacer3);


    // Display parameters edition

    intituleEdit = new QLineEdit(formLayoutWidget);
    intituleEdit->setObjectName(QString::fromUtf8("intituleEdit"));
    formLayout->setWidget(0, QFormLayout::FieldRole, intituleEdit);

    checkboxLayout = new QHBoxLayout();
    absoluteRadio = new QRadioButton(formLayoutWidget);
    absoluteRadio->setText(QString::fromUtf8("Absolue"));
    QObject::connect(absoluteRadio, SIGNAL(clicked()), this, SLOT(setAbsoluteDeadline()));
    checkboxLayout->addWidget(absoluteRadio);
    relativeRadio = new QRadioButton(formLayoutWidget);
    relativeRadio->setText(QString::fromUtf8("Relative"));
    QObject::connect(relativeRadio, SIGNAL(clicked()), this, SLOT(setRelativeDeadline()));
    checkboxLayout->addWidget(relativeRadio);
    formLayout->setLayout(2, QFormLayout::FieldRole, checkboxLayout);
    absoluteRadio->setChecked(true);


    absoluteDateEdit = new QDateEdit(formLayoutWidget);
    absoluteDateEdit->setCalendarPopup(true);
    absoluteDateEdit->setDate(QDate::currentDate());
    formLayout->setWidget(3, QFormLayout::FieldRole, absoluteDateEdit);

    relativeLayout = new QHBoxLayout();
    relativeLayout->setObjectName(QString::fromUtf8("relativeLayout"));
    nbDays = new QLineEdit(formLayoutWidget);
    nbDays->setObjectName(QString::fromUtf8("nbDays"));
    relativeLayout->addWidget(nbDays);

    daysLabel = new QLabel(formLayoutWidget);
    daysLabel->setObjectName(QString::fromUtf8("daysLabel"));
    relativeLayout->addWidget(daysLabel);

    relativeComboBox = new QComboBox(formLayoutWidget);
    relativeComboBox->setObjectName(QString::fromUtf8("relativeComboBox"));
    relativeLayout->addWidget(relativeComboBox);

    taskComboBox = new QComboBox(formLayoutWidget);
    taskComboBox->setObjectName(QString::fromUtf8("taskComboBox"));
    relativeLayout->addWidget(taskComboBox);

    daysLabel->setText(QApplication::translate("Dialog", "jours", 0, QApplication::UnicodeUTF8));
    relativeComboBox->clear();
    relativeComboBox->insertItems(0, QStringList()
     << QApplication::translate("Dialog", "avant", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("Dialog", "après", 0, QApplication::UnicodeUTF8)
    );

    formLayout->setLayout(4, QFormLayout::FieldRole, relativeLayout);

    setAbsoluteDeadline();

    QComboBox* firstRequiredTask = new QComboBox(formLayoutWidget);
    firstRequiredTask->insertItems(0, QStringList()
     << QApplication::translate("Dialog", "Ajouter une tâche", 0, QApplication::UnicodeUTF8)
    );
    formLayout->setWidget(6, QFormLayout::FieldRole, firstRequiredTask);

    //requiredTasks.push_back(firstRequiredTask);


    buttonBox = new QDialogButtonBox(formLayoutWidget);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    formLayout->setWidget(8, QFormLayout::FieldRole, buttonBox);

    QObject::connect(this->buttonBox, SIGNAL(accepted()), this, SLOT(checkFields()));
    QObject::connect(this->buttonBox, SIGNAL(rejected()), this, SLOT(close()));

}
/*
void TaskDialog::setArgs(Time* dateStart, Time* dateEnd, string intitule, string description) {
    dateStartEdit->setDate(QDate(dateStart->getYear(), dateStart->getMonth(), dateStart->getDay()));
    dateStartEdit->setTime(QTime(dateStart->getHour(), 0, 0));
    dateEndEdit->setDate(QDate(dateEnd->getYear(), dateEnd->getMonth(), dateEnd->getDay()));
    dateEndEdit->setTime(QTime(dateEnd->getHour(), 0, 0));
    this->titleEdit->setText(QString(intitule.c_str()));
    this->descriptionEdit->setText(QString(description.c_str()));
}*/


TaskDialog::~TaskDialog()
{

    delete frame;

/*
    delete formLayoutWidget;
    delete formLayout;
    delete dateEndEdit;
    delete titleEdit;
    delete descriptionEdit;
    delete buttonBox;*/
}

void TaskDialog::checkFields() {
    if(titleEdit->text().isEmpty())
        QMessageBox::warning(this, "Error", "You must fill at least the title field");
    else
        emit acceptedAndOk();
}

void TaskDialog::setRelativeDeadline() {

    nbDays->setVisible(true);
    daysLabel->setVisible(true);
    relativeComboBox->setVisible(true);
    taskComboBox->setVisible(true);

    absoluteDateEdit->setVisible(false);
}

void TaskDialog::setAbsoluteDeadline() {


    nbDays->setVisible(false);
    daysLabel->setVisible(false);
    relativeComboBox->setVisible(false);
    taskComboBox->setVisible(false);

    absoluteDateEdit->setVisible(true);
}
