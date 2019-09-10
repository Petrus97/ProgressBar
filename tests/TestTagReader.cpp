//
// Created by ale19 on 07/09/19.
//

#include "TestTagReader.h"
#include <fstream>

void TestTagReader::testMetadataRead() {
    tag.setSaveFileLocation("../TestSongs/test_read2.txt");
    tag.setSource("../../tests/TestSongs/");
    tag.getMetadata();
    //Use of diff system call to check
    QVERIFY(std::system("cd .. cd ../TestSongs diff test_read.txt test_read2.txt") == 0);
}
