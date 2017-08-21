//
// Created by Fte on 13/08/2017.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../TaskList.h"


TEST(TaskList, addTask){
    TaskList toDo;
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");
    Date d(15,9,2017);
    Task t2(d,"iscrivere nel borsa");
    toDo.addTask(t);
    toDo.addTask(t1);
    toDo.addTask(t2);
    auto it=toDo.getTaskList().begin();

    ASSERT_EQ(3,toDo.getSizeList());
    ASSERT_TRUE(t2==*it);
    it++;
    ASSERT_TRUE(t1==*it);
    it++;
    ASSERT_TRUE(t==*it);
}

TEST(TaskList,removeTask){
    TaskList toDo;
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");

    Date d(15,9,2017);
    Task t2(d,"iscrivere nel borsa");
    toDo.addTask(t);
    toDo.addTask(t1);
    toDo.addTask(t2);
    toDo.removeTask(t);
    ASSERT_EQ(2,toDo.getSizeList());
    toDo.removeTask(t2);
    ASSERT_EQ(1,toDo.getSizeList());
}

TEST(TaskList, emptyList){
    TaskList toDo;
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");

    Date d(15,9,2017);
    Task t2(d,"iscrivere nel borsa");
    toDo.addTask(t);
    toDo.addTask(t1);
    toDo.addTask(t2);

    toDo.emptyList();
    ASSERT_EQ(0,toDo.getSizeList());
}

TEST(TaskList,searchByDate){
    TaskList toDo;
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");

    Date d(15,9,2017);
    Task t2(d,"iscrivere nel borsa");
    toDo.addTask(t);
    toDo.addTask(t1);
    toDo.addTask(t2);

    TaskList search= toDo.searchTasksByDate(d);
    auto it =search.getTaskList().begin();

   ASSERT_TRUE(*it==t2);
}
TEST(TaskList,moveTask){
    TaskList toDo;
    TaskList done;
    Task t("Call mamma");
    Task t1(5,9,2017,"consenga il progetto");

    Date d(15,9,2017);
    Task t2(d,"iscrivere nel borsa");
    toDo.addTask(t);
    toDo.addTask(t1);
    done.addTask(t2);
    toDo.moveTask(done,t);
    ASSERT_EQ(1,toDo.getSizeList());
    ASSERT_EQ(2,done.getSizeList());


}