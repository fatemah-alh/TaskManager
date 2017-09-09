//
// Created by Fte on 06/09/2017.
//

#ifndef GUI_GUIDATE_H
#define GUI_GUIDATE_H

#include <wx/wx.h>
#include <wx/valnum.h>
#include <wx/datectrl.h>

class GUIDate : public wxDialog
{
    //use validator
private:

protected:
    wxStaticText* day_;
    wxTextCtrl* day;
    wxStaticText* month_;
    wxTextCtrl* month;
    wxStaticText* year_;
    wxTextCtrl* year;
    wxButton* okDate;
    wxButton* cancelDate;
    int dayTask;
    int monthTask;
     int yearTask;


public:

    int getDayTask() const {
        return dayTask;
    }

    void setDayTask(int dayTask) {
        GUIDate::dayTask = dayTask;
    }

    int getMonthTask() const {
        return monthTask;
    }

    void setMonthTask(int monthTask) {
        GUIDate::monthTask = monthTask;
    }

    int getYearTask() const {
        return yearTask;
    }

    void setYearTask(int yearTask) {
        GUIDate::yearTask = yearTask;
    }

    GUIDate( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Date"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 251,163 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~GUIDate();


    void convertToValidDate();
    bool isLeap(int y);
    int numOfDayInMonth(int m,int y);

};

#endif //GUI_GUIDATE_H
