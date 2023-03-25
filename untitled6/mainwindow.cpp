#include "mainwindow.h"
#include "./ui_mainwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    song = new QMediaContent(QUrl::fromLocalFile("F:\\Qt project\\untitled6\\H.wav"));
    player->setMedia(*song);
    player->setVolume(40);
    player->play();
    connect(ui->button, SIGNAL(clicked()), this, SLOT(ans()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString&)) , this, SLOT(switch_color()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::switch_color(){
    QString a = ui->comboBox->currentText();
    if(a.toStdString() == "dark"){
        ui->text_1->setStyleSheet("background-color: gray");
        ui->comboBox->setStyleSheet("background-color: gray");
        ui->button->setStyleSheet("background-color: gray");
        ui->label->setStyleSheet("background-color: gray");
        ui->centralwidget->setStyleSheet("background-color: black");
        ui->menubar->setStyleSheet("background-color: gray");
        ui->statusbar->setStyleSheet("background-color: gray");
    }
    if(a.toStdString() == "white"){
        ui->text_1->setStyleSheet("background-color: white");
        ui->comboBox->setStyleSheet("background-color: white");
        ui->button->setStyleSheet("background-color: black");
        ui->button->setStyleSheet("color: green");
        ui->label->setStyleSheet("background-color: white");
        ui->centralwidget->setStyleSheet("background-color: white");
        ui->menubar->setStyleSheet("background-color: white");
        ui->statusbar->setStyleSheet("background-color: white");
    }
}


void MainWindow::ans()
{
    answer = ui->text_1->toPlainText();
    if(answer == "")
    {
        ui->label->setText("Введите тескт");
    }
    else
    {
    ui->label->setText(tr("Загружаю, сэр..."));
    song = new QMediaContent(QUrl::fromLocalFile("F:\\Qt project\\untitled6\\Dow.wav"));
    player->setMedia(*song);
    player->play();
    requestUser=ui->text_1->toPlainText();

    for(auto it = synonym.begin(); it < synonym.end(); it++)
    {
        if(it->first == answer)
        {
            break;
        }
        else
        {
            for(auto ik = it->second.begin(); ik < it->second.end(); ik++)

            {
                if(answer == (*ik))
                {
                    answer = it->first;
                    break;
                }
            }
        }
    }

    QDir dir(pathToDesktop.first());
    dir.setFilter(QDir::Dirs);
    _list_folder = dir.entryInfoList();
    int k = 0;


    ui->text_1->clear();
    for(int j = 0; j < _list_folder.size();j++)
    {
        QFileInfo fileInfo = _list_folder.at(j);
        string s = fileInfo.fileName().toStdString();
        QString _s = QString::fromStdString(s);
        _file_name = "file:///"+ program + _s  + '/' + answer;

        for(auto i : format)
        {
            if (k == 0)
            {
                _file_name = "file:///"+ program + answer;
                if(QDesktopServices::openUrl(QUrl(_file_name + i, QUrl::TolerantMode)) == true)
                {
                    break;
                }
            }
            if(k == j)
            {
                if(QDesktopServices::openUrl(QUrl(_file_name + i, QUrl::TolerantMode)) == true)
                {
                    break;
                }
            }
        }
        k++;
    }
}
}
