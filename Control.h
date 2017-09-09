//
// Created by fatemah on 29/08/17.
//

#ifndef TASKMANGER_CONTROL_H
#define TASKMANGER_CONTROL_H

#include "TaskList.h"
#include "Percent.h"

class Control {
protected:

    TaskList *toDo;
    TaskList *done;
    TaskList *ignored;

    int toDoPercent;
    int donePercent;
    int ignoredPercent;

public:

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

public:
    Control(TaskList* toDo,TaskList *done, TaskList *ignored):toDo(toDo),done(done)
            ,ignored(ignored){
         toDoPercent=0;
         donePercent=0;
         ignoredPercent=0;
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
    void addTask(wxString taskList,wxString taskName, wxString taskColor,wxString taskTag,
                 bool taskDone,int day,int month,int year){
        Task newTask;
        Date d(day,month,year);
        newTask.setDateOfTask(d);
        newTask.setNameOfTask(taskName.ToStdString());
        if(taskName==wxEmptyString)
            taskName="new Task";

        if(taskTag!=wxEmptyString)
            setTag(newTask,taskTag);
        if(taskColor!=wxEmptyString)
            setColor(newTask,taskColor);

        newTask.setDone(taskDone);

        if (taskList == "ToDo") {
            toDo->addTask(newTask);
        } else if (taskList == "Done") {
            done->addTask(newTask);
        } else {
            ignored->addTask(newTask);
        }


    }
    void addTask(wxString taskList,wxString taskName, wxString taskColor,wxString taskTag,
                 bool taskDone){

        Task newTask;
        newTask.setNameOfTask(taskName.ToStdString());
        if(taskName==wxEmptyString)
            taskName="new Task";

        if(taskTag!=wxEmptyString)
            setTag(newTask,taskTag);
        if(taskColor!=wxEmptyString)
            setColor(newTask,taskColor);

        newTask.setDone(taskDone);

        if (taskList == "ToDo") {
            toDo->addTask(newTask);
        } else if (taskList == "Done") {
            done->addTask(newTask);
        } else {
            ignored->addTask(newTask);
        }}



    void setTag(Task& newTask,wxString taskTag){

        //wxT("life"), wxT("family"), wxT("friends"), wxT("social"), wxT("studying"), wxT("work"), wxT("hobey"), wxT("volunteer")
        if(taskTag=="life")
            newTask.setTagTask(Tag::life);
        else if(taskTag=="family")
            newTask.setTagTask(Tag::family);
        else if(taskTag=="friends")
            newTask.setTagTask(Tag::friends);
        else if(taskTag=="social")
            newTask.setTagTask(Tag::social);
        else if(taskTag=="studying")
            newTask.setTagTask(Tag::studying);
        else  if(taskTag=="work")
            newTask.setTagTask(Tag::work);
        else if(taskTag=="hobey")
            newTask.setTagTask(Tag::hobey);
        else if(taskTag=="volunteer")
            newTask.setTagTask(Tag::volunteer);
        else
            std::cout<<"Error";

    }
    void setColor(Task& newTask, wxString taskColor){
        //("Pink"), wxT("Red"), wxT("Green"), wxT("White"), wxT("Blue"), wxT("Yellow"), wxT("Grey")
        if(taskColor=="Pink")
            newTask.setColorOfTask(Color::Pink);
        else if(taskColor=="Red")
            newTask.setColorOfTask(Color::Red);
        else if(taskColor=="Green")
            newTask.setColorOfTask(Color::Green);
        else if(taskColor=="White")
            newTask.setColorOfTask(Color::White);
        else if(taskColor=="Blue")
            newTask.setColorOfTask(Color::Blue);
        else if(taskColor=="Yellow")
            newTask.setColorOfTask(Color::Yellow);
        else if(taskColor=="Grey")
            newTask.setColorOfTask(Color::Grey);
        else
            std::cout<<"Error";



    }

    void removeTask(wxString taskList,wxString taskName){
        TaskList* task_List;
        if (taskList == "ToDo") {
            task_List=toDo;
        } else if (taskList == "Done") {
            task_List=done;
        } else {
            task_List=ignored;

        }
        task_List->removeTaskByName(taskName.ToStdString());
    }
    void emptyList(wxString taskList){
        TaskList* task_List;
        if (taskList == "ToDo") {
            task_List= toDo;

        } else if (taskList == "Done")
        {
            task_List= done;

        }else if(taskList=="Ignored") {
            task_List= ignored;
        }
        else
            wxMessageBox("There is no such list in our task manager!");
        task_List->emptyList();

    }
    void moveTask(wxString fromList,wxString toList, wxString taskName){
        TaskList* fromList_;
        TaskList* toList_;

        if(fromList=="ToDo") {
            fromList_=toDo;

        }
        if(fromList=="Done") {
            fromList_=done;
        }
        if(fromList=="Ignored"){
            fromList_=ignored;

        }
        if(toList=="ToDo"){
            toList_=toDo;

        }
        if(toList=="Done"){
            toList_=done;

        }
        if(toList=="Ignored"){
            toList_=ignored;

        }
        fromList_->moveTaskByName(*toList_,taskName.ToStdString());
    }
    void calculatePercent(){

        Percent p(*toDo,*done,*ignored);
        p.calculatePercent();
        setToDoPercent(p.getToDoPercent());
        setDonePercent( p.getDonePercent());
        setIgnoredPercent( p.getIgnoredPercent());
    }

};


#endif //TASKMANGER_CONTROL_H
