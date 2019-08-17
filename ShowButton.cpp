//
// Created by ale19 on 17/08/19.
//

#include <QtGui/QDesktopServices>
#include "ShowButton.h"

ShowButton::ShowButton(QWidget *parent) : QPushButton(parent){
    this->setText("Show Results");
    this->setEnabled(false);
    connect(this, SIGNAL(pressed()), this, SLOT(showResult()));
}

//open default editor to show the result
void ShowButton::showResult() {
    QDesktopServices::openUrl(QUrl("file:/home/ale19/CLionProjects/ProgressBar/result/metadata.txt"));
}