#include "StartView.hpp"

StartView::StartView(QWidget *parent) : QWidget(parent) {

    startLayout = new QVBoxLayout(this);

    logoWidget = new QWidget(this);
    logoWidget->setObjectName(QString::fromUtf8("logoWidget"));
    logoWidget->setStyleSheet(QString::fromUtf8("border: 1px solid black"));
    logoWidget->setStyleSheet("background-image: url(resources/logo.jpg)");

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
    text->setText(QString::fromUtf8("Blablalallalallblksdjfikdsjfsd jki jfgiksdh sdf is"));


    startLayout->addWidget(logoWidget);
    startLayout->addWidget(title);
    startLayout->addWidget(text);
}

StartView::~StartView() {

}
