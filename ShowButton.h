//
// Created by ale19 on 17/08/19.
//

#ifndef PROGRESSBAR_SHOWBUTTON_H
#define PROGRESSBAR_SHOWBUTTON_H


#include <QtWidgets>


class ShowButton : public QPushButton{
    Q_OBJECT
public:
    explicit ShowButton(QWidget* parent=nullptr);
public slots:
    void showResult();


};


#endif //PROGRESSBAR_SHOWBUTTON_H
