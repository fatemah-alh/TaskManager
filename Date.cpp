//
// Created by Fte on 03/08/2017.
//

#include "Date.h"

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