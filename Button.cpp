//
// Created by ale19 on 02/08/19.
//
#include "Button.h"

Button::Button(const QString &text, TagReader const& tagger, QWidget *parent) : QPushButton(text, parent) {
    this->setFixedWidth(150);
    this->animateClick(1000);
    this->tag = tagger;
    connect(this, SIGNAL(pressed()), this, SLOT(onClick())/*, Qt::ConnectionType::QueuedConnection */);
}

//use this because TagReader is not a Q_OBJECT, it's like a "wrapper"
void Button::onClick() {
    tag.getMetadata();
}
