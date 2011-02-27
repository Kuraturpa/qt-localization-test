#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include <iostream>
#include <QDialog>
#include <QList>

MainWindow::MainWindow(QApplication* a,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->app = a;
    lang = new Language(app);
    if(!lang)
        return;
    connect(ui->pushButton_quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->pushButton_dialog,SIGNAL(clicked()),this,SLOT(OpenDialog()));
    QList<QRadioButton*> list = ui->groupBox->findChildren<QRadioButton*>();
    for(int i=0;i<list.size();i++)
    {
        QRadioButton* rb = list.at(i);
        connect(rb,SIGNAL(clicked()),this,SLOT(ChangeLanguage()));
    }
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
    QList<QRadioButton*> list = ui->groupBox->findChildren<QRadioButton*>();
    for(int i=0;i<list.size();i++)
    {
        QRadioButton* rb = list.at(i);
        if(rb->isChecked() && rb->accessibleName().length() > 0)
            lang->ChangeLanguage(rb->accessibleName().toInt());
    }
    ui->retranslateUi(this);
}

void MainWindow::OpenDialog()
{
    std::clog<<"MainWindow::OpenDialog()"<<std::endl;
    QDialog d;
    Ui::Dialog* dg = new Ui::Dialog;
    if(!dg)
        return;
    dg->setupUi(&d);
    delete dg;
    d.exec();
}
