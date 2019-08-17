//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_BUTTON_H
#define PROGRESSBAR_BUTTON_H

#include <QPushButton>
#include "AbstractSubject.h"
#include "TagReader.h"


class Button : public QPushButton{
    Q_OBJECT
public:
    explicit Button(const QString &text, const TagReader& tagger, QWidget *parent = nullptr);

public slots:
    void onClick();

private:
    TagReader tag;
};

#endif //PROGRESSBAR_BUTTON_H
