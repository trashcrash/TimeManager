#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saveevents.h"

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

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_enter_button_clicked();
}

void MainWindow::on_enter_button_clicked()
{
    QApplication::quit();
}


void MainWindow::on_history_button_clicked()
{
    unique_ptr<EventData> event_obj(new EventData());
    event_obj->EventData::ReadBinaryFile("./record.dat");
}

