//
// Created by ale19 on 29/08/19.
//

#ifndef PROGRESSBAR_TESTPROGRESSDIALOG_H
#define PROGRESSBAR_TESTPROGRESSDIALOG_H

#include <QtTest/QtTest>
#include <iostream>
#include "../TagReader.h"
#include "../Observer.h"

//You need to include the QTest header and declare the test functions as private slots so the test framework finds and executes it.
class TestProgressDialog : public QObject, public Observer{
Q_OBJECT
public:
    explicit TestProgressDialog(QObject *parent = nullptr);
    void update(std::string progress) override ;

private slots:
    void notifyTest();

private:
    TagReader tag;
    int counter;
};


//QTEST_MAIN(TestProgressDialog)





//TODO cmake in tests e add executable in cmake primario. Utilizzare una sottoclasse di observer con meno canzoni -> confrontare i file di tests con la system call diff
#endif //PROGRESSBAR_TESTPROGRESSDIALOG_H
