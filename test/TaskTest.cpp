//
// Created by Fte on 13/08/2017.
//



#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Task.h"

TEST(Task,constructor_defualt){
Task t;
Date today;
Tag tag=Tag ::life;
ASSERT_TRUE(today == t.getDateOfTask());// non work withe ASSERT_EQ becuase they are objects
ASSERT_EQ("New Task",t.getNameOfTask());

ASSERT_FALSE(t.getColorOfTask()==Color::Red);
ASSERT_EQ(tag,t.getTagTask());
}

TEST(Task,constructor1){
Date d(10,9,2017);
Task t(d,"Call mamma");
ASSERT_EQ("Call mamma",t.getNameOfTask());
ASSERT_TRUE(d==t.getDateOfTask());
}

TEST(Task,constructor2){

Task t(31,8,2017,"rivesione del codice");
ASSERT_TRUE(Date(31,8,2017)==t.getDateOfTask());
ASSERT_EQ(t.getNameOfTask(),"rivesione del codice");

}

TEST(Task,setMethods){
Task t(31,8,2017,"rivesione del codice");

t.setColorOfTask(Color::Blue);
ASSERT_EQ(t.getColorOfTask(),Color::Blue);

t.setTagTask(Tag::studying);
ASSERT_EQ(t.getTagTask(),Tag::studying);

t.setDateOfTask(Date(5,9,2017));
ASSERT_TRUE(Date(5,9,2017)==t.getDateOfTask());

t.setNameOfTask("second visit");
ASSERT_EQ(t.getNameOfTask(),"second visit");

}

TEST(Task,assignment){
Task t(31,8,2017,"rivesione del codice");
t.setColorOfTask(Color::Red);
t.setTagTask(Tag::work);
Task taskAssignment=t;
ASSERT_EQ(taskAssignment.getNameOfTask(),t.getNameOfTask());
Date date=taskAssignment.getDateOfTask();
ASSERT_TRUE( date== t.getDateOfTask());
ASSERT_EQ(taskAssignment.getTagTask(),t.getTagTask());
ASSERT_EQ(taskAssignment.getColorOfTask(),t.getColorOfTask());


}

TEST(Task, copyConstructor){
Task t(31,8,2017,"rivesione del codice");
t.setColorOfTask(Color::Red);
t.setTagTask(Tag::work);
Task copyTask(t);
ASSERT_EQ(copyTask.getNameOfTask(),t.getNameOfTask());
Date date=copyTask.getDateOfTask();
ASSERT_TRUE(date==t.getDateOfTask());
ASSERT_EQ(copyTask.getTagTask(),t.getTagTask());
ASSERT_EQ(copyTask.getColorOfTask(),t.getColorOfTask());
}

TEST(Task,operatorEqual){
Task t(31,8,2017,"rivesione del codice");
Task t2(31,8,2017,"rivesione del codice");
Task t3(2,3,2017,"Call mamma");
ASSERT_TRUE(t==t2);
ASSERT_FALSE(t==t3);
}
