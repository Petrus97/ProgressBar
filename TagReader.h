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

    void getMetadata();
    
    static int getNFiles();
    
    void setSource(const std::string &source);
    
    const std::string &getSaveFileLocation() const;

    void setSaveFileLocation(const std::string &saveFileLocation);

    ~TagReader() override;

private:
    bool isPathExist(const std::string &s);
    
private:
    std::string source;
    std::string save_file_location;
    DIR *dir;
    struct dirent *files;
    TagLib::List<TagLib::FileRef> fileList;
    static int n_files;
};


#endif //PROGRESSBAR_TAGREADER_H
