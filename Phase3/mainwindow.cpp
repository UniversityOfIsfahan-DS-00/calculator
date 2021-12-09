#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystack.h"
#include "mystack.cpp"

#include <bits/stdc++.h>

using namespace std;

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

// input validation
void MainWindow::on_lineEdit_input_textChanged(const QString &org_text)
{
    QVector<QString> valid_chars = {"+", "-", "*", "/", "^", "%", ".", ")", "(", "Π"};
    QVector<QString> valid_op = {"+", "-", "*", "/", "^", "%"};
    bool after_dot = false;

    QString non_const_text = org_text;

    non_const_text = non_const_text.simplified();
    non_const_text.replace(" ", "");

    const QString text = non_const_text;

    for (int i = 0; i < text.size(); i++)
    {
        // checking first character
        if(i == 0 && !text[i].isNumber() && (text[i] != "-" && text[i] != "(" && text[i] != "." && text[i] != "Π"))
        {
            ui->pushButton_op_equal->setText("Invalid input!");
            ui->pushButton_op_equal->setDisabled(true);
            return;
        }
        // checking last character
        else if(i == text.size()-1 && !text[i].isNumber() && (text[i] != ")" && text[i] != "Π"))
        {
            ui->pushButton_op_equal->setText("Invalid input!");
            ui->pushButton_op_equal->setDisabled(true);
            return;
        }
        else
        {
            // checking for illegal characters
            if(!text[i].isNumber())
            {
                int j;
                for(j = 0; j < valid_chars.size(); j++)
                {
                    if(text[i] == valid_chars[j])
                    {
                        if(text[i] == "." && after_dot)
                        {
                            ui->pushButton_op_equal->setText("Invalid input!");
                            ui->pushButton_op_equal->setDisabled(true);
                            return;
                        }
                        else if(text[i] == ".")
                        {
                            after_dot = true;
                        }
                        else
                        {
                            after_dot = false;
                        }
                        break;
                    }
                }

                if(j == valid_chars.size())
                {
                    ui->pushButton_op_equal->setText("Invalid input!");
                    ui->pushButton_op_equal->setDisabled(true);
                    return;
                }
            }
        }
    }

    bool current, next;

    // checking for consecutive operators
    for(int i = 0; i < text.size()-1; i++)
    {
        current = false, next = false;
        if(text[i] == "Π" && text[i+1] == "Π")
        {
            ui->pushButton_op_equal->setText("Invalid input!");
            ui->pushButton_op_equal->setDisabled(true);
            return;
        }
        else if(!text[i].isNumber())
        {
            for(int j = 0; j < valid_op.size(); j++)
            {
                if(text[i] == valid_op[j])
                {
                    current = true;
                }
                if(text[i+1] == valid_op[j])
                {
                    next = true;
                }
            }
            if(current && next)
            {
                ui->pushButton_op_equal->setText("Invalid input!");
                ui->pushButton_op_equal->setDisabled(true);
                return;
            }
        }
    }

    // checking round brackets
    MyStack<QString> st;

    for(int i = 0; i < text.size(); i++)
    {
        if(text[i] == "(")
        {
            st.push(text[i]);
            // empty round brackets
            if(!text[i+1].isNull() && (text[i+1] == ")"))
            {
                ui->pushButton_op_equal->setText("Invalid input!");
                ui->pushButton_op_equal->setDisabled(true);
                return;
            }

            // special case
            if(!text[i+1].isNull())
            {
                if(text[i+1] == "+" || text[i+1] == "*" || text[i+1] == "/" || text[i+1] == "%" || text[i+1] == "^")
                {
                    ui->pushButton_op_equal->setText("Invalid input!");
                    ui->pushButton_op_equal->setDisabled(true);
                    return;
                }
            }
            if(i != 0 && (text[i-1].isNumber() || text[i-1] == "Π"))
            {
                ui->pushButton_op_equal->setText("Invalid input!");
                ui->pushButton_op_equal->setDisabled(true);
                return;
            }
        }
        else if(text[i] == ")")
        {
            if(st.isEmpty())
            {
                ui->pushButton_op_equal->setText("Invalid input!");
                ui->pushButton_op_equal->setDisabled(true);
                return;
            }
            else
            {
                st.pop();
            }

            if(i != text.size()-1)
            {
                if(text[i+1] == "(")
                {
                    ui->pushButton_op_equal->setText("Invalid input!");
                    ui->pushButton_op_equal->setDisabled(true);
                    return;
                }
            }

            // special case
            if(i != 0)
            {
                if(text[i-1] == "+" || text[i-1] == "*" || text[i-1] == "/" || text[i-1] == "%" || text[i-1] == "^")
                {
                    ui->pushButton_op_equal->setText("Invalid input!");
                    ui->pushButton_op_equal->setDisabled(true);
                    return;
                }
            }
            if(i != text.size()-1 && (text[i+1].isNumber() || text[i+1] == "Π"))
            {
                ui->pushButton_op_equal->setText("Invalid input!");
                ui->pushButton_op_equal->setDisabled(true);
                return;
            }
        }
    }

    if(!st.isEmpty())
    {
        ui->pushButton_op_equal->setText("Invalid input!");
        ui->pushButton_op_equal->setDisabled(true);
        return;
    }

    ui->pushButton_op_equal->setText("=");
    ui->pushButton_op_equal->setEnabled(true);
    return;
}
