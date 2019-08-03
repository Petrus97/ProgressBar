//
// Created by ale19 on 02/08/19.
//

#include "ProgressBar.h"

ProgressBar::ProgressBar(QWidget *parent) : QProgressBar(parent) {
    this->progressBar = new QProgressBar(parent);
    this->progressBar->setMaximum(100);
    this->progressBar->setMinimum(0);
    this->start_value = 0;
    this->progressBar->setValue(this->start_value);
    this->progressBar->setTextVisible(true);
    //this->progressBar->setAlignment(Qt::AlignLeft);
}

void ProgressBar::update(int progress) {
    this->start_value += progress;
    if (this->start_value  > ProgressBar::value() && progress < ProgressBar::maximum()) {
        ProgressBar::setValue(this->start_value);
    }
}


ProgressBar::~ProgressBar() {
    delete progressBar;
}
