//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_OBSERVER_H
#define PROGRESSBAR_OBSERVER_H
class AbstractSubject;

class Observer {
public:
    virtual void update(int progress) = 0;
};
#endif //PROGRESSBAR_OBSERVER_H
