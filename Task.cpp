//
// Created by Fte on 03/08/2017.
//

#include "Task.h"

Task::Task(const Task &t) {
    nameOfTask=t.nameOfTask;
    done=t.done;
    dateOfTask=t.dateOfTask;//copy object date!!
}
void Task::operator=(const Task &t) {

}
