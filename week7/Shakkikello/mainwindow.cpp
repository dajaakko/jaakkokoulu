#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);
    Player1Button = new QPushButton(this);
    Player2Button = new QPushButton(this);
    StartGame = new QPushButton(this);
    StopGame = new QPushButton(this);
    Player2ProgressBar = new QProgressBar(this);
    Player1ProgressBar = new QProgressBar(this);
    KaksiMin = new QPushButton(this);
    ViisiMin = new QPushButton(this);

    connect(ui->KaksiMin,SIGNAL (clicked()), this,SLOT(time2())); //kytketään 120sec time2 funktioon
    connect(ui->ViisiMin,SIGNAL (clicked()), this,SLOT(time5())); //kytketään 120sec time5 funktioon
    connect(ui->StartGame,SIGNAL (clicked()), this,SLOT(startGame()));//kytketään startgame startgame funktioon
    connect(ui->Player1Button, SIGNAL(clicked()), this, SLOT(Player1ButtonHandler())); //kytketään p1button p1buttonhandler funktioon
    connect(ui->StartGame,SIGNAL (clicked()), this,SLOT(updateProgressBar())); //kytketään startgame progressbar päivitys funktioon, joka lähtee vähentämään aikaa
    connect(ui->StartGame,SIGNAL (clicked()), this,SLOT(setGameInfoText()));
    connect(ui->StartGame,SIGNAL (clicked()), this,SLOT(Player1ButtonHandler()));//test kytketään start game painike player1buttoniin, jossa valitaan pelaajaksi 1
    connect(ui->Player1Button,SIGNAL (clicked()), this,SLOT(Player2ButtonHandler()));
    connect(ui->Player2Button,SIGNAL (clicked()), this,SLOT(Player2ButtonHandler()));
    connect(ui->Player2Button,SIGNAL (clicked()), this,SLOT(Player1ButtonHandler()));
    connect(ui->Player2Button,SIGNAL (clicked()), this,SLOT(updateProgressBar()));
    connect(pQTimer, SIGNAL(timeout()),this,SLOT(updateProgressBar()));
    connect(ui->StopGame,SIGNAL (clicked()), this,SLOT(stopgame()));
setGameInfoText("Select time", 12);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::time2()
{
    setGameInfoText("PRESS START GAME", 12);
    gameTime=1200;
    player1Time=100;
    player2Time=100;


    ui->Player1ProgressBar->setValue(player1Time);
    ui->Player2ProgressBar->setValue(player2Time);
    ui->Player1ProgressBar->setMaximum(100);
    ui->Player2ProgressBar->setMaximum(100);
    ui->Player1ProgressBar->setMinimum(0);
    ui->Player2ProgressBar->setMinimum(0);

}

void MainWindow::time5()
{
    setGameInfoText("PRESS START GAME", 12);
gameTime = 5000;
player1Time=100;
player2Time=100;

ui->Player1ProgressBar->setValue(player1Time);
ui->Player2ProgressBar->setValue(player2Time);
ui->Player1ProgressBar->setMaximum(100);
ui->Player2ProgressBar->setMaximum(100);
ui->Player1ProgressBar->setMinimum(0);
ui->Player2ProgressBar->setMinimum(0);
qDebug() <<"Nappia painettu";

}



void MainWindow::updateProgressBar()
{
    setGameInfoText("game ongoing", 12);
    if (currentPlayer == 1) {
            ui->Player1ProgressBar->setValue(player1Time--);
        } else if (currentPlayer == 2) {
            ui->Player2ProgressBar->setValue(player2Time--);
        } {
        if (player1Time == 0) {
            qDebug()<<"toimiiks";
               setGameInfoText("Pelaaja 2 voitti!", 12); // Voittotiedote pelaajalle 2
           } else if (player2Time == 0) {
               setGameInfoText("Pelaaja 1 voitti!", 12); // Voittotiedote pelaajalle 1
           }
   }
}

void MainWindow::startGame()
{
setGameInfoText("peli alkaa", 12);
    currentPlayer=1;



pQTimer->setInterval(gameTime);

}

void MainWindow::Player1ButtonHandler()
{
    currentPlayer=1;
    pQTimer->start();
    qDebug() <<"pelaaja1 nappia painettu2";

}

void MainWindow::Player2ButtonHandler()
{

    currentPlayer=2;

    qDebug() <<"pelaaja2 nappia painettu2";




}

void MainWindow::stopgame()
{
qDebug() <<"tetsti" ;
setGameInfoText("select time and press start game to start again", 12);
pQTimer->stop();
}

void MainWindow::setGameInfoText(QString teksti, short f)
{

    QFont font;
    font.setPointSize(f);
    ui->tapahtuma->setFont(font);
    ui->tapahtuma->setText(teksti);

}








