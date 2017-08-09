//
// Created by Fte on 03/08/2017.
//

#ifndef TASKMANGER_DATE_H
#define TASKMANGER_DATE_H
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(){
        time_t now = time(0);
        tm *ltm = localtime(&now);

        day= ltm->tm_mday;
        month=1 + ltm->tm_mon;
        year=1900 + ltm->tm_year;
    }
    Date(int d, int m, int y)// how to know number of day in months!
    {
        day=d;
        month=m;
        year=y;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        if (day >31 || d<0)
            day=ltm->tm_mday;
        if(month>12 || month<0)
            month=1 + ltm->tm_mon;
    };


    //~Date(); //if there is composition, need virtual D'otr?||

    bool operator >(const Date& d);
    bool operator<(const Date &d);
    bool operator ==(const Date& d);
    //   bool isDateMinOfToday();// maby not need!

    int getDay() const {
        return day;
    }
    void setDay(int day) {
        Date::day = day;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Date::month = month;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }
};


#endif //TASKMANGER_DATE_H
