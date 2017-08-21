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
    Date(int d, int m, int y) //throw(std::invalid_argument)
    {   day=d;
        month=m;
        year=y;
        convertToValidDate();
    };


    ~Date(){}; //if there is composition, need virtual D'otr?||
    void convertToValidDate();
    bool isLeap(int y);
    int numOfDayInMonth(int m,int y);
    bool operator >(const Date& d);
    bool operator<(const Date &d);
    bool operator ==(const Date& d)const ;
    int getDay() const {
        return day;
    }
    void setDay(int day) {
        Date::day = day;
        convertToValidDate();
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Date::month = month;
        convertToValidDate();
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }
};


#endif //TASKMANGER_DATE_H
