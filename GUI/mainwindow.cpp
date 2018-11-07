#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "saveevents.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
using namespace std;

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
    // Get the input from lineEdit
    QString input_event = ui->lineEdit->text();
    QFile data("./data.txt");
    data.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QDataStream outs(&data);
    outs.setVersion(QDataStream::Qt_5_11);
    outs << input_event << '\n';
    data.close();
    ui->lineEdit->clear();
}


void MainWindow::on_history_button_clicked()
{
    QFile data("./data.txt");
    data.open(QIODevice::ReadOnly);
    QTextStream read_file(&data);
    ui->textBrowser->setText(read_file.readAll());
}


void MainWindow::on_clean_button_clicked()
{
    QFile data("./data.txt");
    data.remove();
}
