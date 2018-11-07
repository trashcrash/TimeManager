#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <chrono>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
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

    // Get current datetime
    QString current_datetime = QDateTime::currentDateTime().toString();

    // Open data.txt and append text
    QFile data("./data.txt");
    data.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
    QTextStream outs(&data);
    outs << input_event << " -> " << current_datetime <<  '\n';
    data.close();

    // Clear lineEdit
    ui->lineEdit->clear();
}


void MainWindow::on_history_button_clicked()
{
    // Open data.txt
    QFile data("./data.txt");
    data.open(QIODevice::ReadOnly);
    QTextStream read_file(&data);

    // Show text in textBrowser
    ui->textBrowser->setText(read_file.readAll());
}


void MainWindow::on_clean_button_clicked()
{
    // Remove data.txt
    QFile data("./data.txt");
    data.remove();
    ui->textBrowser->clear();
}
