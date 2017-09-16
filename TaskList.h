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
    TaskList()= default;
    ~TaskList(){};

    void addTask(Task& t);
    void removeTask(Task& t);
    void removeTaskByName(string s);
    void emptyList();
    TaskList searchTasksByDate(Date d);
    void moveTask(TaskList&l2,Task& t);
    void moveTaskByName(TaskList& l2,string s);
    void changeNameOfTask(string taskName1,string taskName2);
    void changeColorOfTask( string taskName, Color taskColor);
    void changeTagOfTask(string taskName,Tag taskTag);
    void changeDateOfTask(string taskName,Date d);
    //

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
