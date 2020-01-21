#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>

#include "glwidget.h"

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
    void on_pb_start_clicked();

    void on_pb_stop_clicked();

    void onTimeout();

    void on_pb_printscreen_clicked();

    void on_pb_time_clicked();

private:
    Ui::MainWindow *ui;
    QTimer m_timer;
    qint64 m_start_time = 0;
    bool m_useStopwatch = true;

    GLWidget *m_widget = nullptr;
};
#endif // MAINWINDOW_H
