//
// Created by ale19 on 16/08/19.
//

#ifndef PROGRESSBAR_PROGRESSDIALOG_H
#define PROGRESSBAR_PROGRESSDIALOG_H

#include <string>
#include <QtWidgets/QProgressDialog>
#include "AbstractSubject.h"
#include "Observer.h"
#include "ShowButton.h"

class ProgressDialog : public QProgressDialog, public Observer{
    Q_OBJECT
public:
    explicit ProgressDialog(ShowButton* button, QWidget *parent = nullptr);

    void update(std::string progress) override;

    ~ProgressDialog() override;

private:
    ShowButton *myButton;
    QString text;
    int start_value;
};


#endif //PROGRESSBAR_PROGRESSDIALOG_H
