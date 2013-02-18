#include "StartView.hpp"

StartView::StartView(QWidget *parent) : QWidget(parent) {
    startLayout = new QVBoxLayout(this);
    startLayout->setGeometry(QRect());

    logoWidget = new QWidget(this);
    logoWidget->setFixedSize(200,200);
    logoWidget->setObjectName(QString::fromUtf8("logoWidget"));
    logoWidget->setStyleSheet(QString::fromUtf8("border: 1px solid black"));
    logoWidget->setStyleSheet("background-image: url(:logo.png)");

    title = new QLabel(this);
    title->setWordWrap(true);
    title->setText(QString::fromUtf8("Bienvenue dans LoafMaker !"));
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    titleFont.setItalic(true);
    titleFont.setWeight(75);
    title->setFont(titleFont);

    text = new QLabel(this);
    text->setWordWrap(true);
    text->setText(QString::fromUtf8("Pour visualisez vos tâches ou en créer de nouvelles, sélectionnez ou créez une liste de tâche à gauche de l'écran."));


    startLayout->addWidget(logoWidget);
    startLayout->addWidget(title);
    startLayout->addWidget(text);
}

StartView::~StartView() {

}
