#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDialog>

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
    connect(ui->pushButton_dialog,SIGNAL(clicked()),this,SLOT(OpenDialog()));
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

void MainWindow::OpenDialog()
{
    std::clog<<"MainWindow::OpenDialog()"<<std::endl;
    QDialog d;
    Ui::Dialog* dg = new Ui::Dialog;
    dg->setupUi(&d);
    delete dg;
    d.exec();
}
