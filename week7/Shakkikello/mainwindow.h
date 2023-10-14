#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qprogressbar.h"
#include "qpushbutton.h"
#include <QTimer>
#include <QFont>
#include <QDebug>
using namespace std;


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void time2();
    void time5();
    void updateProgressBar();
    void startGame();
    void Player1ButtonHandler();
    void Player2ButtonHandler();
    void stopgame();

private slots:

void setGameInfoText(QString,short);

   // void setGameInfoText(QString, short);

signals:
    void timeout();
private:
    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer * pQTimer;
    QPushButton *Player1Button;
    QPushButton *Player2Button;
    QPushButton *KaksiMin;
    QPushButton *ViisiMin;
    QPushButton *StartGame;
    QPushButton *StopGame;
    QProgressBar *Player1ProgressBar;
    QProgressBar *Player2ProgressBar;
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
