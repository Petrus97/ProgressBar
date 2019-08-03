#include <iostream>
#include <QApplication>
#include <QVBoxLayout>
#include "ProgressBar.h"
#include "Button.h"


int main(int argc, char *argv[]){
    QApplication a{argc, argv};
    ProgressBar *progressBar = new ProgressBar;
    Button *button = new Button("Pulsante inutile");
    button->attachObserver(progressBar);
    QWidget *window = new QWidget;
    window->setFixedSize(500, 500);
    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(button);
    box->addWidget(progressBar);
    window->setLayout(box);
    window->show();
    return a.exec();
}