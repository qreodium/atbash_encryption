#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->alphabet->setText("абвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    editAlphabet(ui->alphabet->displayText());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editEncrypt(QString word)
{
    ui->lineEdit_2->setText(encrypt(word));
}

void MainWindow::editAlphabet(QString _alphabet)
{    alphabet = _alphabet;
     editEncrypt(ui->lineEdit->text());
}

QString MainWindow::encrypt(QString text)
{
    QString finalText;
    for(int i = 0; i<text.size(); i++)
    {
        qDebug() << alphabet.size();
        for(int j=0; j<alphabet.size(); j++)
        {
            if(text[i].isUpper())
            {

                if(text[i].toLower() == alphabet[j])
                {
                    finalText = finalText.append(alphabet[alphabet.size()-j-1].toUpper());
                    break;
                }
            }
            else
            {
                if(text[i] == alphabet[j])
                {
                    finalText = finalText.append(alphabet[alphabet.size()-j-1]);
                    break;
                }
            }
        }
        if(finalText.size()==i)
        {
            finalText = finalText.append(text[i]);
        }
    }
    return finalText;
}
