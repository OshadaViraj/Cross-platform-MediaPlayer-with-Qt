#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:grey;");
    Player=new QMediaPlayer(this);
    vw=new  QVideoWidget(this);
    Player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider=new QSlider(this);

    br =new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);
    ui->statusBar->addPermanentWidget(slider);
    ui->statusBar->addPermanentWidget(br);

    connect(Player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(Player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
     connect(slider,&QSlider::sliderMoved,Player,&QMediaPlayer::setPosition);


    connect(Player,&QMediaPlayer::durationChanged,br,&QProgressBar::setMaximum);
    connect(Player,&QMediaPlayer::positionChanged,br,&QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
  QString  fileName =QFileDialog::getOpenFileName(this,"Open a file","","Video File(*.*)");
  on_actionStop_triggered();
  Player->setMedia(QUrl::fromLocalFile(fileName));
  Player->play();
  ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionPlay_triggered()
{
Player->play();
ui->statusBar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    Player->pause();
    ui->statusBar->showMessage("Paused.....");

}

void MainWindow::on_actionStop_triggered()
{
    Player->stop();
    ui->statusBar->showMessage("Stopped");
}

void MainWindow::on_actionMute_triggered()
{
    Player->setVolume(0);
    ui->statusBar->showMessage("Mute");

}

void MainWindow::on_actionUnmute_triggered()
{
    ui->statusBar->showMessage("Unmute");
    Player->setVolume(100);
    ui->statusBar->showMessage("Playing.....");

}

void MainWindow::on_actionAbout_triggered()
{
    About about;
    about.setModal(true);
    about.exec();

}
