//
// Created by Fte on 26/08/2017.
//

#include "GUITaskManager.h"

GUITaskManager::GUITaskManager( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style )
        : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxFlexGridSizer* fgSizer3;
    fgSizer3 = new wxFlexGridSizer( 0, 3, 0, 0 );
    fgSizer3->SetFlexibleDirection( wxBOTH );
    fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
//names of lists
    ToDo = new wxStaticText( this, wxID_ANY, wxT("To Do"), wxDefaultPosition, wxDefaultSize, 0 );
    ToDo->Wrap( -1 );
    fgSizer3->Add( ToDo, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

    Done = new wxStaticText( this, wxID_ANY, wxT("Done"), wxDefaultPosition, wxDefaultSize, 0 );
    Done->Wrap( -1 );
    fgSizer3->Add( Done, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

    Ignored = new wxStaticText( this, wxID_ANY, wxT("Ignored"), wxDefaultPosition, wxDefaultSize, 0 );
    Ignored->Wrap( -1 );
    fgSizer3->Add( Ignored, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
//list Boxs
    toDoList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL );
    toDoList->SetMinSize( wxSize( 250,400 ) );

    fgSizer3->Add( toDoList, 0, wxALL|wxEXPAND, 5 );

    doneList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL );
    doneList->SetMinSize( wxSize( 250,400 ) );

    fgSizer3->Add( doneList, 0, wxALL|wxEXPAND, 5 );

    ignoredList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_HSCROLL );
    ignoredList->SetMinSize( wxSize( 250,400 ) );

    fgSizer3->Add( ignoredList, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );


    this->SetSizer( fgSizer3 );
    this->Layout();
    m_menubar1 = new wxMenuBar( 0 );
    TaskManager = new wxMenu();
    wxMenuItem* addTask;
    // choice of menu "Task Manager"
    addTask = new wxMenuItem( TaskManager, wxID_ANY, wxString( wxT("add task") ) , wxEmptyString, wxITEM_NORMAL );
    TaskManager->Append( addTask );

    wxMenuItem* removeTask;
    removeTask = new wxMenuItem( TaskManager, wxID_ANY, wxString( wxT("remove task") ) , wxEmptyString, wxITEM_NORMAL );
    TaskManager->Append( removeTask );

    wxMenuItem* moveTask;
    moveTask = new wxMenuItem( TaskManager, wxID_ANY, wxString( wxT("move task") ) , wxEmptyString, wxITEM_NORMAL );
    TaskManager->Append( moveTask );

    wxMenuItem* emptyList;
    emptyList = new wxMenuItem( TaskManager, wxID_ANY, wxString( wxT("empty list") ) , wxEmptyString, wxITEM_NORMAL );
    TaskManager->Append( emptyList );

    m_menubar1->Append( TaskManager, wxT("Task Manager") );

// choice of menu "search" and percent.

    search = new wxMenu();
    wxMenuItem* searchByDate;
    searchByDate = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by date") ) , wxEmptyString, wxITEM_NORMAL );


    wxMenuItem* searchByName;
    searchByName = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by name") ) , wxEmptyString, wxITEM_NORMAL );


    wxMenuItem* searchByDay;
    searchByDay = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by day") ) , wxEmptyString, wxITEM_NORMAL );

    wxMenuItem* searchByMonth;
    searchByMonth = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by month") ) , wxEmptyString, wxITEM_NORMAL );

    wxMenuItem* searchByYear;
    searchByYear = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by year") ) , wxEmptyString, wxITEM_NORMAL );


    wxMenuItem* todayList;
    todayList = new wxMenuItem( search, wxID_ANY, wxString( wxT("Today List") ) , wxEmptyString, wxITEM_NORMAL );


    wxMenuItem* searchByTag;
    searchByTag = new wxMenuItem( search, wxID_ANY, wxString( wxT("search by tag") ) , wxEmptyString, wxITEM_NORMAL );



    search->Append(todayList);
    search->Append( searchByName );
    search->Append( searchByDate );
    search->Append( searchByTag );
    search->Append( searchByDay );
    search->Append( searchByMonth );
    search->Append( searchByYear );


    m_menubar1->Append( search, wxT("search") );

    percent = new wxMenu();
    wxMenuItem* calculatePercent;
    calculatePercent = new wxMenuItem( percent, wxID_ANY, wxString( wxT("calculate percent") ) , wxEmptyString, wxITEM_NORMAL );
    percent->Append( calculatePercent );

    m_menubar1->Append( percent, wxT("percent") );

    this->SetMenuBar( m_menubar1 );


    this->Centre( wxBOTH );

    // Connect Events

    toDoList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );

    doneList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );
    ignoredList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );

    this->Connect( addTask->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::addTask ) );
    this->Connect( removeTask->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::removeTask ) );
    this->Connect( moveTask->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::moveTask ) );
    this->Connect( emptyList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::emptyList ) );
    this->Connect( calculatePercent->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::calculatePercent ) );
    this->Connect(todayList->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUITaskManager::getTodayList));
    this->Connect( searchByDate->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByDate ) );
    this->Connect( searchByName->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByName ) );
    this->Connect( searchByDay->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByDay ) );
    this->Connect( searchByTag->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByTag ) );
    this->Connect( searchByMonth->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByMonth ) );
    this->Connect( searchByYear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByYear ) );


}

GUITaskManager::~GUITaskManager()
{
    // Disconnect Events

    toDoList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );

    doneList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );

    ignoredList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( GUITaskManager::editTask ), NULL, this );

    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::addTask ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::removeTask ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::moveTask ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::emptyList ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::calculatePercent ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByDate ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByName ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::searchByDay ) );
    this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUITaskManager::calculatePercent ) );
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUITaskManager::getTodayList));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUITaskManager::searchByTag));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUITaskManager::searchByMonth));
    this->Disconnect(wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(GUITaskManager::searchByYear));

}


void GUITaskManager::addTask(wxCommandEvent &event) {
    //wxString mess = wxGetTextFromUser("Inserire titolo:", wxEmptyString);

    GUITask guiTask(this);
    long x = guiTask.ShowModal();
    if (x == wxID_OK) {

        wxString taskList = guiTask.getGuiSelectedList();
        wxString taskName = guiTask.getGuiNameTask();
        wxString taskColor=guiTask.getGuiColor();
        wxString taskTag=guiTask.getGuiTag();
if(taskName!=wxEmptyString){

        if (taskList == "ToDo") {
               toDoList->Append(taskName);
        } else if (taskList == "Done") {
            doneList->Append(taskName);

        } else {
            taskList="Ignored";
            ignoredList->Append(taskName);
        }
        if(guiTask.isSetted_()){
            int day=guiTask.getDayTask();
            int month=guiTask.getMonthTask();
            int year=guiTask.getYearTask();
           control->addTask(taskList,taskName,taskColor,taskTag,day,month,year);
        } else{

        control->addTask(taskList,taskName,taskColor,taskTag);}
    }else
    wxMessageBox("You did not enter name of task!");}

}

void GUITaskManager::removeTask(wxCommandEvent &event) {

    wxString taskName;
    wxListBox* selectedList;
    wxString taskList;
    bool select_= false;

    GUIRemoveTask removeTask1(this);
    if(removeTask1.ShowModal()==wxID_OK)
    {
        taskList=removeTask1.getChoiceRemove()->GetStringSelection();
        if(taskList=="ToDo"){
            selectedList=toDoList;

            select_=true;

        } else if(taskList=="Done"){
            selectedList=doneList;
            select_=true;


        }else if(taskList=="Ignored")
        {
            selectedList=ignoredList;
            select_=true;

        } else
            wxMessageBox("You did not select any list!");

        if(select_){
            bool found=false;
            taskName=removeTask1.getTaskRemove()->GetLineText(0);
            int i = selectedList->GetCount()-1;
            while(i>=0 && !found) {
                if(taskName==selectedList->GetString(i))
                {found=true;

                } else
                    i--;
            }
            if(found==true){
                selectedList->Delete(i);
                control->removeTask(taskList,taskName);

            } else
                wxMessageBox("There is no such task in the selected list!");

        }



    }

}
void GUITaskManager::emptyList(wxCommandEvent &event) {
    wxTextEntryDialog dlg(this,"Choose List:'ToDo','Done','Ignored'","choose list");
    wxListBox* listBox;
    wxString taskList;
    bool select_= false;

    if ( dlg.ShowModal() == wxID_OK ) {
        taskList = dlg.GetValue();
        if (taskList == "ToDo") {
            listBox = toDoList;
            select_ = true;
        } else if (taskList == "Done")
        {
            listBox=doneList;
            select_= true;
        }else if(taskList=="Ignored") {
            listBox=ignoredList;
            select_= true;
        }else if(taskList==wxEmptyString)

            wxMessageBox("You did not enter any choice!");
         else
            wxMessageBox("There is no such list in our task manager!");

    }

    if(select_){
        for (int i = listBox->GetCount()-1; i >=0 ; --i) {
            listBox->Delete(i);

        }
        control->emptyList(taskList);

        }

    }


void GUITaskManager::moveTask(wxCommandEvent &event) {
    wxListBox* fromList;
    wxListBox* toList;
    wxString taskName;
    wxString fromList_;
    wxString toList_;
    bool select_1=false;
    bool select_2=false;
    bool found= false;

    GUIMoveTask moveTask1(this);
    if(moveTask1.ShowModal()==wxID_OK){
       fromList_= moveTask1.getFromList()->GetStringSelection();
        toList_=moveTask1.getToList()->GetStringSelection();
        taskName=moveTask1.getTaskMove()->GetLineText(0);
        if(fromList_==wxEmptyString )
            wxMessageBox("Please select 'form list'");
        if(toList_==wxEmptyString)
            wxMessageBox("Please select 'to list'");
        if(taskName==wxEmptyString)
            wxMessageBox("Please enter task!");

        if(fromList_=="ToDo") {
            fromList=toDoList;
            select_1=true;
        }
        if(fromList_=="Done") {
            fromList=doneList;
            select_1=true;

        }
        if(fromList_=="Ignored"){
            fromList=ignoredList;
            select_1= true;
        }
        if(toList_=="ToDo"){
            toList=toDoList;
            select_2=true;
        }
        if(toList_=="Done"){
            toList=doneList;
            select_2=true;
        }
        if(toList_=="Ignored"){
            toList=ignoredList;
            select_2=true;
        }
        if(toList_==fromList_) {
            wxMessageBox("You want move task to the same list! It's waste time! ");
            select_1= false;
            select_2= false;
        }

        if(select_1 && select_2 && taskName!=wxEmptyString){

            int i = fromList->GetCount()-1;
            while(i>=0 && !found) {
                if(taskName==fromList->GetString(i))
                {found=true;

                } else
                    i--;
            }
            if(found) {
                fromList->Delete(i);
                toList->Append(taskName);
                control->moveTask(fromList_,toList_,taskName);

            } else
                wxMessageBox("There is no such task in the selected list!");

        }
    }


}
void GUITaskManager::calculatePercent(wxCommandEvent &event) {

    int toDoSize=toDoList->GetCount();
    int doneSize=doneList->GetCount();
    int ignoredSize=ignoredList->GetCount();
    int total=toDoSize+doneSize+ignoredSize;
    if(total!=0) {
        int toDoPercent = toDoSize * 100 / total;
        int donePercent = doneSize * 100 / total;
        int ignoredPercent = ignoredSize * 100 / total;
/*
    control->calculatePercent();
    toDoPercent=control->getToDoPercent();
    donePercent=control->getDonePercent();
    ignoredPercent=control->getIgnoredPercent();
*/

        wxString s1 = wxString::Format(wxT("You have %d percent tasks for do it!\n\n"), toDoPercent);
        wxString s2 = wxString::Format(wxT("You achieved %d percent from tasks!\n\n"), donePercent);
        wxString s3 = wxString::Format(wxT("You ignored %d percent from tasks!\n\n"), ignoredPercent);
        wxString msg;
        wxString evaluate;

        msg.Append(s1);
        msg.Append(s2);
        msg.Append(s3);
        if (toDoPercent > 80) {
            evaluate = "You have to do more!";
        } else if (toDoPercent == 0) {
            evaluate = "Relax you have not to do any thing!";
        }
        msg.Append(evaluate);


        wxMessageBox(msg, wxT("Percent"), wxCENTRE, this);
    } else
        wxMessageBox("Lists are empties!");
}

void GUITaskManager::editTask(wxCommandEvent &event) {
    //this->GetConnectWidget()
    int pos= event.GetInt();
    wxString taskNameClicked=event.GetString();
    wxObject* listBoxClicked= event.GetEventObject();
    wxListBox*taskListOrigin;
    wxString taskListOrigin_;

    if(listBoxClicked==toDoList){
        taskListOrigin=toDoList;
        taskListOrigin_="ToDo";}
    else if(listBoxClicked==doneList){
        taskListOrigin=doneList;
        taskListOrigin_="Done";
    }
    else if(listBoxClicked==ignoredList) {

        taskListOrigin = ignoredList;
        taskListOrigin_="Ignored";
    }
    else
        wxMessageBox("Fatal error!!");

    GUITask guiTask(this);
    if(guiTask.ShowModal()==wxID_OK){
        wxString taskList = guiTask.getGuiSelectedList();
        wxString taskName = guiTask.getGuiNameTask();
        wxString taskColor=guiTask.getGuiColor();
        wxString taskTag=guiTask.getGuiTag();

        //wxString day

        wxListBox* changedList;
        bool changedList_=false;
        bool move_=false;
        //check list selected
        if(taskList=="ToDo")
        {
            changedList=toDoList;
            changedList_=true;
        }else if(taskList=="Done"){
            changedList=doneList;
            changedList_=true;

        }
        else if(taskList=="Ignored")
        {
            changedList=ignoredList;
            changedList_=true;
        } else {
            changedList = taskListOrigin;
            taskList=taskListOrigin_;
        }

        if(changedList_){
            if (taskListOrigin!=changedList)//move task
            {move_=true;
            }
        }
        //check name
        if(taskName==wxEmptyString){
            taskName=taskNameClicked;
        } else if(taskName!=taskNameClicked){//change name to new name
            bool found=false;
            int i = taskListOrigin->GetCount()-1;
            while(i>=0 && !found) {
                if(taskNameClicked==taskListOrigin->GetString(i))
                {found=true;

                } else
                    i--;
            }
            if(found) {
                taskListOrigin->SetString(i,taskName);
                control->changeNameOfTask(taskListOrigin_, taskNameClicked,taskName);
            }
        }
          //check color
        if(taskColor!=wxEmptyString){

           control->changeColorOfTask(taskListOrigin_,taskName,taskColor);
            }
        //check Tag
        if(taskTag!=wxEmptyString){
           control->changeTagOfTask(taskListOrigin_,taskName,taskTag);

        }

        //check date
        if(guiTask.isSetted_()) {
            int day = guiTask.getDayTask();
            int month = guiTask.getMonthTask();
            int year = guiTask.getYearTask();
            control->changeDateOfTask(taskList,taskName,day,month,year);

        }
        if(move_){
            bool found=false;

            int i = taskListOrigin->GetCount()-1;
            while(i>=0 && !found) {
                if(taskName==taskListOrigin->GetString(i))
                {found=true;

                } else
                    i--;
            }
            if(found) {
                taskListOrigin->Delete(i);
                changedList->Append(taskName);
                control->moveTask(taskListOrigin_,taskList,taskName);

            } else
                wxMessageBox("Fatal error");
        } }}

void GUITaskManager::searchByDate(wxCommandEvent &event) {
    GUIDate guiDate1(this);
    if(guiDate1.ShowModal()==wxID_OK)
    {
        guiDate1.convertToValidDate();
        int day=guiDate1.getDayTask();
        int month=guiDate1.getMonthTask();
        int year=guiDate1.getYearTask();
        control->searchByDate(day,month,year);
    }
}

void GUITaskManager::getTodayList(wxCommandEvent &event) {
    Date today;
    control->searchByDate(today.getDay(),today.getMonth(),today.getYear());
}
void GUITaskManager::searchByDay(wxCommandEvent &event) {
    int dayTask;

    wxTextEntryDialog dlg(this,"Enter day","search by date");
    dlg.SetTextValidator(wxFILTER_DIGITS);
    dlg.SetMaxLength(2);
    dlg.SetValue("1");


    if ( dlg.ShowModal() == wxID_OK ){
        dayTask= wxAtoi(dlg.GetValue());
        if(dayTask>31 || dayTask<1){
            wxMessageBox("Invalid day! we will set it at 1!");
            dayTask=1;
        }

        control->searchByDay(dayTask);

    }

    //control->searchByDay(day);
}
void GUITaskManager::searchByMonth(wxCommandEvent &event)  {
    int monthTask;

    wxTextEntryDialog dlg(this,"Enter Month","search by month");
    dlg.SetTextValidator(wxFILTER_DIGITS);
    dlg.SetMaxLength(2);
    dlg.SetValue("1");


    if ( dlg.ShowModal() == wxID_OK ){
       monthTask= wxAtoi(dlg.GetValue());
        if(monthTask>12 || monthTask<1){
            wxMessageBox("Invalid month! we will set it at 1!");
            monthTask=1;
        }

        control->searchByMonth(monthTask);

    }

    //control->searchByDay(day);
}

void GUITaskManager::searchByYear(wxCommandEvent &event) {
    int yearTask;

    wxTextEntryDialog dlg(this,"Enter year","search by year");
    dlg.SetTextValidator(wxFILTER_DIGITS);
    dlg.SetMaxLength(4);
    dlg.SetValue("2017");


    if ( dlg.ShowModal() == wxID_OK ){
        yearTask= wxAtoi(dlg.GetValue());
        if(yearTask>2090 || yearTask<2000){
            wxMessageBox("Invalid day! we will set it at 2017!");
            yearTask=2017;
        }

        control->searchByYear(yearTask);

    }

    //control->searchByDay(day);
}

void GUITaskManager::searchByName(wxCommandEvent &event) {
    wxTextEntryDialog dlg(this,"Enter name of task","search by name");
    if(dlg.ShowModal()==wxID_OK){
        wxString taskName=dlg.GetValue();
        control->searchByName(taskName);
    }

}

void GUITaskManager::searchByTag(wxCommandEvent &event) {
    wxTextEntryDialog dlg(this,"Enter one of this Tag:life, family,friends,social,"
            "studying, work, hobey, volunteer","search by tag");
    if(dlg.ShowModal()==wxID_OK){
        wxString taskTag=dlg.GetValue();

        control->searchByTag(taskTag);
    }

}




