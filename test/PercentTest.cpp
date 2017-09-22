//
// Created by Fte on 22/08/2017.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Percent.h"

TEST(Percent,calculatPercent){
    Date d(99,15,1993);
    Date f(15,9,2017);
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");
    Task t2(f,"iscrivere nel borsa");
    Task t3(27,6,2017,"fatto esame algoritmi");
    Task t4(15,2,2018,"fai shopping");
    TaskList todo;
    todo.addTask(t1);
    todo.addTask(t2);
    TaskList done;
    done.addTask(t);
    done.addTask(t3);
    TaskList ignored;
    ignored.addTask(t4);
    int total=done.getSizeList()+todo.getSizeList()+ignored.getSizeList();
Percent myprog(todo,done,ignored);
    myprog.calculatePercent();
    
    ASSERT_EQ(40,myprog.getToDoPercent());
    ASSERT_EQ(40,myprog.getDonePercent());
    ASSERT_EQ(20,myprog.getIgnoredPercent());
}