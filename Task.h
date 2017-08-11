//
// Created by Fte on 03/08/2017.
//

#ifndef TASKMANGER_TASK_H
#define TASKMANGER_TASK_H
#include <iostream>
#include "Date.h"
#include "Color.h"

using std::string;
class Task {
private:
    string nameOfTask;
    bool done;
    Date dateOfTask;
    Color colorOfTask;
public:

    explicit Task (string s="New Task",Color c= Color ::rose, bool done= false):nameOfTask(s),colorOfTask(c),done(done){};
    explicit Task(Date d,string s="New Task",Color c= Color ::rose, bool done= false):dateOfTask(d),nameOfTask(s),colorOfTask(c),done(done){};
    Task ( int d, int m, int y,string s="New Task",Color c= Color ::rose, bool done= false):dateOfTask(d,m,y),nameOfTask(s),colorOfTask(c),done(done){};
    Task(const Task& t);

    virtual  ~Task(){};// delete Date obj??//virtual??!!
    Task& operator =(const Task& t);
    bool operator==(const Task&t);

    const string &getNameOfTask() const {
        return nameOfTask;
    }

    void setNameOfTask(const string &nameOfTask) {
        Task::nameOfTask = nameOfTask;
    }

    const Date &getDateOfTask() const {
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
    Color getColorOfTask() const {
        return colorOfTask;
    }

    void setColorOfTask(Color colorOfTask) {
        Task::colorOfTask = colorOfTask;
    }



};


#endif //TASKMANGER_TASK_H
