//
// Created by Fte on 03/08/2017.
//

#ifndef TASKMANGER_TASK_H
#define TASKMANGER_TASK_H
#include <iostream>
#include "Date.h"
#include "Color.h"
#include "Tag.h"

using std::string;
class Task {
private:
    string nameOfTask;
    bool done;
    Date dateOfTask;
    Color colorOfTask;
    Tag tagTask;//in future possible be class category

public:

    explicit Task (string s="New Task"):nameOfTask(s){
        // Color c= Color ::rose,Tag tag=Tag::life,bool done= false
        colorOfTask= Color ::rose;
        tagTask=Tag::life;
        done= false;
    };
    explicit Task(Date d,string s="New Task"):dateOfTask(d),nameOfTask(s){
        colorOfTask= Color ::rose;
        tagTask=Tag::life;
        done= false;

    };
    Task ( int d, int m, int y,string s="New Task"):dateOfTask(d,m,y),nameOfTask(s){
        colorOfTask= Color ::rose;
        tagTask=Tag::life;
        done= false;
    };

    Task(const Task& t);

    virtual  ~Task()= default;// delete Date obj??//virtual??!!
    Task& operator =(const Task& t);
    bool operator==(const Task&t)const ;

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

    Tag getTagTask() const {
        return tagTask;
    }

    void setTagTask(Tag tagTask) {
        Task::tagTask = tagTask;
    }


};


#endif //TASKMANGER_TASK_H
