#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum Operand {
    NONE,
    DIV,
    SUB,
    MUL,
    ADD
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void numberClickedHandler();
    void clearClickHandler();
    void operandClickedHandler();
    void enterClickHandler();

private:
    Ui::MainWindow *ui;
    Operand operand = Operand::NONE;
};
#endif // MAINWINDOW_H
