#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDialog>
#include <QFileDialog>

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


void MainWindow::on_pushButton_open_file_clicked()
{
    input_file_ = QFileDialog::getOpenFileName(0, "OpenFile", "", "*.txt *.bin");
    ui->textEdit->setText(input_file_);
}


void MainWindow::on_checkBox_pressed()
{
    input_file_delete_ = !input_file_delete_;
}


void MainWindow::on_pushButton_clicked()
{
    output_file_ = QFileDialog::getSaveFileName();
    ui->textEdit_2->setText(output_file_);
}


void MainWindow::on_checkBox_2_pressed()
{
    use_timer_ = !use_timer_;
}


void MainWindow::on_pushButton_2_clicked()
{


    int counter = 0;
    QString smask = ui->maskEdit->toMarkdown();
    QString outfilename = output_file_;
    int m = smask.toInt();
    int timer = 1000;
    int64_t mask = m;
    QFile file(input_file_);
    m1:

    if(!file.exists() || file.isOpen()){
        Delay(timer);
        goto m1;
    }

    QFile outfile(output_file_);
    if(outfile.exists() && !rewrite_file_){
        QString str;
        str.setNum(counter++);
        outfilename = output_file_ + str;
    }

    MakeBinFromFile(input_file_.toStdString(), outfilename.toStdString(), mask);
    if(input_file_delete_){
        QFile file(input_file_);
        file.remove();
    }

    if(use_timer_){
       Delay(timer);
       goto m1;
    }
}


void MainWindow::on_checkBox_rewrite_pressed()
{
    rewrite_file_ = !rewrite_file_;
}

