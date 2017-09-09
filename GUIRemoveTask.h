//
// Created by Fte on 06/09/2017.
//

#ifndef GUI_GUIREMOVETASK_H
#define GUI_GUIREMOVETASK_H


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
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIRemoveTask
///////////////////////////////////////////////////////////////////////////////
class GUIRemoveTask : public wxDialog
{
private:

protected:
    wxStaticText* list_;
    wxChoice* choiceRemove;
    wxStaticText* taskRemove_;
    wxTextCtrl* taskRemove;
    wxButton* okRemove;
    wxButton* cancelRemove;

public:
    wxChoice *getChoiceRemove() const {
        return choiceRemove;
    }

    void setChoiceRemove(wxChoice *choiceRemove) {
        GUIRemoveTask::choiceRemove = choiceRemove;
    }

    wxTextCtrl *getTaskRemove() const {
        return taskRemove;
    }

    void setTaskRemove(wxTextCtrl *taskRemove) {
        GUIRemoveTask::taskRemove = taskRemove;
    }

    GUIRemoveTask( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Remove task"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 227,137 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~GUIRemoveTask();

};


#endif //GUI_GUIREMOVETASK_H
