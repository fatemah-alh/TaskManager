//
// Created by Fte on 03/08/2017.
//

#include "Task.h"

Task::Task(const Task &t) {
    nameOfTask=t.nameOfTask;
    done=t.done;
    dateOfTask=Date(t.dateOfTask);
    // dateOfTask=t.dateOfTask;//copy object date!!
}
Task& Task::operator=(const Task &t) {

    nameOfTask=t.nameOfTask;
    done=t.done;
    dateOfTask=Date(t.dateOfTask);
    return *this;
}

bool Task::operator==(const Task &t) {
    if (nameOfTask==t.nameOfTask && done==t.done && dateOfTask==t.dateOfTask)
        return true;
    else
        return false;
}