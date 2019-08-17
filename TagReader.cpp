//
// Created by ale19 on 13/08/19.
//

#include "TagReader.h"
#include <fstream>
#include <unistd.h>

TagReader::TagReader(){
    this->source = "/media/ale19/Acer/Users/Alessio.celeste64-PC/Downloads/Torrent_Download/Рок в Авто ( Зарубежный) - Collection  MP3 SMG/SomeMusic/";
    this->files = nullptr;
    this->n_files = 0;
    this->dir = nullptr;
}

void TagReader::getMetadata() {
    //if(source != nullptr)
    //    this->source = source;
    this->dir = opendir(this->source.c_str());
    if(this->dir != nullptr){
        while((this->files = readdir(this->dir))){ //read the directory
           // usleep(100000);
            std::string tmp = this->files->d_name;
            std::string extension;
            int i = (int)tmp.length() - 1;
            while(tmp.at(i) != '.'){ //check the extension
                extension = tmp.at(i) + extension;
                i--;
            }
            if (extension == "mp3") {
                std::string current_file = (this->source)+(files->d_name); //require all path to read the metadata
                TagLib::FileRef f(current_file.c_str()); //require a const char*
                if(!f.isNull() && f.tag()) //check if file has audio properties and is not a nullpointer
                    this->fileList.append(f);
                this->n_files++;
            }
        }
    }
    closedir(this->dir);
    //Start to reading metadata and writing to a file
    std::ofstream metadata;
    metadata.open("../result/metadata.txt");
    TagLib::List<TagLib::FileRef>::ConstIterator it;
    for(it = fileList.begin(); it != fileList.end(); ++it) {
        usleep(100000);
        TagLib::Tag *tag = (*it).tag();
        std::string str = it->file()->name(); //complete file name path
        notify(str.erase(str.find(this->source), this->source.length())); //show only the name
        metadata << "\n#############################\n"<< std::endl;
        metadata << str << std::endl;
        metadata << "title   - \"" << tag->title() << "\"" << std::endl;
        metadata << "artist  - \"" << tag->artist() << "\"" << std::endl;
        metadata << "album   - \"" << tag->album() << "\"" << std::endl;
        metadata << "year    - \"" << tag->year() << "\"" << std::endl;
        metadata << "comment - \"" << tag->comment() << "\"" << std::endl;
        metadata << "track   - \"" << tag->track() << "\"" << std::endl;
        metadata << "genre   - \"" << tag->genre() << "\"" << std::endl;
    }
    metadata.close();
    fileList.clear();
}

int TagReader::getNFiles(){
    return n_files;
}

TagReader::~TagReader() = default;
