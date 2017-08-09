//
// Created by Fte on 03/08/2017.
//

#include "TaskList.h"

void TaskList::addTask(Task& t) {
    taskList.push_back(t);

}
bool TaskList::removeTask(Task &t) {// it's possible throw exception that the the task dos'nt exist!!
    for (auto it = taskList.begin();  it != taskList.end(); ++ it) {
        if(*it==t) {
            taskList.remove(*it);
            return true;
        }
    }
    //else the task not found
    return false;

}
void TaskList:: emptyList(){
    if(!taskList.empty()){
        for ( auto it=taskList.begin(); it !=taskList.end(); ++it) {

            taskList.erase(it);
            delete &it;
            //  taskList.remove(*it);
        }
        taskList.clear();
    }
}

TaskList TaskList::searchTasks(Date d) {
    TaskList l;
    for (auto it = taskList.begin();  it !=taskList.end() ; ++ it) {
        Date date;
        date=it->getDateOfTask();
        if(date==d)
            l.taskList.push_back(*it);

    }
   if (l.taskList.empty())
       std::cout<<"there is no tasks in this day";
    return l;

}


