//
// Created by ale19 on 13/08/19.
//

#include "TagReader.h"
#include <fstream>
#include <unistd.h>

TagReader::TagReader(){
    this->source = "../Music/";
    this->save_file_location = "../result/metadata.txt";
    this->files = nullptr;
    this->dir = nullptr;
}

int TagReader::n_files = 0;

void TagReader::getMetadata() {
    this->dir = opendir(this->source.c_str());
    if(this->dir != nullptr){
        while((this->files = readdir(this->dir))){ //read the directory
            std::string tmp = this->files->d_name;
            std::string extension;
            int i = (int)tmp.length() - 1;
            while(tmp.at(i) != '.'){ //check the extension
                extension = tmp.at(i) + extension;
                i--;
            }
            if (extension == "mp3" || extension== "m4a") {
                std::string current_file = (this->source)+(files->d_name); //require all path to read the metadata
                TagLib::FileRef f(current_file.c_str()); //require a const char*
                if(!f.isNull() && f.tag()) //check if file has audio properties and is not a nullpointer
                    this->fileList.append(f);
                TagReader::n_files++;
            }
        }
    }
    closedir(this->dir);
    //Start to reading metadata and writing to a file
    std::ofstream metadata;
    metadata.open(getSaveFileLocation().c_str());
    TagLib::List<TagLib::FileRef>::ConstIterator it;
    for(it = fileList.begin(); it != fileList.end(); ++it) {
        usleep(10000);
        TagLib::Tag *tag = (*it).tag();  //tag iterator
        std::string str = it->file()->name(); //complete file name path
        notify(str.erase(str.find(this->source), this->source.length())); //show only the name, cut the path
        metadata << "#############################\n"<< std::endl;
        metadata << str << std::endl;
        metadata << "title   - \"" << tag->title() << "\"" << std::endl;
        metadata << "artist  - \"" << tag->artist() << "\"" << std::endl;
        metadata << "album   - \"" << tag->album() << "\"" << std::endl;
        metadata << "year    - \"" << tag->year() << "\"" << std::endl;
        metadata << "comment - \"" << tag->comment() << "\"" << std::endl;
        metadata << "track   - \"" << tag->track() << "\"" << std::endl;
        metadata << "genre   - \"" << tag->genre() << "\"\n" << std::endl;
    }
    metadata.close();
    fileList.clear();
}

int TagReader::getNFiles(){
    return n_files;
}

void TagReader::setSource(const std::string &source) {
    if(isPathExist(source))
        TagReader::source = source;
    else
        std::cerr << "Path not found" <<std::endl;
}

bool TagReader::isPathExist(const std::string &path) {
    std::cout << "Path send:   " << path << std::endl;
    const char* c_path = path.c_str();
    if(c_path == nullptr)
        return false;
    DIR* pathDir;
    bool exist = false;
    pathDir = opendir(c_path);
    //std::cout << "opendir: " << c_path << pathDir << std::endl;
    //std::cout << (pathDir != nullptr?"TROVATA":"NON TROVATA") << std::endl;
    if (pathDir != nullptr) {
        exist = true;
        closedir(pathDir);
    }
    return exist;
}

const std::string &TagReader::getSaveFileLocation() const {
    return save_file_location;
}

void TagReader::setSaveFileLocation(const std::string &saveFileLocation) {
    save_file_location = saveFileLocation;
}

TagReader::~TagReader() = default;
