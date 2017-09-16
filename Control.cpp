//
// Created by fatemah on 13/09/17.
//
#include "Control.h"
void Control::addTask(wxString taskList, wxString taskName, wxString taskColor, wxString taskTag, int day, int month,
                      int year) {

        Task newTask;
        Date d(day,month,year);
        newTask.setDateOfTask(d);
        newTask.setNameOfTask(taskName.ToStdString());
        if(taskName==wxEmptyString)
            taskName="new Task";

        if(taskTag!=wxEmptyString)
            setTag(newTask,taskTag);
        if(taskColor!=wxEmptyString)
            setColor(newTask,taskColor);


        if (taskList == "ToDo") {
            toDo->addTask(newTask);
        } else if (taskList == "Done") {
            done->addTask(newTask);
        } else {
            ignored->addTask(newTask);
        }


}

void Control::addTask(wxString taskList, wxString taskName, wxString taskColor, wxString taskTag)
{

    Task newTask;
    newTask.setNameOfTask(taskName.ToStdString());
    if(taskName==wxEmptyString)
        taskName="new Task";

    if(taskTag!=wxEmptyString)
        setTag(newTask,taskTag);
    if(taskColor!=wxEmptyString)
        setColor(newTask,taskColor);



    if (taskList == "ToDo") {
        toDo->addTask(newTask);
    } else if (taskList == "Done") {
        done->addTask(newTask);
    } else {
        ignored->addTask(newTask);
    }}
void Control::setTag(Task &newTask, wxString taskTag) {

    //wxT("life"), wxT("family"), wxT("friends"), wxT("social"), wxT("studying"), wxT("work"), wxT("hobey"), wxT("volunteer")
    if(taskTag=="life")
        newTask.setTagTask(Tag::life);
    else if(taskTag=="family")
        newTask.setTagTask(Tag::family);
    else if(taskTag=="friends")
        newTask.setTagTask(Tag::friends);
    else if(taskTag=="social")
        newTask.setTagTask(Tag::social);
    else if(taskTag=="studying")
        newTask.setTagTask(Tag::studying);
    else  if(taskTag=="work")
        newTask.setTagTask(Tag::work);
    else if(taskTag=="hobey")
        newTask.setTagTask(Tag::hobey);
    else if(taskTag=="volunteer")
        newTask.setTagTask(Tag::volunteer);
    else
        std::cout<<"Error";

}
void Control::setColor(Task &newTask, wxString taskColor) {
    //("Pink"), wxT("Red"), wxT("Green"), wxT("White"), wxT("Blue"), wxT("Yellow"), wxT("Grey")
    if(taskColor=="Pink")
        newTask.setColorOfTask(Color::Pink);
    else if(taskColor=="Red")
        newTask.setColorOfTask(Color::Red);
    else if(taskColor=="Green")
        newTask.setColorOfTask(Color::Green);
    else if(taskColor=="White")
        newTask.setColorOfTask(Color::White);
    else if(taskColor=="Blue")
        newTask.setColorOfTask(Color::Blue);
    else if(taskColor=="Yellow")
        newTask.setColorOfTask(Color::Yellow);
    else if(taskColor=="Grey")
        newTask.setColorOfTask(Color::Grey);
    else
        std::cout<<"Error";



}
void Control::removeTask(wxString taskList, wxString taskName) {
    TaskList* task_List;
    if (taskList == "ToDo") {
        task_List=toDo;
    } else if (taskList == "Done") {
        task_List=done;
    } else {
        task_List=ignored;

    }
    task_List->removeTaskByName(taskName.ToStdString());
}

void Control::emptyList(wxString taskList) {
    TaskList* task_List;
    if (taskList == "ToDo") {
        task_List= toDo;

    } else if (taskList == "Done")
    {
        task_List= done;

    }else if(taskList=="Ignored") {
        task_List= ignored;
    }
    else
        wxMessageBox("There is no such list in our task manager!");
    task_List->emptyList();

}
void Control::moveTask(wxString fromList, wxString toList, wxString taskName) {
    TaskList* fromList_;
    TaskList* toList_;

    if(fromList=="ToDo") {
        fromList_=toDo;

    }
    if(fromList=="Done") {
        fromList_=done;
    }
    if(fromList=="Ignored"){
        fromList_=ignored;

    }
    if(toList=="ToDo"){
        toList_=toDo;

    }
    if(toList=="Done"){
        toList_=done;

    }
    if(toList=="Ignored"){
        toList_=ignored;

    }
    fromList_->moveTaskByName(*toList_,taskName.ToStdString());
}
void Control::calculatePercent(){

    Percent p(*toDo,*done,*ignored);
    p.calculatePercent();
    setToDoPercent(p.getToDoPercent());
    setDonePercent( p.getDonePercent());
    setIgnoredPercent( p.getIgnoredPercent());
}
void Control::changeNameOfTask(wxString taskList, wxString taskNameClicked, wxString taskName) {

        TaskList* task_List;
        if (taskList == "ToDo") {
            task_List= toDo;

        } else if (taskList == "Done")
        {
            task_List= done;

        }else if(taskList=="Ignored") {
            task_List= ignored;
        }
        else
            wxMessageBox("There is no such list in our task manager!");
    task_List->changeNameOfTask(taskNameClicked.ToStdString(),taskName.ToStdString());

}

void Control::changeColorOfTask(wxString taskList, wxString taskName, wxString taskColor) {

    TaskList* task_List;
    Color c=Color::Pink;
    if (taskList == "ToDo") {
        task_List= toDo;

    } else if (taskList == "Done")
    {
        task_List= done;

    }else if(taskList=="Ignored") {
        task_List= ignored;
    }else
        wxMessageBox("There is no such list in our task manager!");

    if(taskColor=="Pink")
        c=Color::Pink;
    else if(taskColor=="Red")
        c=Color::Red;
    else if(taskColor=="Green")
        c=Color::Green;
    else if(taskColor=="White")
        c=Color::White;
    else if(taskColor=="Blue")
        c=Color::Blue;
    else if(taskColor=="Yellow")
        c=Color::Yellow;
    else if(taskColor=="Grey")
        c=Color::Grey;
    else
        std::cout<<"Error";

    task_List->changeColorOfTask(taskName.ToStdString(),c);

}

void Control::changeTagOfTask(wxString taskList, wxString taskName, wxString taskTag) {

    TaskList* task_List;
    Tag t=Tag ::life;
    Color c=Color::Pink;
    if (taskList == "ToDo") {
        task_List= toDo;

    } else if (taskList == "Done")
    {
        task_List= done;

    }else if(taskList=="Ignored") {
        task_List= ignored;
    }else
        wxMessageBox("There is no such list in our task manager!");
    if(taskTag=="life")
        t=Tag::life;
    else if(taskTag=="family")
        t=Tag::family;
    else if(taskTag=="friends")
        t=Tag::friends;
    else if(taskTag=="social")
        t=Tag::social;
    else if(taskTag=="studying")
        t=Tag::studying;
    else  if(taskTag=="work")
        t=Tag::work;
    else if(taskTag=="hobey")
        t=Tag::hobey;
    else if(taskTag=="volunteer")
       t= Tag::volunteer;
    else
        std::cout<<"Error";
    task_List->changeTagOfTask(taskName.ToStdString(),t);


}

void Control::changeDateOfTask(wxString taskList, wxString taskName, int day, int month, int year) {
    TaskList* task_List;
    if (taskList == "ToDo") {
        task_List= toDo;

    } else if (taskList == "Done")
    {
        task_List= done;

    }else if(taskList=="Ignored") {
        task_List= ignored;
    }
    else
        wxMessageBox("There is no such list in our task manager!");
    Date d(day,month,year);
    task_List->changeDateOfTask(taskName.ToStdString(),d);
}
void Control::searchByDate(int day, int month, int year) {
    Date d(day,month,year);
    TaskList toDoSearch= toDo->searchTasksByDate(d);
    TaskList doneSerch =done->searchTasksByDate(d);
    TaskList ignoredSearch=ignored->searchTasksByDate(d);
    wxString result;
    if(toDoSearch.getTaskList().empty() && doneSerch.getTaskList().empty() && ignoredSearch.getTaskList().empty()) {
        result = "No results!";
    }

    if(!toDoSearch.getTaskList().empty()){
        ListView l1(toDoSearch);
        wxString s1(l1.printList());
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(!doneSerch.getTaskList().empty()){
        ListView l2(doneSerch);
        wxString s2(l2.printList());

        result.Append("\nResults of search in Done list:\n");
        result.Append(s2);

    }
    if(!ignoredSearch.getTaskList().empty()){

        ListView l3(ignoredSearch);
        wxString s3(l3.printList());

        result.Append("\nResults of search in To Do list:\n");
        result.Append(s3);
    }

    wxMessageBox(result,"search result");
}

void Control::searchByDay(int day) {
    ListView l1(*toDo);
    wxString s1(l1.printListByDay(day));
    ListView l2(*done);
    wxString s2(l2.printListByDay(day));
    ListView l3(*ignored);
    wxString s3 (l3.printListByDay(day));
    wxString result;
    if(s1=="" && s2==""&& s3=="")
        result="There is no task in this day";
    if(s1!=""){
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(s2!=""){
        result.Append("Results of search in Done list:\n");
        result.Append(s2);

    }
    if(s3!=""){
        result.Append("Results of search in Ignored list:\n");
        result.Append(s3);
    }
    wxString adressMsg=wxString::Format(wxT("Task of day %d"), day);
    wxMessageBox(result,adressMsg);

}

void Control::searchByMonth(int month) {

    ListView l1(*toDo);
    wxString s1(l1.printListByMonth(month));
    ListView l2(*done);
    wxString s2(l2.printListByMonth(month));
    ListView l3(*ignored);
    wxString s3 (l3.printListByMonth(month));
    wxString result;
    if(s1=="" && s2==""&& s3=="")
        result="There is no task in this month";
    if(s1!=""){
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(s2!=""){
        result.Append("Results of search in Done list:\n");
        result.Append(s2);

    }
    if(s3!=""){
        result.Append("Results of search in Ignored list:\n");
        result.Append(s3);
    }
    wxString adressMsg=wxString::Format(wxT("Task of month %d"), month);
    wxMessageBox(result,adressMsg);

}

void Control::searchByYear(int year)  {
    ListView l1(*toDo);
    wxString s1(l1.printListByYear(year));
    ListView l2(*done);
    wxString s2(l2.printListByYear(year));
    ListView l3(*ignored);
    wxString s3 (l3.printListByYear(year));
    wxString result;
    if(s1=="" && s2==""&& s3=="")
        result="There is no task in this year";
    if(s1!=""){
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(s2!=""){
        result.Append("Results of search in Done list:\n");
        result.Append(s2);

    }
    if(s3!=""){
        result.Append("Results of search in Ignored list:\n");
        result.Append(s3);
    }
    wxString adressMsg=wxString::Format(wxT("Task of year %d"), year);
    wxMessageBox(result,adressMsg);

}

void Control::searchByName(wxString taskName) {
    ListView l1(*toDo);
    wxString s1(l1.printListByName(taskName.ToStdString()));
    ListView l2(*done);
    wxString s2(l2.printListByName(taskName.ToStdString()));
    ListView l3(*ignored);
    wxString s3 (l3.printListByName(taskName.ToStdString()));
    wxString result;
    if(s1=="" && s2==""&& s3=="")
        result="There is no task with this name";
    if(s1!=""){
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(s2!=""){
        result.Append("Results of search in Done list:\n");
        result.Append(s2);

    }
    if(s3!=""){
        result.Append("Results of search in Ignored list:\n");
        result.Append(s3);
    }
    wxString adressMsg=wxString::Format(wxT("Task with name '%s'"), taskName.ToStdString());
    wxMessageBox(result,adressMsg);

}


void Control::searchByTag(wxString taskTag) {
    Tag t;
    if(taskTag=="life")
        t=Tag::life;
    else if(taskTag=="family")
        t=Tag::family;
    else if(taskTag=="friends")
        t=Tag::friends;
    else if(taskTag=="social")
        t=Tag::social;
    else if(taskTag=="studying")
        t=Tag::studying;
    else  if(taskTag=="work")
        Tag::work;
    else if(taskTag=="hobey")
        Tag::hobey;
    else if(taskTag=="volunteer")
        Tag::volunteer;
    else {
        wxMessageBox("There is No such tag in the task manager, we will search of defualt tag(life)");
    }

    ListView l1(*toDo);
    wxString s1(l1.printListByTag(t));
    ListView l2(*done);
    wxString s2(l2.printListByTag(t));
    ListView l3(*ignored);
    wxString s3 (l3.printListByTag(t));
    wxString result;
    if(s1=="" && s2==""&& s3=="")
        result="There is no task with this tag";
    if(s1!=""){
        result.Append("Results of search in To Do list:\n");
        result.Append(s1);
    }
    if(s2!=""){
        result.Append("Results of search in Done list:\n");
        result.Append(s2);

    }
    if(s3!=""){
        result.Append("Results of search in Ignored list:\n");
        result.Append(s3);
    }
    wxString adressMsg=wxString::Format(wxT("Tasks with tag %s"), taskTag.ToStdString());
    wxMessageBox(result,adressMsg);

}