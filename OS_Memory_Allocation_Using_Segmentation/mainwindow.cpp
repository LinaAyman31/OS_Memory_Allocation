#include "mainwindow.h"
#include "ui_mainwindow.h"

QStringList row_labels;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->hide();
    QStringList column_labels;
    column_labels << "Starting Address" << "Size";
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(column_labels);

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->show();
   ui->tableWidget->setVerticalHeaderLabels(row_labels);
   ui->pushButton->setText("Add new hole");
   ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
   row_labels << QString::number(ui->tableWidget->rowCount());
   ui->tableWidget->setVerticalHeaderLabels(row_labels);
}
