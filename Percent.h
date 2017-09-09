//
// Created by Fte on 21/08/2017.
//

#ifndef TASKMANGER_PERCENT_H
#define TASKMANGER_PERCENT_H

#include "TaskList.h"
class Percent {
private:

    int toDoSize;
    int doneSize;
    int ignoredSize;

    int toDoPercent;
    int donePercent;
    int ignoredPercent;

    int total;

public:

    Percent(int todo=0,int done=0,int ignored=0):toDoSize(todo),doneSize(done),ignoredSize(ignored){
        total=toDoSize+doneSize+ignoredSize;
        calculatePercent();
    }
    Percent(TaskList todo,TaskList done,TaskList ignored){
        toDoSize=todo.getSizeList();
        doneSize=done.getSizeList();
        ignoredSize=ignored.getSizeList();
        total=toDoSize+doneSize+ignoredSize;
        calculatePercent();

    }

/*
    Percent(int total=0){
        this->total=total;
    }
    */

   // int calculatePercent(TaskList taskList);
    void calculatePercent();

    int getTotal() const {
        return total;
    }

    void setTotal(int total) {
        Percent::total = total;
    }

    int getToDoSize() const {
        return toDoSize;
    }

    void setToDoSize(int toDoSize) {
        Percent::toDoSize = toDoSize;
    }

    int getDoneSize() const {
        return doneSize;
    }

    void setDoneSize(int doneSize) {
        Percent::doneSize = doneSize;
    }

    int getIgnoredSize() const {
        return ignoredSize;
    }

    void setIgnoredSize(int ignoredSize) {
        Percent::ignoredSize = ignoredSize;
    }

    int getToDoPercent() const {
        return toDoPercent;
    }

    void setToDoPercent(int toDoPercent) {
        Percent::toDoPercent = toDoPercent;
    }

    int getDonePercent() const {
        return donePercent;
    }

    void setDonePercent(int donePercent) {
        Percent::donePercent = donePercent;
    }

    int getIgnoredPercent() const {
        return ignoredPercent;
    }

    void setIgnoredPercent(int ignoredPercent) {
        Percent::ignoredPercent = ignoredPercent;
    }

};


#endif //TASKMANGER_PERCENT_H
