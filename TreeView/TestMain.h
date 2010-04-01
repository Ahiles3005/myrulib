/***************************************************************
 * Name:      DataViewMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2010-03-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DATAVIEWMAIN_H
#define DATAVIEWMAIN_H

#include <wx/wx.h>

class wxTreeListCtrl;

class DataViewFrame: public wxFrame
{
	public:
		DataViewFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxWidgets Application Template"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 481,466 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~DataViewFrame();

	protected:
		enum
		{
			idMenuQuit = 1000,
			idOpenList,
			idOpenTree,
			idMenuAbout,
			idDataView,
		};

		wxStatusBar* m_statusbar;
		wxTreeListCtrl* m_dataview;

	private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
		void OnOpenList( wxCommandEvent& event ){ event.Skip(); }
		void OnOpenTree( wxCommandEvent& event ){ event.Skip(); }
        DECLARE_EVENT_TABLE()
};

#endif // DATAVIEWMAIN_H
