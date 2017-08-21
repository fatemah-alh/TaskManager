//
// Created by Fte on 07/08/2017.
//

#include "ListView.h"

void ListView::printList() {

    if(!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it) {
            std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                     <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;


        }
    }
}

void ListView::printListByTag(Tag tag) {
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getTagTask()==tag){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }

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

void ListView::printListByDay(int d ){
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getDay()==d){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }

}

void ListView::printListByMonth(int m) {
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getMonth()==m){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }

}

void ListView::printListByYear(int y) {
    if (!list.empty()){
        for (auto it = list.begin();  it!=list.end() ; ++it){
            if(it->getDateOfTask().getYear()==y){
                std::cout<<it->getNameOfTask()<<"\t"<<it->getDateOfTask().getDay()
                         <<"/"<<it->getDateOfTask().getMonth()<<"/"<<it->getDateOfTask().getYear()<<std::endl;

            }
        }

    }
}