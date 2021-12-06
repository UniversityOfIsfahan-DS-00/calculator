#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>

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
    void on_pushButton_exit_clicked();

    void on_pushButton_minimize_clicked();

    void on_pushButton_num_1_clicked();

    void on_pushButton_num_2_clicked();

    void on_pushButton_num_3_clicked();

    void on_pushButton_num_4_clicked();

    void on_pushButton_num_5_clicked();

    void on_pushButton_num_6_clicked();

    void on_pushButton_num_7_clicked();

    void on_pushButton_num_8_clicked();

    void on_pushButton_num_9_clicked();

    void on_pushButton_op_dot_clicked();

    void on_pushButton_Braces_open_clicked();

    void on_pushButton_Braces_close_clicked();

    void on_pushButton_num_pi_clicked();

    void on_pushButton_op_rem_clicked();

    void on_pushButton_op_div_clicked();

    void on_pushButton_op_plus_clicked();

    void on_pushButton_op_pow_clicked();

    void on_pushButton_op_multiply_clicked();

    void on_pushButton_op_minuse_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_ac_clicked();

    void on_pushButton_num_0_clicked();

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
};
#endif // MAINWINDOW_H
