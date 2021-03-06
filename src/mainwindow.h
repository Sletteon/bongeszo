#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QShortcut>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void FocusLineEdit();
    void Back();
    void Forward();
    void ScrollDown();
    void ScrollUp();
    void ScrollLeft();
    void ScrollRight();

void ScrollDownOrRight(Qt::Orientation orientation, int value);

void ScrollUpOrLeft(Qt::Orientation orientation, int value);

};

#endif // MAINWINDOW_H
