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

bool Date::operator==(const Date& d) {
    if(d.year==year && d.month==month && d.day==day)
        return true;
    else
        return false;

}

/*
bool Date::isDateMinOfToday() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    if(year<1900 + ltm->tm_year)
        return true;
    if(month<1 + ltm->tm_mon)
        return true;
    if(day<ltm->tm_mday)
        return true;
    return false;

}
 */