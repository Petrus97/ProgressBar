//
// Created by ale19 on 13/08/19.
//

#ifndef PROGRESSBAR_TAGREADER_H
#define PROGRESSBAR_TAGREADER_H

#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <taglib/tstring.h>
#include <taglib/tag.h>
#include <dirent.h>
#include "AbstractSubject.h"


class TagReader : public AbstractSubject{
public:
    TagReader();

    //void getMetadata(std::string source = nullptr);
    void getMetadata();
    int getNFiles();

    virtual ~TagReader() override;
private:
    std::string source;
    DIR *dir;
    struct dirent *files;
    TagLib::List<TagLib::FileRef> fileList;
    int n_files;
};


#endif //PROGRESSBAR_TAGREADER_H
