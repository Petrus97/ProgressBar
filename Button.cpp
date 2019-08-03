//
// Created by ale19 on 02/08/19.
//
#include "Button.h"

Button::Button(const QString &text, QWidget *parent) : QPushButton(text, parent) {
    this->upgrade = new QPushButton(text, parent);
    this->upgrade->setFixedSize(150, 150);
    this->upgrade->animateClick(1000);
    connect(this, SIGNAL(clicked()), this, SLOT(onClick()), Qt::ConnectionType::QueuedConnection );
}
void Button::onClick() {
    notify(10);
    //do stuff
}