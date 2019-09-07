//
// Created by ale19 on 07/09/19.
//

#include "TestTagReader.h"
#include <fstream>

void TestTagReader::testMetadataRead() {
    tag.setSaveFileLocation("/home/ale19/CLionProjects/ProgressBar/tests/TestSongs/test_read2.txt");
    tag.setSource("/home/ale19/CLionProjects/ProgressBar/tests/TestSongs/");
    tag.getMetadata();
    //Use of diff system call to check
    QVERIFY(std::system("cd /home/ale19/CLionProjects/ProgressBar/tests/TestSongs diff test_read.txt test_read2.txt") == 0);
}
