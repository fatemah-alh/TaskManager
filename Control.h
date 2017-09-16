//
// Created by fatemah on 29/08/17.
//

#ifndef TASKMANGER_CONTROL_H
#define TASKMANGER_CONTROL_H

#include <wx/wx.h>
#include "TaskList.h"
#include "Percent.h"
#include "ListView.h"

class Control {
protected:

    TaskList *toDo;
    TaskList *done;
    TaskList *ignored;

    int toDoPercent;
    int donePercent;
    int ignoredPercent;

public:

    Control(TaskList* toDo,TaskList *done, TaskList *ignored):toDo(toDo),done(done)
            ,ignored(ignored){
        toDoPercent=0;
        donePercent=0;
        ignoredPercent=0;
    }

    void addTask(wxString taskList,wxString taskName, wxString taskColor,wxString taskTag,
                 int day,int month,int year);
    void addTask(wxString taskList,wxString taskName, wxString taskColor,wxString taskTag);
    void setTag(Task& newTask,wxString taskTag);
    void setColor(Task& newTask, wxString taskColor);
    void removeTask(wxString taskList,wxString taskName);
    void emptyList(wxString taskList);
    void moveTask(wxString fromList,wxString toList, wxString taskName);
    void calculatePercent();
    void changeNameOfTask(wxString taskList, wxString taskNameClicked,wxString taskName);
    void changeColorOfTask(wxString taskList,wxString taskName,wxString taskColor);
    void changeTagOfTask(wxString taskList,wxString taskName,wxString taskTag);
    void changeDateOfTask(wxString taskList,wxString taskName,int day,int month,int year);
    void searchByDate(int day,int month,int year);
    void searchByDay(int day);
    void searchByName(wxString taskName);
    void searchByTag(wxString taskTag);
    void searchByMonth(int month);
    void searchByYear(int year);


    int getToDoPercent() const {
        return toDoPercent;
    }

    void setToDoPercent(int toDoPercent) {
        Control::toDoPercent = toDoPercent;
    }

    int getDonePercent() const {
        return donePercent;
    }

    void setDonePercent(int donePercent) {
        Control::donePercent = donePercent;
    }

    int getIgnoredPercent() const {
        return ignoredPercent;
    }

    void setIgnoredPercent(int ignoredPercent) {
        Control::ignoredPercent = ignoredPercent;
    }



    TaskList *getToDo() const {
        return toDo;
    }

    void setToDo(TaskList *toDo) {
        Control::toDo = toDo;
    }

    TaskList *getDone() const {
        return done;
    }

    void setDone(TaskList *done) {
        Control::done = done;
    }

    TaskList *getIgnored() const {
        return ignored;
    }

    void setIgnored(TaskList *ignored) {
        Control::ignored = ignored;
    }

};


#endif //TASKMANGER_CONTROL_H
