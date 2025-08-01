#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "coder.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_open_file_clicked();

    void on_checkBox_pressed();

    void on_pushButton_clicked();

    void on_checkBox_2_pressed();

    void on_pushButton_2_clicked();

    void on_checkBox_rewrite_pressed();

private:
    bool
    input_file_delete_ = false,
    use_timer_ = false,
    rewrite_file_ = false;

    int64_t mask_ = 1;
    QString input_file_,
    output_file_;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
