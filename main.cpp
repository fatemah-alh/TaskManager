#include <iostream>

#include "Date.h"
#include "Task.h"
#include "TaskList.h"
int main() {
    Date d(99,15,1993);
    Date f(15,9,2017);
    Task t("Call mamma",Color ::yellow, true);
    Task t1(5,9,2017,"consenga il progetto");
    Task t2(f,"iscrivere nel borsa");
    Task t3(27,6,2017,"fatto esame algoritmi",Color ::red, true);
    TaskList todo;
    todo.addTask(t1);
    todo.addTask(t2);
    TaskList done;
    done.addTask(t);
    done.addTask(t3);
    TaskList ignored;
    todo.removeTask(t3);
    TaskList search;
    search=todo.searchTasks(f);

    std::cout<<todo.getSizeList()<<done.getSizeList()<<ignored.getSizeList()<<search.getSizeList();





/*
  //test Class Date
   int day;
    std::cout << d.getDay()<<d.getMonth()<<d.getYear() << std::endl;
    //std::cout<<
    f=t.getDateOfTask();
    day=t.getDateOfTask().getDay();
    std::cout << day << std::endl;
    */
    return 0;
}