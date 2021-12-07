#pragma once
#include "wx/wx.h"
#include "wx/dirctrl.h"
class MyOutliner : public wxPanel
{
public:
	MyOutliner(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* vbox;
	wxButton* btn;
	wxGenericDirCtrl* m_gdir;

	void OnJpegFilter(wxCommandEvent& event);
};

const int ID_JPEG_FILTER = 20;
const int ID_PNG_FILTER = 21;
const int ID_BMP_FILTER = 22;