//
// Created by Fte on 27/08/2017.
//

#ifndef TASKMANGER_MAIN_H
#define TASKMANGER_MAIN_H


#include <wx/wx.h>
#include "GUITaskManager.h"
#include "Control.h"



class MyApp : public wxApp {
public:

    TaskList *toDo;
    TaskList *done;
    TaskList *ignored;
    //GUITaskManager*guiTaskManager;


    virtual bool OnInit();

    int OnExit() override;


};


#endif //TASKMANGER_MAIN_H
