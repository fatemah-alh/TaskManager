//
// Created by Fte on 07/08/2017.
//

#include "ListView.h"

std::string ListView::printList() {
    std::string s;
    if(!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it) {
            string name=it->getNameOfTask();
            int day=it->getDateOfTask().getDay();
            int month=it->getDateOfTask().getMonth();
            int year=it->getDateOfTask().getYear();
            std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
            s=s+s1;

        }
        std::cout<<s<<std::endl;
    } else
        s="No tasks!\n";

    return s;
}

std::string ListView::printListByTag(Tag tag) {
    bool result=false;
    std::string s;
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getTagTask()==tag){
                string name=it->getNameOfTask();
                int day=it->getDateOfTask().getDay();
                int month=it->getDateOfTask().getMonth();
                int year=it->getDateOfTask().getYear();
                std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
                s=s+s1;
                result= true;
            }
        }
        if(!result)
        {
            s="";
        }

    }
    return s;

}

void ListView::printListByColor(Color color) {
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getColorOfTask()==color){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }

}
void ListView::printListByDate(Date date) {
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask()==date){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }

}

std::string ListView::printListByDay(int d ){
    bool result=false;
    std::string s;
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getDay()==d){string name=it->getNameOfTask();
                int day=it->getDateOfTask().getDay();
                int month=it->getDateOfTask().getMonth();
                int year=it->getDateOfTask().getYear();
                std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
                s=s+s1;
            result= true;
            }
        }
        if(!result)
        {
            s="";
        }

    }
    return s;

}

std::string ListView::printListByMonth(int m) {
    bool result=false;
    std::string s;
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getMonth()==m){
                string name=it->getNameOfTask();
                int day=it->getDateOfTask().getDay();
                int month=it->getDateOfTask().getMonth();
                int year=it->getDateOfTask().getYear();
                std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
                s=s+s1;
                result= true;
            }
        }
        if(!result)
        {
            s="";
        }

    }
    return s;

}
std::string ListView::printListByYear(int y) {
    bool result=false;
    std::string s;
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getYear()==y){
                string name=it->getNameOfTask();
                int day=it->getDateOfTask().getDay();
                int month=it->getDateOfTask().getMonth();
                int year=it->getDateOfTask().getYear();
                std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
                s=s+s1;
                result= true;
            }
        }
        if(!result)
        {
            s="";
        }

    }
    return s;

}


std::string ListView::printListByName(string taskName ){
    bool result=false;
    std::string s;
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getNameOfTask()==taskName){
                string name=it->getNameOfTask();
                int day=it->getDateOfTask().getDay();
                int month=it->getDateOfTask().getMonth();
                int year=it->getDateOfTask().getYear();
                std::string s1=name +"\t"+ std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year)+"\n";
                s=s+s1;
                result= true;
            }
        }
        if(!result)
        {
            s="";
        }

    }
    return s;

}
