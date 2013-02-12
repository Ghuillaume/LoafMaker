#include "ListDialog.hpp"
#include "List.hpp"

ListDialog::ListDialog(QWidget* parent, ListOfList listOfList):
    QDialog ( parent )
{

    this->setObjectName("Dialog");
    this->resize(500, 220);
    this->setWindowTitle(QString::fromUtf8("Créer une nouvelle liste"));

    frame = new QWidget(this);
    frame->setObjectName("frame");
    frame->setGeometry(QRect(10, 10, 500, 220));

    formLayoutWidget = new QWidget(frame);
    formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
    formLayoutWidget->setGeometry(QRect(10, 10, 450, 200));
    formLayoutWidget->setMinimumSize(450, 200);
    formLayout = new QFormLayout(formLayoutWidget);
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setContentsMargins(0, 0, 0, 0);


    // Display labels
    intituleLabel = new QLabel(formLayoutWidget);
    intituleLabel->setObjectName("intituleLabel");
    intituleLabel->setText(QString::fromUtf8("Nom :"));
    formLayout->setWidget(0, QFormLayout::LabelRole, intituleLabel);

    requiredLabel = new QLabel(formLayoutWidget);
    requiredLabel->setObjectName("requiredLabel");
    requiredLabel->setText(QString::fromUtf8("Liste parente :"));
    formLayout->setWidget(1, QFormLayout::LabelRole, requiredLabel);

    QSpacerItem *horizontalSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(2, QFormLayout::SpanningRole, horizontalSpacer1);

    dateLabel = new QLabel(formLayoutWidget);
    dateLabel->setObjectName("dateLabel");
    dateLabel->setText(QString::fromUtf8("Échéance :"));
    formLayout->setWidget(3, QFormLayout::LabelRole, dateLabel);

    orderedLabel = new QLabel(formLayoutWidget);
    orderedLabel->setObjectName("orderedLabel");
    orderedLabel->setText(QString::fromUtf8("Options"));
    formLayout->setWidget(4, QFormLayout::LabelRole, orderedLabel);

    QSpacerItem *horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(5, QFormLayout::SpanningRole, horizontalSpacer2);


    // Display parameters edition

    intituleEdit = new QLineEdit(formLayoutWidget);
    intituleEdit->setObjectName(QString::fromUtf8("intituleEdit"));
    formLayout->setWidget(0, QFormLayout::FieldRole, intituleEdit);

    listComboBox = new QComboBox(formLayoutWidget);
    listComboBox->setObjectName(QString::fromUtf8("listComboBox"));
    formLayout->setWidget(1, QFormLayout::FieldRole, listComboBox);

    absoluteDateEdit = new QDateEdit(formLayoutWidget);
    absoluteDateEdit->setCalendarPopup(true);
    absoluteDateEdit->setDate(QDate::currentDate());
    formLayout->setWidget(3, QFormLayout::FieldRole, absoluteDateEdit);

    orderedCheckBox = new QCheckBox(formLayoutWidget);
    orderedCheckBox->setObjectName(QString::fromUtf8("checkBox"));
    orderedCheckBox->setText(QString::fromUtf8("Liste ordonnée"));
    formLayout->setWidget(4, QFormLayout::FieldRole, orderedCheckBox);



    buttonBox = new QDialogButtonBox(formLayoutWidget);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    formLayout->setWidget(6, QFormLayout::FieldRole, buttonBox);


    this->listComboBox->addItem(QString::fromUtf8("Aucune"));
    this->fillComboBox(&listOfList, 0);

    QObject::connect(this->buttonBox, SIGNAL(accepted()), this, SLOT(checkFields()));
    QObject::connect(this, SIGNAL(acceptedAndOk()), this, SLOT(accept()));
    QObject::connect(this->buttonBox, SIGNAL(rejected()), this, SLOT(close()));


}


void ListDialog::setArgs(string name, List* parent, Time* date, bool ordered) {
    this->intituleEdit->setText(name.c_str());
    int index = 0;
    this->listComboBox->setCurrentIndex(0);
    for(vector<List*>::iterator it = listsAdded.begin() ; it != listsAdded.end() ; it++) {
        if((*it) == parent)
            this->listComboBox->setCurrentIndex(index-1);
        index++;
    }


    this->absoluteDateEdit->setDate(QDate(date->getYear(), date->getMonth(), date->getDay()));

    if(ordered) {
        this->orderedCheckBox->setChecked(true);
    }
}


ListDialog::~ListDialog()
{
    delete frame;
}

void ListDialog::fillComboBox(ListOfList *listOfList, int level) {
    if (listOfList->empty()) {
        return;
    } else {
        for(int i = 0; i < listOfList->size(); i ++) {
            string listName =  "";
            for (int j = 0; j < level; j++) {
                listName += "--";
            }
            listName += " " + listOfList->at(i)->getName();
            this->listComboBox->addItem(QString::fromUtf8(listName.c_str()));
            this->listsAdded.push_back(listOfList->at(i));
            ListOfList sublist = listOfList->at(i)->getAllLists();
            if(!sublist.empty()) {
                fillComboBox(&sublist, level + 1);
            }
        }
    }
}

void ListDialog::checkFields() {
    if(intituleEdit->text().isEmpty())
        QMessageBox::warning(this, "Erreur", "Prout");
    else
        emit acceptedAndOk();
}
