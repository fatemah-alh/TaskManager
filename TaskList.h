//
// Created by Fte on 03/08/2017.
//

#ifndef TASKMANGER_TASKLIST_H
#define TASKMANGER_TASKLIST_H

#include "Task.h"
#include <list>

class TaskList {
private:
    std::list<Task> taskList;

public:
    TaskList(){};// how to initializer list//
    ~TaskList(){/*

        for ( auto it=taskList.begin(); it !=taskList.end(); ++it) {

            taskList.erase(it);
            delete &it;
          //  taskList.remove(*it);
        }
        taskList.clear();
*/
    };//delete objects Task

    void addTask(Task& t);
    bool removeTask(Task& t);// remove task from list, need pointer or ref,
    // trow an execption if task not in task!?
    // it's possible receve name of list
    // when move task form to-do to other list, use earse element!, it's pointed!

    // void printList();// print namoe of taske in list if there is list
    void emptyList();
    TaskList searchTasks(Date d);// by day,month,year, by name

    //sugg:: board of Task list, possible creare in class board list of Tasklist!

    const std::list<Task> &getTaskList() const {
        return taskList;
    }

    void setTaskList(const std::list<Task> &taskList) {
        TaskList::taskList = taskList;
    }

    int getSizeList() const {
        return taskList.size();
    }

};

#endif //TASKMANGER_TASKLIST_H
