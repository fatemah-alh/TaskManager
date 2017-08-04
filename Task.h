//
// Created by Fte on 03/08/2017.
//

#ifndef TASKMANGER_TASK_H
#define TASKMANGER_TASK_H
#include <iostream>
#include "Date.h"
using std::string;

class Task {
private:
    string nameOfTask;
    bool done;
    Date dateOfTask;
public:

    Task (string s="New Task", bool done= false):nameOfTask(s),done(done){

    };

    Task ( string s="New Task", bool done= false,int d, int m, int y):nameOfTask(s),done(done),dateOfTask(d,m,y){

    };

    Task(const Task& t);
    //~Task();// delete Date obj
    void operator =(const Task& t);

    const string &getNameOfTask() const {
        return nameOfTask;
    }

    void setNameOfTask(const string &nameOfTask) {
        Task::nameOfTask = nameOfTask;
    }

    const Date &getDateOfTask() const {//
        return dateOfTask;
    }

    void setDateOfTask(const Date &dateOfTask) {//
        Task::dateOfTask = dateOfTask;
    }

    bool isDone() const {
        return done;
    }

    void setDone(bool done) {
        Task::done = done;
    }

    //color;


};


#endif //TASKMANGER_TASK_H
