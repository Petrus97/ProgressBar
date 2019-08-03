//
// Created by ale19 on 02/08/19.
//

#ifndef PROGRESSBAR_ABSTRACTSUBJECT_H
#define PROGRESSBAR_ABSTRACTSUBJECT_H

#include <list>
#include "Observer.h"

class AbstractSubject {
public:
    virtual void attachObserver(Observer *o){
        obs.push_back(o);
    };
    virtual void detachObserver(Observer *o){
        obs.remove(o);
    };
    void deleteAllObserver(){
        obs.erase(obs.begin(), obs.end());
    };
    void notify(int progress){
        for (auto itr : obs){
            itr->update(progress);
        }
    };

    virtual ~AbstractSubject(){}



private:
    std::list<Observer* > obs;
};

#endif //PROGRESSBAR_ABSTRACTSUBJECT_H
