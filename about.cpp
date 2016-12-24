#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:grey;");
}

About::~About()
{
    delete ui;
}
