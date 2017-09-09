//
// Created by Fte on 06/09/2017.
//

#include "GUIMoveTask.h"


GUIMoveTask::GUIMoveTask( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxFlexGridSizer* fgSizer6;
    fgSizer6 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer6->SetFlexibleDirection( wxBOTH );
    fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    fromList_ = new wxStaticText( this, wxID_ANY, wxT("From list:"), wxDefaultPosition, wxDefaultSize, 0 );
    fromList_->Wrap( -1 );
    fgSizer6->Add( fromList_, 0, wxALL, 5 );

    wxString fromListChoices[] = { wxEmptyString, wxT("ToDo"), wxT("Done"), wxT("Ignored") };
    int fromListNChoices = sizeof( fromListChoices ) / sizeof( wxString );
    fromList = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, fromListNChoices, fromListChoices, 0 );
    fromList->SetSelection( 0 );
    fgSizer6->Add( fromList, 0, wxALL, 5 );

    toList_ = new wxStaticText( this, wxID_ANY, wxT("To list:"), wxDefaultPosition, wxDefaultSize, 0 );
    toList_->Wrap( -1 );
    fgSizer6->Add( toList_, 0, wxALL, 5 );

    wxString toListChoices[] = { wxEmptyString, wxT("ToDo"), wxT("Done"), wxT("Ignored") };
    int toListNChoices = sizeof( toListChoices ) / sizeof( wxString );
    toList = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, toListNChoices, toListChoices, 0 );
    toList->SetSelection( 0 );
    fgSizer6->Add( toList, 0, wxALL, 5 );

    taskMove_ = new wxStaticText( this, wxID_ANY, wxT("Enter task"), wxDefaultPosition, wxDefaultSize, 0 );
    taskMove_->Wrap( -1 );
    fgSizer6->Add( taskMove_, 0, wxALL, 5 );

    taskMove = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer6->Add( taskMove, 0, wxALL, 5 );

    okMove = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer6->Add( okMove, 0, wxALL, 5 );

    cancelMove = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer6->Add( cancelMove, 0, wxALL, 5 );


    this->SetSizer( fgSizer6 );
    this->Layout();

    this->Centre( wxBOTH );
}

GUIMoveTask::~GUIMoveTask()
{
}

