//
// Created by Fte on 27/08/2017.
//

#ifndef TASKMANGER_GUITASK_H
#define TASKMANGER_GUITASK_H

#include "wx/wx.h"
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/dialog.h>
#include <wx/dateevt.h>
#include <wx/datectrl.h>

#include "GUIDate.h"
#include "Date.h"

#define wxID_GUITask 1000
class GUITask : public wxDialog
{
private:

protected:
    wxStaticText* choose_List;
    wxChoice* chooseList;
    wxStaticText* Task_;
    wxTextCtrl* Task;
    wxStaticText* Date_;
    wxButton* Date;
    wxStaticText* choose_Color;
    wxChoice* chooseColor;
    wxStaticText* choose_Tag;
    wxChoice* chooseTag;
    wxCheckBox* checkDone;
    wxStaticText* space;
    wxButton* ok;
    wxButton* cancel;
    wxDatePickerCtrl* datePicker;

    wxString guiNameTask;
    wxString guiColor;
    wxString guiTag;
    wxString guiSelectedList;

    bool guiDone;

    int dayTask;
    int monthTask;
    int yearTask;

    bool setted_;



    // Virtual event handlers, overide them in your derived class
    virtual void setTaskList( wxCommandEvent& event );
    virtual void setName( wxCommandEvent& event ) ;
    virtual void setDate( wxCommandEvent& event );
    virtual void setColor( wxCommandEvent& event ) ;
    virtual void setTag( wxCommandEvent& event ) ;
    virtual void setDone( wxCommandEvent& event ) ;

public:

    GUITask( wxWindow* parent, wxWindowID id = wxID_GUITask, const wxString& title = wxT("Task"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 243,274 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~GUITask();


    const wxString &getGuiNameTask() const {
        return guiNameTask;
    }

    void setGuiNameTask(const wxString &guiNameTask) {
        GUITask::guiNameTask = guiNameTask;
    }

    const wxString &getGuiColor() const {
        return guiColor;
    }

    void setGuiColor(const wxString &guiColor) {
        GUITask::guiColor = guiColor;
    }

    const wxString &getGuiTag() const {
        return guiTag;
    }

    void setGuiTag(const wxString &guiTag) {
        GUITask::guiTag = guiTag;
    }

    const wxString &getGuiSelectedList() const {
        return guiSelectedList;
    }

    void setGuiSelectedList(const wxString &guiSelectedList) {
        GUITask::guiSelectedList = guiSelectedList;
    }

    bool isGuiDone() const {
        return guiDone;
    }

    void setGuiDone(bool guiDone) {
        GUITask::guiDone = guiDone;
    }

//
    int getDayTask() const {
        return dayTask;
    }

    void setDayTask(int dayTask) {
        GUITask::dayTask = dayTask;
    }

    int getMonthTask() const {
        return monthTask;
    }

    void setMonthTask(int monthTask) {
        GUITask::monthTask = monthTask;
    }

    int getYearTask() const {
        return yearTask;
    }

    void setYearTask(int yearTask) {
        GUITask::yearTask = yearTask;
    }

    bool isSetted_() const {
        return setted_;
    }

    void setSetted_(bool setted_) {
        GUITask::setted_ = setted_;
    }

};

/*
// Virtual event handlers, overide them in your derived class
    virtual void setTaskList( wxCommandEvent& event );
    void setName( wxCommandEvent& event );
     void setDate( wxCommandEvent& event ) { event.Skip(); }
    virtual void setColor( wxCommandEvent& event );
    virtual void setTag( wxCommandEvent& event ) ;
    virtual void setDone( wxCommandEvent& event );
     void setTask( wxCommandEvent& event );



*/

#endif //TASKMANGER_GUITASK_H
