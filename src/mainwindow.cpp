#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QTimer>
#include "QWebFrame"
#include <Qt>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
     * TODO:
    (mainwindow.h-ba)
    void PairShortcutsWithFunctions (std::string func, QKeySequence());
        mainwindow.cpp:
    void PairShortcutsWithFunctions (std::string func, QKeySequence()){
        QShortcut *ShortcutName = new QShortcut(QKeySequence(), this);
        QObject::connect(ShortcutName, &QShortcut::activated, this, func);
    }
    //HIBA: 'operator()' is not a member of 'std::__cxx11::basic_string<char>'

*/

    //Alt+D lenyomásakor hívja meg a MainWindow::FocusLineEdit függvényt
    QShortcut *FocusEdit = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_D), this);
    QObject::connect(FocusEdit,    &QShortcut::activated, this, &MainWindow::FocusLineEdit);

    //Alt+H lenyomásakor hívja meg a MainWindow::Back függvényt
    QShortcut *BackSC = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_H), this);
    QObject::connect(BackSC,    &QShortcut::activated, this, &MainWindow::Back);

    //Alt+L lenyomásakor hívja meg a MainWindow::Forward függvényt
    QShortcut *ForwardSC = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_L), this);
    QObject::connect(ForwardSC,    &QShortcut::activated, this, &MainWindow::Forward);

    // scrollDSC = scrollDownShortCut
    QShortcut *scrollDSC = new QShortcut(QKeySequence(Qt::Key_J), this);
    QObject::connect(scrollDSC,    &QShortcut::activated, this, &MainWindow::ScrollDown);

    QShortcut *scrollUSC = new QShortcut(QKeySequence(Qt::Key_K), this);
    QObject::connect(scrollUSC,    &QShortcut::activated, this, &MainWindow::ScrollUp);


    QShortcut *scrollLSC = new QShortcut(QKeySequence(Qt::Key_H), this);
    QObject::connect(scrollLSC,    &QShortcut::activated, this, &MainWindow::ScrollLeft);


    QShortcut *scrollRSC = new QShortcut(QKeySequence(Qt::Key_L), this);
    QObject::connect(scrollRSC,    &QShortcut::activated, this, &MainWindow::ScrollRight);

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
        QTimer::singleShot(0, ui->webView, SLOT(setFocus()));
    } else
    {
        if (!url.contains("http://"))
        {
            ui->webView->load("https://"+url);
            QTimer::singleShot(0, ui->webView, SLOT(setFocus()));
        }else
        {
             ui->webView->load(url);
             QTimer::singleShot(0, ui->webView, SLOT(setFocus()));
        }
    }
}

//ui->lineEdit fókuszolása
void MainWindow::FocusLineEdit()
{
    ui->lineEdit->clear();
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
// töltse be integerbe a jelenlegi görgetési pozíciót, és adjon hozzá 40-et (px)
void MainWindow::ScrollDownOrRight(Qt::Orientation orientation, int value){
    int currentScrollValue = ui->webView->page()->mainFrame()->scrollBarValue(orientation);
    ui->webView->page()->mainFrame()->setScrollBarValue(orientation, currentScrollValue  + value);
}
// töltse be integerbe a jelenlegi görgetési pozíciót, és vonjon ki belőle 40-et (px)
void MainWindow::ScrollUpOrLeft(Qt::Orientation orientation, int value){
    int currentScrollValue = ui->webView->page()->mainFrame()->scrollBarValue(orientation);
    ui->webView->page()->mainFrame()->setScrollBarValue(orientation, currentScrollValue  - value);
}

void MainWindow::ScrollDown()
{
    ScrollDownOrRight(Qt::Vertical, 40);
}

void MainWindow::ScrollUp()
{
    ScrollUpOrLeft(Qt::Vertical, 40);
}

void MainWindow::ScrollLeft()
{
    ScrollUpOrLeft(Qt::Horizontal, 40);
}

void MainWindow::ScrollRight()
{
    ScrollDownOrRight(Qt::Horizontal, 40);
}

