//
// Created by ale19 on 02/08/19.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar(QWidget *parent){
    this->progressBar = new QProgressBar(parent);
    this->progressBar->setMaximum(100);
    this->progressBar->setMinimum(0);
}

void ProgressBar::update(int progress) {
    if (progress > ProgressBar::value() && progress < ProgressBar::maximum())
        ProgressBar::setValue(progress);
}

ProgressBar::~ProgressBar() {
    delete progressBar;
}
