//
// Created by Fte on 21/08/2017.
//

#ifndef TASKMANGER_PERCENT_H
#define TASKMANGER_PERCENT_H

#include "TaskList.h"
class Percent {
private:
    /*
    int todoSize;
    int doneSize;
    int ignoredSize;
     */
    int total;

public:
    /*
    Percent(int todo=0,int done=0,int ignored=0):todoSize(todo),doneSize(done),ignoredSize(ignored){
        total=todoSize+doneSize+ignoredSize;
    }
    Percent(TaskList todo,TaskList done,TaskList ignored){
        todoSize=todo.getSizeList();
        doneSize=done.getSizeList();
        ignoredSize=ignored.getSizeList();
        total=todoSize+doneSize+ignoredSize;

    }
     */

    Percent(int total=0){
        this->total=total;
    }

    int calculatePercent(TaskList taskList);

    int getTotal() const {
        return total;
    }

    void setTotal(int total) {
        Percent::total = total;
    }

};


#endif //TASKMANGER_PERCENT_H
