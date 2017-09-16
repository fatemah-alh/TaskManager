//
// Created by Fte on 03/08/2017.
//

#include "TaskList.h"


void TaskList::addTask(Task& t) {
    taskList.push_front(t);
}

void TaskList::removeTask(Task &t) {// it's possible throw exception that the the task dos'nt exist!!
    bool  found= false;
    auto it = taskList.begin();
    while (it != taskList.end() && !found)
    {
        if(*it==t)
            found= true;
        else
            it++;
    }
    if(found)
            taskList.remove(*it);
    else
        std::cout<<"The task is not in the list";
    //else the task not found


}

void TaskList::removeTaskByName(string s) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==s)
            found= true;
        else
            it++;
    }
    if(found)
        taskList.remove(*it);
    else
        std::cout<<"The task is not in the list";

}
void TaskList::moveTask(TaskList &l2, Task &t) {//
    l2.addTask(t);
    removeTask(t);
}

void TaskList::moveTaskByName(TaskList &l2, string s) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==s)
            found= true;
        else
            it++;
    }
    if(found){
        std::cout<<"size of 'list from' is"<<getSizeList()<<l2.getSizeList()<<std::endl;
        l2.addTask(*it);//problem!
        removeTask(*it);
        std::cout<<"The task"<<s<<"is Moved.\n size of 'list from' is"<<getSizeList()<<
                "\n size of to list is "<<l2.getSizeList();
    }


}
// when empty lis notif list view for reprint the list..
void TaskList:: emptyList(){
    if(!taskList.empty()){

       taskList.clear();
    }
}
TaskList TaskList::searchTasksByDate(Date d){
    TaskList l;
    for (auto it = taskList.begin();  it !=taskList.end() ; ++ it) {
        Date date;
        date=it->getDateOfTask();
        if(date==d)
            l.taskList.push_back(*it);

    }
  // if (l.taskList.empty())
      // throw std::invalid_argument("There is no tasks in this day");
     //  std::cout<<"There is no tasks in this day";
    return l;

}
void TaskList::changeNameOfTask(string taskName1, string taskName2) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==taskName1)
            found= true;
        else
            it++;
    }
    if(found){
        it->setNameOfTask(taskName2);
    }
    else
        std::cout<<"wrong name of task!";

}
void TaskList::changeColorOfTask(string taskName, Color taskColor) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==taskName)
            found= true;
        else
            it++;
    }
    if(found){
        it->setColorOfTask(taskColor);
    } else
        std::cout<<"There is no such task in this list!";

}

void TaskList::changeTagOfTask(string taskName, Tag taskTag) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==taskName)
            found= true;
        else
            it++;
    }
    if(found){
        it->setTagTask(taskTag);
    } else
        std::cout<<"There is no such task in this list!";

}

void TaskList::changeDateOfTask(string taskName, Date d) {
    bool  found= false;
    auto it = taskList.begin();

    while (it != taskList.end() && !found)
    {
        if(it->getNameOfTask()==taskName)
            found= true;
        else
            it++;
    }
    if(found){
        it->setDateOfTask(d);
    } else
        std::cout<<"There is no such task in this list!";


}

