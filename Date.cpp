//
// Created by Fte on 03/08/2017.
//

#include "Date.h"

// for compare date of task with date of today ,just create object of Date default and use == for choose the list of today ,
//use <  for move form today to ignored or done
// > for be in todo list
// use compare date (==)for view list by date
// view by month, by year by day!


bool Date::operator>(const Date &d) {
    if(year>d.year)
        return true;
    if(month>d.month)
        return true;
    if(day>d.day)
        return true;
    return false;
}

bool Date::operator<(const Date &d) {
    if(year<d.year)
        return true;
    if(month<d.month)
        return true;
    if(day<d.day)
        return true;
    return false;
}

bool Date::operator==(const Date& d) const {
    if(d.year==year && d.month==month && d.day==day)
        return true;
    else
        return false;

}

bool Date::isLeap(int y){
    if ((y% 4 == 0) || (y% 400 == 0 && y % 100 == 0))
        return true;
    return false;

}
int Date::numOfDayInMonth(int m,int y) {
    if (m==2){
        if(isLeap(y))
            return 29;
        else
            return 28;
    }
    else if(m==1 || m==3 || m==5 ||m==7 ||m==8 || m==10 ||m==12)
        return 31;
    else
        return 30;
}

void Date::convertToValidDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(month>12 || month<0)
        month=1+ltm->tm_mon;
    int n=numOfDayInMonth(month,year);
    if (day >n || day<0)
        day=n;
}// it's possible seperate the detection of day and month in two function,for use in setDay and setMonthand
// possible return error withe or without repair the logice error!.. what is the best!

/*
bool Date::isValidMonth(int m){
    if(m>12 || m<0)
        return false;
    return true;
}
bool Date::isValidDay(int d){
    if (d >numOfDayInMonth(month,year) || d<0)
        return false;
    return true;

}*/