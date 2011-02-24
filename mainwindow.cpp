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
    connect(ui->actionSuomi,SIGNAL(triggered()),lang,SLOT(ChangeLanguage()));
    std::clog<<"Window opened"<<std::endl;
}

MainWindow::~MainWindow()
{
    delete lang;
    delete ui;
}
