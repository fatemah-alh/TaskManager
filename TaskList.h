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
    TaskList()= default;// how to initializer list//
    ~TaskList(){

        for ( auto it=taskList.begin(); it !=taskList.end(); ++it) {

           // taskList.erase(it);
          delete &it;
          //  taskList.remove(*it);
        }
       // taskList.clear();

    };//delete objects Task

    void addTask(Task& t);

    void removeTask(Task& t);// remove task from list, need pointer or ref,
    // trow an execption if task not in taskList!?
    // it's possible receve name of list
    // when move task form to-do to other list, use earse element!, it's pointed!

    // void printList();// print namoe of taske in list if there is list
    void emptyList();
    TaskList searchTasksByDate(Date d);//throw(std::invalid_argument);// by day,month,year, by name

    //sugg:: board of Task list, possible creare in class board list of Tasklist!
    void moveTask(TaskList& l2,Task& t);

    int getSizeList() const {
        return taskList.size();
    }

    const std::list<Task> &getTaskList() const {
        return taskList;
    }

    void setTaskList(const std::list<Task> &taskList) {
        TaskList::taskList = taskList;
    }


};

#endif //TASKMANGER_TASKLIST_H
