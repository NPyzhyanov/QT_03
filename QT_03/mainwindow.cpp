#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectionDialog = new ConnectionDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_set_connection_clicked()
{
    connectionDialog->show();
}
