#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "language.h"
#include <iostream>

MainWindow::MainWindow(QApplication* a,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->app = a;
    lang = new Language(app);
    connect(ui->pushButton_quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->radioButton_suomi,SIGNAL(clicked()),this,SLOT(ChangeLanguage()));
    connect(ui->radioButton_english,SIGNAL(clicked()),this,SLOT(ChangeLanguage()));
    lang->ChangeLanguage(0);
    ui->retranslateUi(this);
    std::clog<<"Window opened"<<std::endl;
}

MainWindow::~MainWindow()
{
    std::clog<<"MainWindow::~MainWindow()"<<std::endl;
    delete lang;
    delete ui;
}

void MainWindow::ChangeLanguage()
{
    std::clog<<"MainWindow::ChangeLanguage()"<<std::endl;
    if(ui->radioButton_suomi->isChecked())
        lang->ChangeLanguage(0);
    else
        lang->ChangeLanguage(1);
    ui->retranslateUi(this);
}
