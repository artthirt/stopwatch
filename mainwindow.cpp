#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QGuiApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_widget = new GLWidget();
    m_widget->resize(800, 600);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

MainWindow::~MainWindow()
{    
    delete ui;

    delete m_widget;
}


void MainWindow::on_pb_start_clicked()
{
    m_start_time = QDateTime::currentMSecsSinceEpoch();
    m_timer.start(1);
}

void MainWindow::on_pb_stop_clicked()
{
    m_timer.stop();
}

void MainWindow::onTimeout()
{
    qint64 now = QDateTime::currentMSecsSinceEpoch();

    QDateTime dt = QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)).addMSecs(now - m_start_time);

    ui->lb_hms->setText(dt.time().toString("hh:mm:ss"));
    ui->lb_ms->setText(dt.time().toString("zzz"));
}

void MainWindow::on_pb_printscreen_clicked()
{
    QScreen* s = QGuiApplication::primaryScreen();
    if(!s)
        return;

    QPixmap pix = s->grabWindow(0);
    m_widget->setImage(pix.toImage());
    m_widget->show();
}
