#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <iomanip>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (QPushButton* button : {
         ui->N0,
         ui->N1,
         ui->N2,
         ui->N3,
         ui->N4,
         ui->N5,
         ui->N6,
         ui->N7,
         ui->N8,
         ui->N9,
     }) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    }

    for (QPushButton* button : {
        ui->add,
        ui->mul,
        ui->div,
        ui->sub
    }) {
        connect(button, &QPushButton::clicked, this, &MainWindow::operandClickedHandler);
    }

    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearClickHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearClickHandler() {
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();

    operand = Operand::NONE;
}

void MainWindow::enterClickHandler() {
    float result = 0.0;

    float a = ui->num1->text().toFloat();
    float b = ui->num2->text().toFloat();

    switch (operand) {
        case Operand::ADD:
            result = a + b;
            break;
        case Operand::SUB:
            result = a - b;
            break;
        case Operand::MUL:
            result = a * b;
            break;
        case Operand::DIV:
            result = a / b;
            break;
    }

    std::ostringstream ss;

    ss << std::fixed << std::setprecision(2) << result;

    ui->result->setText(QString::fromStdString(ss.str()));
}

void MainWindow::operandClickedHandler() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button->text() == "/") {
        operand = Operand::DIV;
    } else if (button->text() == "*") {
        operand = Operand::MUL;
    } else if (button->text() == "-") {
        operand = Operand::SUB;
    } else if (button->text() == "+") {
        operand = Operand::ADD;
    }
}

void MainWindow::numberClickedHandler()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (ui->num1->text().isEmpty()) {
        ui->num1->setText(button->text());
    } else if (ui->num2->text().isEmpty()) {
        ui->num2->setText(button->text());
    }
}



