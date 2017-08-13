//
// Created by Fte on 11/08/2017.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Date.h"


TEST(Date,Date_Constructur){
    Date d(15,9,2017);
    ASSERT_EQ(15,d.getDay());
    ASSERT_EQ(9,d.getMonth());
    ASSERT_EQ(2017,d.getYear());

}
TEST(Date,Date_Constructur1){// if day or/and monthe irregulare
    Date d(35,13,2017);
    Date Today;
    ASSERT_EQ(d.getMonth(),Today.getMonth());//set monthe to the current month.

    ASSERT_EQ(d.getDay(),d.numOfDayInMonth(d.getMonth(),d.getYear()));//set day to number od months,


}

TEST(Date,isLeap){
    Date d;
    ASSERT_FALSE(d.isLeap(2017));
    ASSERT_TRUE(d.isLeap(2020));

}
TEST(Date,numOfDayInMonth){
    Date d;
    ASSERT_EQ(28,d.numOfDayInMonth(2,2017));
    ASSERT_EQ(31,d.numOfDayInMonth(8,2020));
    ASSERT_EQ(29,d.numOfDayInMonth(2,2020));
}
TEST(Date,operators){
    Date d(15,3,2011);
    Date d1(28,10,2017);
    Date d2(19,8,2017);
    Date d3(19,8,2017);
    Date Today;
    ASSERT_TRUE(Today>d);
    ASSERT_TRUE(d2<d1);
    ASSERT_TRUE(d3==d2);
    ASSERT_FALSE(d2==d1);
}

TEST(Date, setDay){
    Date d(31,8,2018);
    d.setDay(40);
    ASSERT_EQ(31,d.getDay());

}
TEST(Date,setMonth){
    Date d(26,12,1993);
    Date today;
    d.setMonth(20);
    ASSERT_EQ(d.getMonth(),today.getMonth());
}










