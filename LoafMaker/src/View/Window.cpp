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

		QIcon iconNew;
		iconNew.addFile(QString::fromUtf8(":menu_new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newItem = new QAction(this);
        newItem->setShortcut(QKeySequence::New);
        newItem->setObjectName("newItem");
        newItem->setIcon(iconNew);
        fileMenu->addAction(newItem);
        newItem->setText("Nouveau...");

		QIcon iconImport;
		iconImport.addFile(QString::fromUtf8(":menu_import.png"), QSize(), QIcon::Normal, QIcon::Off);
        openItem = new QAction(this);
        openItem->setShortcut(QKeySequence::Open);
        openItem->setObjectName("openItem");
        openItem->setIcon(iconImport);
        fileMenu->addAction(openItem);
        openItem->setText("Importer");

		QIcon iconExport;
		iconExport.addFile(QString::fromUtf8(":menu_export.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveItem = new QAction(this);
        saveItem->setShortcut(QKeySequence::Save);
        saveItem->setObjectName("saveItem");
        saveItem->setIcon(iconExport);
        fileMenu->addAction(saveItem);
        saveItem->setText("Exporter");

		QIcon iconQuit;
		iconQuit.addFile(QString::fromUtf8(":menu_quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        quitItem = new QAction(this);
        quitItem->setShortcut(QKeySequence::Quit);
        quitItem->setObjectName("quitItem");
        quitItem->setIcon(iconQuit);
        fileMenu->addAction(quitItem);
        quitItem->setText("Quitter");
        
        
		QIcon iconAdd;
		iconAdd.addFile(QString::fromUtf8(":add.png"), QSize(), QIcon::Normal, QIcon::Off);
		QIcon iconEdit;
		iconEdit.addFile(QString::fromUtf8(":edit.png"), QSize(), QIcon::Normal, QIcon::Off);
		QIcon iconDelete;
		iconDelete.addFile(QString::fromUtf8(":trash.png"), QSize(), QIcon::Normal, QIcon::Off);

        listMenu = new QMenu(menubar);
        listMenu->setObjectName("listMenu");
        menubar->addAction(listMenu->menuAction());
        listMenu->setTitle(QString::fromUtf8("Listes"));

            createListItem = new QAction(this);
            createListItem->setObjectName("createListItem");
        	createListItem->setIcon(iconAdd);
            listMenu->addAction(createListItem);
            createListItem->setText(QString::fromUtf8("Créer"));

            editListItem = new QAction(this);
            editListItem->setObjectName("editListItem");
        	editListItem->setIcon(iconEdit);
            listMenu->addAction(editListItem);
            editListItem->setText(QString::fromUtf8("Modifier"));

            deleteListItem = new QAction(this);
            deleteListItem->setObjectName("deleteListItem");
        	deleteListItem->setIcon(iconDelete);
            listMenu->addAction(deleteListItem);
            deleteListItem->setText(QString::fromUtf8("Supprimer"));

        taskMenu = new QMenu(menubar);
        taskMenu->setObjectName("taskMenu");
        menubar->addAction(taskMenu->menuAction());
        taskMenu->setTitle(QString::fromUtf8("Tâches"));

            createTaskItem = new QAction(this);
            createTaskItem->setObjectName("createTaskItem");
        	createTaskItem->setIcon(iconAdd);
            taskMenu->addAction(createTaskItem);
            createTaskItem->setText(QString::fromUtf8("Créer"));

            editTaskItem = new QAction(this);
            editTaskItem->setObjectName("editTaskItem");
        	editTaskItem->setIcon(iconEdit);
            taskMenu->addAction(editTaskItem);
            editTaskItem->setText(QString::fromUtf8("Modifier"));

            deleteTaskItem = new QAction(this);
            deleteTaskItem->setObjectName("deleteTaskItem");
        	deleteTaskItem->setIcon(iconDelete);
            taskMenu->addAction(deleteTaskItem);
            deleteTaskItem->setText(QString::fromUtf8("Supprimer"));

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
    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralWidget->setMinimumSize(APP_WIDTH, APP_HEIGHT);
    this->setCentralWidget(centralWidget);

    splitter = new QSplitter(centralWidget);
    splitter->setMinimumSize(centralWidget->size());
    splitter->setChildrenCollapsible(false);

    /* Left part of the screen */
    listsAndTemplates = new ListsAndTemplates(splitter);
    listsAndTemplates->setMinimumSize(LIST_PANEL_WIDTH, APP_HEIGHT);
    splitter->addWidget(listsAndTemplates);

    /* Right part of the screen */
    listOfTasks = new ListOfTasks(splitter);
    listOfTasks->setMinimumSize(400, APP_HEIGHT);
    splitter->addWidget(listOfTasks);
}

Window::~Window()
{
    delete listOfTasks;
    delete listsAndTemplates;
    delete splitter;
    delete centralWidget;
}

ListsAndTemplates* Window::getListsView() {
    return this->listsAndTemplates;
}

ListOfTasks* Window::getTasksView() {
    return this->listOfTasks;
}
