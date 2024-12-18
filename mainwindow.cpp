#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    connect(actionSave,SIGNAL(triggered(bool)),this,SLOT(saveFile()));
    connect(actionClose,SIGNAL(triggered(bool)),this,SLOT(close()));
}

MainWindow::~MainWindow() {}
void MainWindow::saveFile()
{

}
