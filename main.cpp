#include <iostream>

#include <QApplication>
#include <QVBoxLayout>

#include <taglib/taglib.h>
#include <taglib/fileref.h>
#include <taglib/tstring.h>
#include <taglib/tag.h>

#include "ProgressBar.h"
#include "Button.h"




int main(int argc, char *argv[]){
    std::cout << "******************** \"" << "Lindsey Stirling feat. Lzzy Hale - Shatter Me"<< "\" ********************" << std::endl;
    TagLib::FileRef f("/home/ale19/Scaricati/Lindsey Stirling feat. Lzzy Hale - Shatter Me.mp3");
    TagLib::Tag *tag = f.tag();
    //FIXME segmentation fault if name doesn't finish with extension
    std::cout << "-- TAG (basic) --" << std::endl;
    std::cout << "title   - \"" << tag->title()   << "\"" << std::endl;
    std::cout << "artist  - \"" << tag->artist()  << "\"" << std::endl;
    std::cout << "album   - \"" << tag->album()   << "\"" << std::endl;
    std::cout << "year    - \"" << tag->year()    << "\"" << std::endl;
    std::cout << "comment - \"" << tag->comment() << "\"" << std::endl;
    std::cout << "track   - \"" << tag->track()   << "\"" << std::endl;
    std::cout << "genre   - \"" << tag->genre()   << "\"" << std::endl;

    QApplication a{argc, argv};
    ProgressBar *progressBar = new ProgressBar;
    Button *button = new Button("Pulsante inutile");
    button->attachObserver(progressBar);
    QWidget *window = new QWidget;
    window->setFixedSize(500, 500);
    QVBoxLayout *box = new QVBoxLayout;
    box->addWidget(button);
    box->addWidget(progressBar);
    window->setLayout(box);
    window->show();
    return a.exec();
}