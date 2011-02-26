#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "language.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lang = new Language();
    connect(ui->pushButton_quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->radioButton_suomi,SIGNAL(clicked()),this,SLOT(ChangeLanguage()));
    connect(ui->radioButton_english,SIGNAL(clicked()),this,SLOT(ChangeLanguage()));
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
}
