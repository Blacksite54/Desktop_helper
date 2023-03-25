#include <QMediaPlayer>
#include <QMediaContent>
#include <QMainWindow>
#include <QCommandLinkButton>
#include <QLabel>
#include <QTextEdit>
#include <QString>
#include <iostream>
#include <QProcess>
#include <QThread>
#include <QStandardPaths>
#include <Qdir>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <vector>
#include <map>
#include <QComboBox>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
    void ans();
    void switch_color();
private:
    Ui::MainWindow *ui;
    QString *Check;
    QString requestUser;
    QString *fileName;
    QMediaPlayer *player;
    QMediaContent *song;
    QStringList pathToDesktop = QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
    QString _file_name;
    QFileInfoList _list_folder;
    vector<QString> format = {"",".url",".exe",".ink", ".pdf",".dock",".wav",".mp4",".mp3"};
    QString program = pathToDesktop.first() + '/';
    QString answer;

    vector<pair<QString,vector<QString>>> synonym = {
        {{"Steam"},{"Стим","стим"}},
        {{"Blender"},{"1","2"}},
        {{"Project Zomboid"},{"зомбоид","Зомбоид"}}
    };
};
