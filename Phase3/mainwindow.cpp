#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystack.h"
#include "mystack.cpp"
#include "tree.h"
#include "tree.cpp"
#include "tree_node.h"
#include "tree_node.cpp"

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
    int size = text.size();
    if(size == 0 || (!text[size-1].isNumber() && text[size-1] !="."))
    {
        text += "0.";
    }
    else
    {
        text += ".";
    }
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
                        if((text[i] == "." && after_dot) || (text[i] == "." && !text[i+1].isNumber()))
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

// a function to put space between oprands and operators
void seperator(QString &exp)
{
    for (int i = 0; i < exp.size(); i++)
    {
        if(exp[i].isNumber() || exp[i] == '.' || exp == " ")
        {
            continue;
        }
        else if(exp[i] == '(')
        {
            exp.insert(i+1, " ");
            i++;
        }
        else if(exp[i] == ')')
        {
            exp.insert(i, " ");
            i++;
        }
        else
        {
            if(exp[i] == "-")
            {
                if(i == 0 || (i > 1 && exp[i-2] == "("))
                {
                    exp.remove(i,1);
                    exp.insert(i, "-1 * ");
                    i += 4;
                }
                else
                {
                    exp.insert(i, " ");
                    i++;
                    exp.insert(i+1, " ");
                    i += 1;
                }
            }
            else
            {
                exp.insert(i, " ");
                i++;
                exp.insert(i+1, " ");
                i += 1;
            }
        }
    }
    return;
}

// a function returns the precedence of a character
int precedence(QString str)
{
    if(str == "^")
    {
        return 3;
    }
    if(str == "*" || str == "/" || str == "%")
    {
        return 2;
    }
    if(str == "+" || str == "-")
    {
        return 1;
    }
    if(str == "(" || str == ")")
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

// a function converts infix to postfix
QString infix_to_postfix(QString exp)
{
    MyStack<QString> st;
    QString output, temp;

    for (int i = 0; i < exp.size(); i++)
    {
        temp = "";
        while (i < exp.size() && exp[i] != ' ')
        {
            temp += exp[i];
            i++;
        }

        if(precedence(temp) > 0)  // then it's operator
        {
            if(st.isEmpty() || precedence(temp) > precedence(st.peek()->get_data()) || (temp == "^" && st.peek()->get_data() == "^"))
            {
                st.push(temp);
            }
            else
            {
                while(!st.isEmpty() && precedence(temp) <= precedence(st.peek()->get_data()))
                {
                    output += st.peek()->get_data();
                    output += " ";
                    st.pop();
                }
                st.push(temp);
            }
        }
        else if(precedence(temp) == 0)    // then it's round bracket
        {
            if(temp == "(")
            {
                st.push(temp);
            }
            else
            {
                while (st.peek()->get_data() != "(")
                {
                    output += st.peek()->get_data();
                    output += " ";
                    st.pop();
                }
                st.pop();
            }
        }
        else    // then it's operand
        {
            output += temp;
            output += " ";
        }
    }
    while (!st.isEmpty())
    {
        output += st.peek()->get_data();
        output += " ";
        st.pop();
    }

    return output;
}

// a function converts postfix to infix
QString postfix_to_infix(QString exp)
{
    if(exp.size()==1)
    {
        return exp;
    }
    MyStack<QString> st;
    QString output, temp, tmp1, tmp2;

    for(int i = 0; i < exp.size()-1; i++)
    {
        temp = "";

        while(i < exp.size() && exp[i] != " ")
        {
            temp += exp[i];
            i++;
        }

        if(precedence(temp) < 0)	// then it's an operand
        {
            st.push(temp);
        }
        else
        {
            tmp1 = st.peek()->get_data();
            st.pop();
            tmp2 = st.peek()->get_data();
            st.pop();
            st.push("(" + tmp2 + temp + tmp1 + ")");
        }
    }

    output = st.peek()->get_data();

    return output;
}

// a function calculates and returns a string which is the answer of inputted postfix and a stack which contains calculation steps
QString calculate_postFix(QString exp, MyStack<QString> &steps)
{
    MyStack<QString> st;
    QString str1, str2, str;
    double num1, num2, answer = 0;

    for (int i = 0; i < exp.size(); i++)
    {
        str = "";
        while (i < exp.size() && exp[i] != ' ')
        {
            str += exp[i];
            i++;
        }

        if(str == "+" || str == "-" || str == "/" || str == "*" || str == "^" || str == "%")
        {
            str1 = st.peek()->get_data();
            st.pop();
            str2 = st.peek()->get_data();
            st.pop();

            num1 = str1.toDouble();
            num2 = str2.toDouble();

            if(str == "+")
            {
                answer = num1 + num2;
            }
            else if(str == "-")
            {
                answer = num2 - num1;
            }
            else if(str == "*")
            {
                answer = num1 * num2;
            }
            else if(str == "%")
            {
                if(num1 == 0 || floor(num1) != num1 || floor(num2) != num2)
                {
                    throw "ERROR";
                }
                else
                {
                    answer = (int) num2 % (int) num1;
                }
            }
            else if(str == "/")
            {
                if(num1 == 0)
                {
                    throw "ERROR";
                }
                else
                {
                    answer = num2 / num1;
                }
            }
            else if(str == "^")
            {
                double tmp = 1 / num1;
                bool is_even = false;
                if(int(tmp) == tmp)
                {
                    if((int)tmp % 2 == 0)
                    {
                       is_even = true;
                    }
                }
                if(num2 < 0 && (num1 < 1 && num1 > 0))
                {
                    if(is_even)
                    {
                        throw "ERROR";
                    }
                    else
                    {
                        answer = pow((-1*num2), num1);
                        answer *= -1;
                    }
                }
                else
                {
                    answer = pow(num2, num1);
                }
            }

            exp.remove(0, i+1);

            str = QString::number(answer) + " ";

            exp.insert(0, str);

            while(!st.isEmpty())
            {
                exp.insert(0, st.peek()->get_data() + " ");
                st.pop();
            }

            steps.push(postfix_to_infix(exp));

            i = -1;
        }
        else
        {
            if(str == "Π")
            {
                st.push(QString::number(M_PI));
            }
            else if(str != "")
            {
                st.push(str);
            }
        }

    }

    str = st.peek()->get_data();
    st.pop();

    return str;
}

template<typename T>
MyStack<T> * stack_rev(MyStack<T> &st)
{
    MyStack<T> * rev_st= new MyStack<T>;
    while(!st.isEmpty())
    {
        rev_st->push(st.peek()->get_data());
        st.pop();
    }
    return rev_st;
}

void MainWindow::on_pushButton_op_equal_clicked()
{
    MyStack<QString> steps;
    ui->listWidget->clear();


    QString exp = ui->lineEdit_input->text();
    seperator(exp);

    QListWidgetItem *tmp = new QListWidgetItem("Your Input:");
    ui->listWidget->addItem(tmp);

    QListWidgetItem *inp = new QListWidgetItem(exp);
    ui->listWidget->addItem(inp);

    exp = infix_to_postfix(exp);

    try
    {
        QListWidgetItem *ans = new QListWidgetItem(calculate_postFix(exp, steps));

        steps = *stack_rev(steps);

        for(int i = 0; !steps.isEmpty(); i++)
        {
            QListWidgetItem *tmp = new QListWidgetItem(steps.peek()->get_data());
            ui->listWidget->addItem(tmp);
            steps.pop();
        }
        QListWidgetItem *tmp = new QListWidgetItem("Answer:");
        ui->listWidget->addItem(tmp);
        ui->listWidget->addItem(ans);
    }
    catch (...)
    {
        QListWidgetItem *ans = new QListWidgetItem("Error");
        ui->listWidget->addItem(ans);
    }

    return;
}

void MainWindow::on_pushButton_tree_clicked()
{
    ui->listWidget->clear();

    QString exp = ui->lineEdit_input->text();

    seperator(exp);

    exp = infix_to_postfix(exp);

    // creating expression tree

    MyStack<tree_node<QString> *> st;
    QString str, temp;

    tree_node<QString> * tmp1, * tmp2;

    for (int i = 0; i < exp.size(); i++)
    {
        str = "";
        while (i < exp.size() && exp[i] != ' ')
        {
            str += exp[i];
            i++;
        }

        if(str == "+" || str == "-" || str == "/" || str == "*" || str == "^" || str == "%")
        {
            tree_node<QString> * tmp = new tree_node<QString>;
            tmp->set_data(str);

            tmp1 = st.peek()->get_data();
            st.pop();

            tmp2 = st.peek()->get_data();
            st.pop();

            tmp->set_right(tmp1);
            tmp->set_left(tmp2);

            st.push(tmp);
        }
        else
        {
            tree_node<QString> * tmp = new tree_node<QString>;
            tmp->set_data(str);
            st.push(tmp);
        }

    }

    tree<QString> t;
    t.set_root(st.peek()->get_data());
    st.pop();				// st is empty now

    MyStack<QString> *sst = new MyStack<QString>;

    print_level_order(t.get_root(), sst);

    sst = stack_rev(*sst);

    for(int i = 0; !sst->isEmpty(); i++)
    {
        temp = sst->peek()->get_data();

//        for(int j = sst->get_size()*sst->get_size(); j > 0; j--)
//        {
//            temp.insert(0, " ");
//        }

        QListWidgetItem *tmp = new QListWidgetItem(temp);
        sst->pop();

        ui->listWidget->addItem(tmp);
    }

    return;
}
