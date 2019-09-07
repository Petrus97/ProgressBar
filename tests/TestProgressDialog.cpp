//
// Created by ale19 on 07/09/19.
//

#include "TestProgressDialog.h"

TestProgressDialog::TestProgressDialog(QObject *parent) : QObject(parent) {
    this->counter = 0;
}

void TestProgressDialog::update(std::string progress) {
    this->counter++;
}

void TestProgressDialog::notifyTest() {
    tag.attachObserver(this);
    tag.setSaveFileLocation("/home/ale19/CLionProjects/ProgressBar/tests/TestSongs/test_read2.txt");
    tag.setSource("/home/ale19/CLionProjects/ProgressBar/tests/TestSongs/");
    tag.getMetadata();

    QVERIFY(this->counter == 5);
}