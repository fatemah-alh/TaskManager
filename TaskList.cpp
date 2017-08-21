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
void TaskList::moveTask(TaskList &l2, Task &t) {//
    l2.addTask(t);
    removeTask(t);
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
   if (l.taskList.empty())
      // throw std::invalid_argument("There is no tasks in this day");
       std::cout<<"There is no tasks in this day";

    return l;

}



