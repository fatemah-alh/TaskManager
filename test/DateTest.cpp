//
// Created by Fte on 11/08/2017.
//

#include "gtest/gtest.h"
#include "../Date.h"


TEST(Date,constructur1){
Date d(15,9,2017);
ASSERT_EQ(15,d.getDay);
ASSERT_EQ(9,d.getMonth);
ASSERT_EQ(15,d.getyear);

}














/*
 *
TEST(DataGregoriana, Constructor1) {
    DataGregoriana d(1,1,2016);
    EXPECT_THROW(d.setMese(13), std::invalid_argument);

}

TEST(DataGregoriana, Constructor2) {
    DataGregoriana m(2, 3, 2016);
    ASSERT_EQ(2, m.getGiorno());
    ASSERT_EQ(3, m.getMese());
    ASSERT_EQ(2016, m.getAnno());

}

TEST(DataGregoriana, Bisestile) {//riconosce un anno bisestile?
    DataGregoriana e(29, 2, 2016);
    ASSERT_EQ(29, e.getGiorno());
    ASSERT_EQ(2, e.getMese());
    ASSERT_EQ(2016, e.getAnno());
}

TEST(DataGregoriana, setGiorno) {
    DataGregoriana m(2, 4, 2016);
    ASSERT_THROW(m.setGiorno(31), std::invalid_argument);
    ASSERT_EQ(2, m.getGiorno());
    ASSERT_NO_THROW(m.setGiorno(15));
    ASSERT_EQ(15, m.getGiorno());
}

TEST(DataGregoriana, operatore) {
    DataGregoriana m(17, 5, 2016);
    DataGregoriana e(18, 5, 2016);
    DataGregoriana f(19, 5, 2016);
    ASSERT_TRUE(m < e);
    ASSERT_FALSE(f < e);
    ASSERT_FALSE(f < f);
}


 */