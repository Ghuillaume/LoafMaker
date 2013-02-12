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
    requiredLabel->setText(QString::fromUtf8("Liste parente principale :"));
    formLayout->setWidget(1, QFormLayout::LabelRole, requiredLabel);


    requiredLabel2 = new QLabel(formLayoutWidget);
    requiredLabel2->setObjectName("requiredLabel2");
    requiredLabel2->setText(QString::fromUtf8("Liste parente secondaire :"));
    formLayout->setWidget(2, QFormLayout::LabelRole, requiredLabel2);


    dateLabel = new QLabel(formLayoutWidget);
    dateLabel->setObjectName("dateLabel");
    dateLabel->setText(QString::fromUtf8("Échéance :"));
    formLayout->setWidget(3, QFormLayout::LabelRole, dateLabel);

    orderedLabel = new QLabel(formLayoutWidget);
    orderedLabel->setObjectName("orderedLabel");
    orderedLabel->setText(QString::fromUtf8("Ordonnée ?"));
    formLayout->setWidget(4, QFormLayout::LabelRole, orderedLabel);

    QSpacerItem *horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    formLayout->setItem(5, QFormLayout::SpanningRole, horizontalSpacer2);


    // Display parameters edition

    intituleEdit = new QLineEdit(formLayoutWidget);
    intituleEdit->setObjectName(QString::fromUtf8("intituleEdit"));
    formLayout->setWidget(0, QFormLayout::FieldRole, intituleEdit);

    listListComboBox = new QComboBox(formLayoutWidget);
    listListComboBox->setObjectName(QString::fromUtf8("listComboBox"));
    formLayout->setWidget(1, QFormLayout::FieldRole, listListComboBox);

    listComboBox = new QComboBox(formLayoutWidget);
    listComboBox->setObjectName(QString::fromUtf8("listComboBox"));
    formLayout->setWidget(2, QFormLayout::FieldRole, listComboBox);

    absoluteDateEdit = new QDateEdit(formLayoutWidget);
    formLayout->setWidget(3, QFormLayout::FieldRole, absoluteDateEdit);


    buttonBox = new QDialogButtonBox(formLayoutWidget);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    formLayout->setWidget(6, QFormLayout::FieldRole, buttonBox);

    QObject::connect(this->buttonBox, SIGNAL(accepted()), this, SLOT(checkFields()));

    this->fillComboBox(&listOfList, 0);

}
/*
void ListDialog::setArgs(Time* dateStart, Time* dateEnd, string intitule, string description) {
    dateStartEdit->setDate(QDate(dateStart->getYear(), dateStart->getMonth(), dateStart->getDay()));
    dateStartEdit->setTime(QTime(dateStart->getHour(), 0, 0));
    dateEndEdit->setDate(QDate(dateEnd->getYear(), dateEnd->getMonth(), dateEnd->getDay()));
    dateEndEdit->setTime(QTime(dateEnd->getHour(), 0, 0));
    this->titleEdit->setText(QString(intitule.c_str()));
    this->descriptionEdit->setText(QString(description.c_str()));
}*/


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
                listName += "-";
            }
            listName += " " + listOfList->at(i)->getName();
            this->listListComboBox->addItem(QString::fromUtf8(listName.c_str()));
            ListOfList sublist = listOfList->at(i)->getAllLists();
            if(!sublist.empty()) {
                fillComboBox(&sublist, level + 1);
            }
        }
    }
}

void ListDialog::checkFields() {
    /*if(titleEdit->text().isEmpty())
        QMessageBox::warning(this, "Error", "You must fill at least the title field");
    else
        emit acceptedAndOk();*/
}