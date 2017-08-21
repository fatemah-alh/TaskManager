#include <iostream>

#include "Date.h"
#include "Task.h"
#include "TaskList.h"
#include "ListView.h"
#include "Percent.h"
int main() {
    Date d(99,15,1993);
    Date f(15,9,2017);
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");
    Task t2(f,"iscrivere nel borsa");
    Task t3(27,6,2017,"fatto esame algoritmi");
    TaskList todo;
    todo.addTask(t1);
    todo.addTask(t2);
    TaskList done;
    done.addTask(t);
    done.addTask(t3);
    TaskList ignored;
    Task t4(15,2,2018,"fai shopping");
    ignored.addTask(t4);
    //std::cout<<todo.getSizeList()<<std::endl;
    //todo.removeTask(t1);
    TaskList search;
    search=todo.searchTasksByDate(f);


    std::cout<<todo.getSizeList()<<std::endl<<done.getSizeList()<<search.getSizeList()<<std::endl;
   // todo.moveTask(ignored,t1);
   // todo.removeTask(t1);
   // todo.emptyList();
    std::cout<<"size to do"<<todo.getSizeList()<<std::endl<<ignored.getSizeList()<<std::endl;

    ListView todoView(todo);
   // todoView.printListByTag(Tag::life);
    //todoView.printList();
    todoView.printListByDay(5);

//Percent prog(todo,done,ignored);
   int total=done.getSizeList()+todo.getSizeList()+ignored.getSizeList();
    Percent prog(total);
   std::cout<< prog.calculatePercent(todo)<<"\t"<<prog.calculatePercent(ignored)<<"\t"<<prog.calculatePercent(done);
   // search=todo.searchTasksByDate(f);
   // std::cout<<search.getSizeList()<<std::endl;







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