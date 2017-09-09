//
// Created by Fte on 27/08/2017.
//

#include "GUITask.h"


GUITask::GUITask( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{


    setted_=false;

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxFlexGridSizer* fgSizer3;
    fgSizer3 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer3->SetFlexibleDirection( wxBOTH );
    fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    choose_List = new wxStaticText( this, wxID_ANY, wxT("Choose list"), wxDefaultPosition, wxDefaultSize, 0 );
    choose_List->Wrap( -1 );
    fgSizer3->Add( choose_List, 0, wxALL, 5 );

    wxString chooseListChoices[] = {wxT(""), wxT("ToDo"), wxT("Done"), wxT("Ignored") };
    int chooseListNChoices = sizeof( chooseListChoices ) / sizeof( wxString );
    chooseList = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chooseListNChoices, chooseListChoices, 0 );
    chooseList->SetSelection( 0 );
    fgSizer3->Add( chooseList, 0, wxALL, 5 );

    Task_ = new wxStaticText( this, wxID_ANY, wxT("Enter task"), wxDefaultPosition, wxDefaultSize, 0 );
    Task_->Wrap( -1 );
    fgSizer3->Add( Task_, 0, wxALL, 5 );

    Task = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer3->Add( Task, 0, wxALL, 5 );

    Date_ = new wxStaticText( this, wxID_ANY, wxT("Date"), wxDefaultPosition, wxDefaultSize, 0 );
    Date_->Wrap( -1 );
    fgSizer3->Add( Date_, 0, wxALL, 5 );

    Date = new wxButton( this, wxID_ANY, wxT("Set Date"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer3->Add( Date, 0, wxALL, 5 );

    choose_Color = new wxStaticText( this, wxID_ANY, wxT("Choose color"), wxDefaultPosition, wxDefaultSize, 0 );
    choose_Color->Wrap( -1 );
    fgSizer3->Add( choose_Color, 0, wxALL, 5 );

    wxString chooseColorChoices[] = {wxT(""), wxT("Pink"), wxT("Red"), wxT("Green"), wxT("White"), wxT("Blue"), wxT("Yellow"), wxT("Grey") };
    int chooseColorNChoices = sizeof( chooseColorChoices ) / sizeof( wxString );
    chooseColor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chooseColorNChoices, chooseColorChoices, 0 );
    chooseColor->SetSelection( 0 );
    fgSizer3->Add( chooseColor, 0, wxALL, 5 );

    choose_Tag = new wxStaticText( this, wxID_ANY, wxT("Choose Tag"), wxDefaultPosition, wxDefaultSize, 0 );
    choose_Tag->Wrap( -1 );
    fgSizer3->Add( choose_Tag, 0, wxALL, 5 );

    wxString chooseTagChoices[] = { wxT(""),wxT("life"), wxT("family"), wxT("friends"), wxT("social"), wxT("studying"), wxT("work"), wxT("hobey"), wxT("volunteer") };
    int chooseTagNChoices = sizeof( chooseTagChoices ) / sizeof( wxString );
    chooseTag = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, chooseTagNChoices, chooseTagChoices, 0 );
    chooseTag->SetSelection( 0 );
    fgSizer3->Add( chooseTag, 0, wxALL, 5 );

    checkDone = new wxCheckBox( this, wxID_ANY, wxT("Done"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer3->Add( checkDone, 0, wxALL, 5 );

    space = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    space->Wrap( -1 );
    fgSizer3->Add( space, 0, wxALL, 5 );

    ok = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer3->Add( ok, 0, wxALL, 5 );

    cancel = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer3->Add( cancel, 0, wxALL, 5 );
/*
    datePicker = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
    fgSizer3->Add( datePicker, 0, wxALL, 5 );
*/

    this->SetSizer( fgSizer3 );
    this->Layout();

    this->Centre( wxBOTH );

    // Connect Events
    chooseList->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setTaskList ), NULL, this );
    Task->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUITask::setName ), NULL, this );
    Date->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUITask::setDate ), NULL, this );
    chooseColor->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setColor ), NULL, this );
    chooseTag->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setTag ), NULL, this );
    checkDone->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUITask::setDone ), NULL, this );

}

GUITask::~GUITask()
{
    // Disconnect Events
    chooseList->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setTaskList ), NULL, this );
    Task->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUITask::setName ), NULL, this );
    Date->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUITask::setDate ), NULL, this );
    chooseColor->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setColor ), NULL, this );
    chooseTag->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUITask::setTag ), NULL, this );
    checkDone->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUITask::setDone ), NULL, this );


}




void GUITask::setTaskList(wxCommandEvent &event) {
  setGuiSelectedList(chooseList->GetStringSelection());

    }
void GUITask::setName(wxCommandEvent &event) {

    setGuiNameTask(Task->GetLineText(0));

}

void GUITask::setColor(wxCommandEvent &event) {
    setGuiColor(chooseColor->GetStringSelection());



}

void  GUITask::setTag(wxCommandEvent &event) {
    setGuiTag(chooseTag->GetStringSelection());

}
void  GUITask::setDone(wxCommandEvent &event) {
    setGuiDone(checkDone->IsChecked());
}

void GUITask::setDate(wxCommandEvent &event) {
    GUIDate guiDate1(this);
    if(guiDate1.ShowModal()==wxID_OK)
    {
        guiDate1.convertToValidDate();
        setDayTask( guiDate1.getDayTask());
        setMonthTask(guiDate1.getMonthTask());
        setYearTask(guiDate1.getYearTask());
        setted_=true;

    }
}