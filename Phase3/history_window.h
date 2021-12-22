#ifndef HISTORY_WINDOW_H
#define HISTORY_WINDOW_H

#include <QDialog>
#include <QMouseEvent>

namespace Ui {
class history_window;
}

class history_window : public QDialog
{
    Q_OBJECT

public:
    explicit history_window(QVector<QString> *history, QWidget *parent = nullptr);
    ~history_window();

private slots:
    void on_pushButton_close_clicked();

private:
    Ui::history_window *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
    QVector<QString> *history;
};

#endif // HISTORY_WINDOW_H
