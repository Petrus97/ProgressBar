//
// Created by ale19 on 07/09/19.
//
#include <QTest>
#include "TestProgressDialog.h"
#include "TestTagReader.h"

int main(int argc, char * argv[]){
    TestProgressDialog testProgressDialog;
    TestTagReader testTag;
    int a, b;
    a = QTest::qExec(&testTag, argc,  argv);
    b = QTest::qExec(&testProgressDialog, argc, argv);
    qDebug() << "Overall result" << ((a+b==0)?"PASS":"FAIL");
    return a+b;
}
