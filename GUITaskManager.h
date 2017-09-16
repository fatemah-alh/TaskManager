//
// Created by Fte on 26/08/2017.
//

#ifndef TASKMANGER_GUITASKMANAGER_H
#define TASKMANGER_GUITASKMANAGER_H


#include <wx/wx.h>

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include "GUITask.h"
#include "GUIRemoveTask.h"
#include "GUIMoveTask.h"
#include "Control.h"


///////////////////////////////////////////////////////////////////////////////
/// Class GUITaskManager
///////////////////////////////////////////////////////////////////////////////
class GUITaskManager : public wxFrame
{
private:

protected:
    wxStaticText* ToDo;
    wxStaticText* Done;
    wxStaticText* Ignored;
    wxListBox* toDoList;
    wxListBox* doneList;
    wxListBox* ignoredList;
    wxMenuBar* m_menubar1;
    wxMenu* TaskManager;
    Control* control;


    wxMenu* search;
    wxMenu* percent;

    // Virtual event handlers, overide them in your derived class


     void addTask( wxCommandEvent& event );
     void removeTask( wxCommandEvent& event );
     void moveTask( wxCommandEvent& event );
     void emptyList( wxCommandEvent& event );
     void calculatePercent( wxCommandEvent& event ) ;
     void editTask( wxCommandEvent& event );
     void getTodayList(wxCommandEvent& event);
     void searchByDate( wxCommandEvent& event );
     void searchByDay( wxCommandEvent& event );
    void searchByMonth( wxCommandEvent& event );
    void searchByYear( wxCommandEvent& event );
     void searchByName( wxCommandEvent& event );
     void searchByTag(wxCommandEvent&event);




public:

    GUITaskManager( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GUITaskManager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 789,463 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    ~GUITaskManager();


    Control *getControl() const {
        return control;
    }

    void setControl(Control *control) {
        GUITaskManager::control = control;
    }

};


#endif //TASKMANGER_GUITASKMANAGER_H
