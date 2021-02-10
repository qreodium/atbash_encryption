#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString alphabet;

private slots:
    void editEncrypt(QString word);
    void editAlphabet(QString _alphabet);

private:
    Ui::MainWindow *ui;
    QString encrypt(QString text);
};
#endif // MAINWINDOW_H
