#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Alt+D lenyomásakor hívja meg a MainWindow::FocusLineEdit függvényt
    QShortcut *FocusEdit = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_D), this);
    QObject::connect(FocusEdit,    &QShortcut::activated, this, &MainWindow::FocusLineEdit);

    //Alt+[balra] lenyomásakor hívja meg a MainWindow::Back függvényt
    QShortcut *BackSC = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_Left), this);
    QObject::connect(BackSC,    &QShortcut::activated, this, &MainWindow::Back);

    //Alt+[jobbra] lenyomásakor hívja meg a MainWindow::Forward függvényt
    QShortcut *ForwardSC = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_Right), this);
    QObject::connect(ForwardSC,    &QShortcut::activated, this, &MainWindow::Forward);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString url = ui->lineEdit->text();
    //ha az urlben nincs pont, akkor keressen rá google-ben
    //ha van pont, akkor egészítse ki https://-sel
    //pl.: google <- keresés
    //     google.com <- kiegészítés https://-sel

    if (!url.contains("."))
    {
        ui->webView->load("https://google.com/search?q="+url);
    } else
    {
        if (!url.contains("http://"))
        {
            ui->webView->load("https://"+url);
        }else
        {
             ui->webView->load(url);
        }
    }
}

//ui->lineEdit fókuszolása
void MainWindow::FocusLineEdit()
{
    QTimer::singleShot(0, ui->lineEdit, SLOT(setFocus()));
}

void MainWindow::Back()
{
    ui->webView->back();
}

void MainWindow::Forward()
{
    ui->webView->forward();
}

