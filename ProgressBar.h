//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_PROGRESSBAR_H
#define PROGRESSBAR_PROGRESSBAR_H

#include <QProgressBar>
#include "Observer.h"

class ProgressBar : public QProgressBar, public Observer{
Q_OBJECT
public:
    explicit ProgressBar(QWidget *parent = nullptr);

    void update(int progress) override;

    ~ProgressBar() override;

private:
    QProgressBar *progressBar;
    int start_value;

};


#endif //PROGRESSBAR_PROGRESSBAR_H
