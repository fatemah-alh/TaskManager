//
// Created by Fte on 21/08/2017.
//

#include "Percent.h"

/*
int Percent::calculatePercent(TaskList taskList) {
    int size=taskList.getSizeList();
    return size*100/total;
}
*/

void Percent::calculatePercent() {
    toDoPercent=toDoSize*100/total;
    donePercent=doneSize*100/total;
    ignoredPercent=ignoredSize*100/total;
}