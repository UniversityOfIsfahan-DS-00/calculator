#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

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

void MainWindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void MainWindow::on_pushButton_exit_clicked()
{
    exit(0);
}


void MainWindow::on_pushButton_minimize_clicked()
{
    this->showMinimized();
}

void MainWindow::on_pushButton_num_1_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "1";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_2_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "2";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_3_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "3";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_4_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "4";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_5_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "5";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_6_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "6";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_7_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "7";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_8_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "8";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_9_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "9";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_dot_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += ".";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_Braces_open_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "(";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_Braces_close_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += ")";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_pi_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "Π";
    this->ui->lineEdit_input->setText(text);
    return;
}

void MainWindow::on_pushButton_op_rem_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "%";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_div_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "/";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_plus_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "+";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_pow_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "^";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_multiply_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "*";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_op_minuse_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "-";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_del_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    if(text.size() == 0)
    {
        return;
    }
    text.chop(1);
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_ac_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text = "";
    this->ui->lineEdit_input->setText(text);
    return;
}


void MainWindow::on_pushButton_num_0_clicked()
{
    QString text = this->ui->lineEdit_input->text();
    text += "0";
    this->ui->lineEdit_input->setText(text);
    return;
}
