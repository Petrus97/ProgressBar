//
// Created by ale19 on 07/09/19.
//

#ifndef PROGRESSBAR_TESTTAGREADER_H
#define PROGRESSBAR_TESTTAGREADER_H


#include <QtCore/QObject>
#include <QTest>
#include "../TagReader.h"

class TestTagReader : public QObject{
Q_OBJECT
private slots:
    void testMetadataRead();
private:
    TagReader tag;
};


#endif //PROGRESSBAR_TESTTAGREADER_H
