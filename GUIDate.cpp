//
// Created by Fte on 06/09/2017.
//

#include "GUIDate.h"

GUIDate::GUIDate( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
    wxIntegerValidator<int>
            val(&dayTask, wxNUM_VAL_THOUSANDS_SEPARATOR);
    val.SetRange(0,31);
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );


    wxFlexGridSizer* fgSizer4;
    fgSizer4 = new wxFlexGridSizer( 0, 2, 0, 0 );
    fgSizer4->SetFlexibleDirection( wxBOTH );
    fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

    day_ = new wxStaticText( this, wxID_ANY, wxT("Day:"), wxDefaultPosition, wxDefaultSize, 0 );
    day_->Wrap( -1 );
    fgSizer4->Add( day_, 0, wxALL, 5 );

    day = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, val );
#ifdef __WXGTK__
    if ( !day->HasFlag( wxTE_MULTILINE ) )
	{
	day->SetMaxLength( 2 );
	}
#else
    day->SetMaxLength( 2 );
#endif
    fgSizer4->Add( day, 0, wxALL, 5 );
    wxIntegerValidator<int>
            valM(&monthTask, wxNUM_VAL_THOUSANDS_SEPARATOR);
    valM.SetRange(1,12);

    month_ = new wxStaticText( this, wxID_ANY, wxT("Month:"), wxDefaultPosition, wxDefaultSize, 0 );
    month_->Wrap( -1 );
    fgSizer4->Add( month_, 0, wxALL, 5 );

    month = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0,valM );
#ifdef __WXGTK__
    if ( !month->HasFlag( wxTE_MULTILINE ) )
	{
	month->SetMaxLength( 2 );
	}
#else
    month->SetMaxLength( 2 );
#endif
    fgSizer4->Add( month, 0, wxALL, 5 );


    year_ = new wxStaticText( this, wxID_ANY, wxT("Year:"), wxDefaultPosition, wxDefaultSize, 0 );
    year_->Wrap( -1 );
    fgSizer4->Add( year_, 0, wxALL, 5 );

    wxIntegerValidator< int>
            valY(&yearTask,  wxNUM_VAL_THOUSANDS_SEPARATOR );
    //valY.SetRange(2017,2050);


    year = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 ,valY);
#ifdef __WXGTK__
    if ( !year->HasFlag( wxTE_MULTILINE ) )
	{
	year->SetMaxLength( 4 );
	}
#else
    year->SetMaxLength( 4 );
#endif
    fgSizer4->Add( year, 0, wxALL, 5 );

    okDate = new wxButton( this, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer4->Add( okDate, 0, wxALL, 5 );

    cancelDate = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    fgSizer4->Add( cancelDate, 0, wxALL, 5 );



    this->SetSizer( fgSizer4 );
    this->Layout();

    this->Centre( wxBOTH );
}

GUIDate::~GUIDate()
{
}


bool GUIDate::isLeap(int y){
    if ((y% 4 == 0) || (y% 400 == 0 && y % 100 == 0))
        return true;
    return false;

}
int GUIDate::numOfDayInMonth(int m,int y) {
    if (m==2){
        if(isLeap(y))
            return 29;
        else
            return 28;
    }
    else if(m==1 || m==3 || m==5 ||m==7 ||m==8 || m==10 ||m==12)
        return 31;
    else
        return 30;
}

void GUIDate::convertToValidDate() {

    int n=numOfDayInMonth(monthTask,yearTask);//

    if (dayTask >n ){
        setDayTask(n);
        wxString msg = wxString::Format(wxT("wrong day!Day will be setted to %d"), dayTask);
        wxMessageBox(msg ,wxT("a message"), wxCENTRE , this);
    }
}
