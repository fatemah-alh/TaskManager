//
// Created by Fte on 06/09/2017.
//

#ifndef GUI_GUIMOVETASK_H
#define GUI_GUIMOVETASK_H


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
/// Class GUIMoveTask
///////////////////////////////////////////////////////////////////////////////
class GUIMoveTask : public wxDialog
{
private:

protected:
    wxStaticText* fromList_;
    wxChoice* fromList;
    wxStaticText* toList_;
    wxChoice* toList;
    wxStaticText* taskMove_;
    wxTextCtrl* taskMove;
    wxButton* okMove;
    wxButton* cancelMove;

public:
    wxChoice *getFromList() const {
        return fromList;
    }

    void setFromList(wxChoice *fromList) {
        GUIMoveTask::fromList = fromList;
    }

    wxChoice *getToList() const {
        return toList;
    }

    void setToList(wxChoice *toList) {
        GUIMoveTask::toList = toList;
    }

    wxTextCtrl *getTaskMove() const {
        return taskMove;
    }

    void setTaskMove(wxTextCtrl *taskMove) {
        GUIMoveTask::taskMove = taskMove;
    }

    GUIMoveTask( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Move task"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 229,170 ), long style = wxDEFAULT_DIALOG_STYLE );
    ~GUIMoveTask();

};


#endif //GUI_GUIMOVETASK_H
