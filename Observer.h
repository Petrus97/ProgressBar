//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H

#include <QString>
class AbstractSubject;

class Observer {
public:
    virtual void update(std::string progress) = 0;
};
#endif //PROGRESSBAR_OBSERVER_H
