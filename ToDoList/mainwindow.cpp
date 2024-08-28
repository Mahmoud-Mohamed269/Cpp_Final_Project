#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTaskButton_clicked()
{
    QString task = ui->lineEdit->text();
    if(!task.isEmpty()) {
        ui->taskListWidget->addItem(task);
        ui->lineEdit->clear();
    }
}

void MainWindow::on_removeTaskButton_clicked()
{
    QListWidgetItem *item = ui->taskListWidget->currentItem();
    if(item) {
        delete ui->taskListWidget->takeItem(ui->taskListWidget->row(item));
    }
}

void MainWindow::on_removeAllTasksButton_clicked()
{
    ui->taskListWidget->clear();
}
