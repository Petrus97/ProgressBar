#include <QApplication>
#include <QVBoxLayout>
#include <QtWidgets/QLabel>

#include <taglib/taglib.h>

#include "Button.h"
#include "TagReader.h"
#include "ProgressDialog.h"
#include "ShowButton.h"


int main(int argc, char *argv[]){
    //app creation
    QApplication a{argc, argv};
    QWidget *window = new QWidget;
    QGridLayout *box = new QGridLayout;

    //objects creation
    QLabel *line = new QLabel("Extracting metadata of:");
    TagReader tagger;
    ShowButton *sButton = new ShowButton();
    ProgressDialog *progressDialog =  new ProgressDialog(sButton);
    tagger.attachObserver(progressDialog);
    Button *button = new Button("Start reading", tagger);

    //windows app properties
    window->resize(900, 500);
    window->setWindowTitle("Lab_programmazione");

    //add widgets
    box->addWidget(line);
    box->addWidget(progressDialog);
    box->addWidget(button);
    box->addWidget(sButton);

    //set window
    window->setLayout(box);
    window->show();

    return a.exec();
}