//
// Created by ale19 on 02/08/19.
//
#include "Button.h"

Button::Button(QWidget *parent) {
    this->upgrade = new QPushButton(parent);
}
void Button::onClick() {
    notify(10);
    //do stuff
}