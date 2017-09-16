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
    explicit ListView(TaskList &taskList1){

       list=taskList1.getTaskList();
    }
    std::string printList();
    std::string printListByTag(Tag tag);
    std::string printListByDay(int d);
    std::string printListByMonth(int m);
    std::string printListByYear(int y);
    std::string printListByName(string taskName );
    void printListByColor(Color color);
    void printListByDate(Date date);

    //ByMontheAndYear, ByDayAndMonth



};

#endif //TASKMANGER_LISTVIEW_H
