#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Alt+D = lineEdit fókuszolása (meghív egy FocusLineEdit függvényt
    //a MainWindowban)
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_D), this);
    QObject::connect(shortcut,    &QShortcut::activated, this, &MainWindow::FocusLineEdit);
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

//Alt+D = lineEdit fókuszolása

void MainWindow::FocusLineEdit()
{
    QTimer::singleShot(0, ui->lineEdit, SLOT(setFocus()));
}
