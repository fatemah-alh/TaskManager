//
// Created by Fte on 06/09/2017.
//

#include "GUIRemoveTask.h"


GUIRemoveTask::GUIRemoveTask( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxFlexGridSizer* fgSizer5;
    fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer5->SetFlexibleDirection( wxBOTH );
    fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    list_ = new wxStaticText( this, wxID_ANY, wxT("Choose list:"), wxDefaultPosition, wxDefaultSize, 0 );
    list_->Wrap( -1 );
    fgSizer5->Add( list_, 0, wxALL, 5 );

    wxString choiceRemoveChoices[] = { wxEmptyString, wxT("ToDo"), wxT("Done"), wxT("Ignored") };
    int choiceRemoveNChoices = sizeof( choiceRemoveChoices ) / sizeof( wxString );
    choiceRemove = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiceRemoveNChoices, choiceRemoveChoices, 0 );
    choiceRemove->SetSelection( 0 );
    fgSizer5->Add( choiceRemove, 0, wxALL, 5 );

    taskRemove_ = new wxStaticText( this, wxID_ANY, wxT("Enter task:"), wxDefaultPosition, wxDefaultSize, 0 );
    taskRemove_->Wrap( -1 );
    fgSizer5->Add( taskRemove_, 0, wxALL, 5 );

    taskRemove = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer5->Add( taskRemove, 0, wxALL, 5 );

    okRemove = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer5->Add( okRemove, 0, wxALL, 5 );

    cancelRemove = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer5->Add( cancelRemove, 0, wxALL, 5 );


    this->SetSizer( fgSizer5 );
    this->Layout();

    this->Centre( wxBOTH );
}

GUIRemoveTask::~GUIRemoveTask()
{
}

