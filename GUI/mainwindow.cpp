#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TimeManager");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_button_clicked()
{
    QApplication::quit();
}
