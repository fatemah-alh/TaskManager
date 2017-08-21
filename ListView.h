//
// Created by Fte on 07/08/2017.
//

#ifndef TASKMANGER_LISTVIEW_H
#define TASKMANGER_LISTVIEW_H

#include "TaskList.h"
#include <list>

class ListView {
private:
   //TaskList taskList;
   std::list<Task> list;
public:
    ListView(TaskList taskList1){

       list=taskList1.getTaskList();
    }
    void printList();// print name of task, and date in one list

    void printListByTag(Tag tag);

    void printListByColor(Color color);
    void printListByDate(Date date);
    void printListByDay(int d);
    void printListByMonth(int m);
    void printListByYear(int y);

    //ByMontheAndYear, ByDayAndMonth



};

#endif //TASKMANGER_LISTVIEW_H
