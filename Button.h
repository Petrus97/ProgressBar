//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_BUTTON_H
#define PROGRESSBAR_BUTTON_H

#include <QPushButton>
#include "AbstractSubject.h"


class Button : public QPushButton, public AbstractSubject{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);
    void onClick();
private:
    QPushButton* upgrade;
};

#endif //PROGRESSBAR_BUTTON_H
