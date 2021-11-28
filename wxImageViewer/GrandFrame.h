#pragma once
#include "wx/wx.h"
#include "MyOutliner.h"
#include "ImagePanel.h"
#include "MyToolBar.h"
#include "MyMenuBar.h"
#include "wx/dirctrl.h"
#include "wx/dir.h"
#include "ImagePropsPanel.h"
#include "MyMemoryPanel.h"
#include "wx/aboutdlg.h"

class GrandFrame : public wxFrame
{
public:
	GrandFrame(const wxString& title);
	wxPanel* grandPanel;
	wxBoxSizer* hbox;
	wxBoxSizer* vbox;

	MyMenuBar* m_menuBar;
	ImagePanel* m_imagePanel;
	ImagePropsPanel* m_propsPanel;
	MyOutliner* m_outliner;
	wxGenericDirCtrl* m_gdir;
	MyMemoryPanel* m_memPanel;
	MyToolBar* m_toolBar;

	void OnQuit(wxCommandEvent& WXUNUSED(event));
	void OnOpen(wxCommandEvent& WXUNUSED(event));
	void OnGenericDirOpen(wxCommandEvent& WXUNUSED(event));
	void OnRotateLeft(wxCommandEvent& WXUNUSED(event));
	void OnRotateRight(wxCommandEvent& WXUNUSED(event));
	void OnScale(wxScrollEvent& WXUNUSED(event));

	void OnMemoryOpen(wxListEvent& WXUNUSED(event));
};

const int borderSize = 10;
const int wxID_DIRCTRL = 6;

const wxColour maroon = wxColour("#A66E00");

const wxString defaultWallpaper = "Images\\HighResPicture.jpg";