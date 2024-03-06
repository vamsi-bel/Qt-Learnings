#include "mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QStatusBar>
#include <QDebug>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(400,300);
    //Add central widget
    QPushButton *button = new QPushButton("Hello", this);
    setCentralWidget(button);

    //Declare quit action
    QAction *quitAction = new QAction("Quit");
    connect(quitAction,&QAction::triggered,[=](){QApplication::quit();});


    //Add menus
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addAction("Edit");
    menuBar()->addAction("Window");
    menuBar()->addAction("Settings");
    menuBar()->addAction("Help");

    //Add status bar message
    statusBar()->showMessage("Uploading file...",3000);
    //statusBar()->clearMessage();
}

MainWindow::~MainWindow()
{
}

