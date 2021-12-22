#include "history_window.h"
#include "ui_history_window.h"

history_window::history_window(QVector<QString> *history, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history_window)
{
    ui->setupUi(this);

    this->history = history;

    QVector<QString>::iterator itr;

    for(itr = history->begin(); itr != history->end(); itr++)
    {
        QListWidgetItem *tmp = new QListWidgetItem(*itr);
        ui->listWidget->addItem(tmp);
    }
}

history_window::~history_window()
{
    delete ui;
}

void history_window::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}

void history_window::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}

void history_window::on_pushButton_close_clicked()
{
    this->close();
    return;
}
