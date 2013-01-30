#include "Window.hpp"

Window::Window(QWidget *parent) : QMainWindow(parent)
{
    this->resize(APP_WIDTH, APP_HEIGHT);

    /* Menubar */
    menubar = new QMenuBar(this);
    this->setMenuBar(menubar);
    menubar->setObjectName("menubar");

    fileMenu = new QMenu(menubar);
    fileMenu->setObjectName("fileMenu");
    menubar->addAction(fileMenu->menuAction());
    fileMenu->setTitle(QString::fromUtf8("Fichier"));

        newItem = new QAction(this);
        newItem->setShortcut(QKeySequence::New);
        newItem->setObjectName("newItem");
        fileMenu->addAction(newItem);
        newItem->setText("Nouveau...");

        openItem = new QAction(this);
        openItem->setShortcut(QKeySequence::Open);
        openItem->setObjectName("openItem");
        fileMenu->addAction(openItem);
        openItem->setText("Importer");

        saveItem = new QAction(this);
        saveItem->setShortcut(QKeySequence::Save);
        saveItem->setObjectName("saveItem");
        fileMenu->addAction(saveItem);
        saveItem->setText("Exporter");

        quitItem = new QAction(this);
        quitItem->setShortcut(QKeySequence::Quit);
        quitItem->setObjectName("quitItem");
        fileMenu->addAction(quitItem);
        quitItem->setText("Quitter");

    editMenu = new QMenu(menubar);
    editMenu->setObjectName("editMenu");
    menubar->addAction(editMenu->menuAction());
    editMenu->setTitle(QString::fromUtf8("Édition"));

    /*
        newSlotItem = new QAction(this);
        newSlotItem->setShortcut(Qt::CTRL+Qt::Key_A);
        newSlotItem->setObjectName("newSlotItem");
        editMenu->addAction(newSlotItem);
        newSlotItem->setText("Create an event");

    settingsMenu = new QMenu(menubar);
    settingsMenu->setObjectName("settingsMenu");
    menubar->addAction(settingsMenu->menuAction());
    settingsMenu->setTitle("Synchronization");

        reloadItem = new QAction(this);
        reloadItem->setShortcut(Qt::Key_F5);
        reloadItem->setObjectName("reloadItem");
        settingsMenu->addAction(reloadItem);
        reloadItem->setText("Reset local calendar with my Google Calendar");

        importItem = new QAction(this);
        importItem->setShortcut(Qt::Key_F6);
        importItem->setObjectName("importItem");
        settingsMenu->addAction(importItem);
        importItem->setText(QString("Update local calendar from UnivNantes (CELCAT)"));

        exportItem = new QAction(this);
        exportItem->setShortcut(Qt::Key_F7);
        exportItem->setObjectName("exportItem");
        settingsMenu->addAction(exportItem);
        exportItem->setText("Save my calendar on Google Calendar");

        settingsMenu->addSeparator();

        settingsItem = new QAction(this);
        settingsItem->setObjectName("settingsItem");
        settingsMenu->addAction(settingsItem);
        settingsItem->setText("Settings..");
    */

    /* Central widget */
    centralwidget = new QWidget(this);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    this->setCentralWidget(centralwidget);

    /* Left part of the screen */
    listsAndTemplates = new ListsAndTemplates(centralwidget);
    listsAndTemplates->setGeometry(10, 20, LIST_PANEL_WIDTH, 550);

    /* Right part of the screen */
    listOfTasks = new ListOfTasks(TASK_PANEL_WIDTH, centralwidget);
    listOfTasks->setGeometry(LIST_PANEL_WIDTH + PANELS_SEPARATOR_SIZE, 20, TASK_PANEL_WIDTH, 550);
}

Window::~Window()
{
    delete listOfTasks;
    delete listsAndTemplates;
    delete centralwidget;
}
