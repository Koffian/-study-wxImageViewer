#pragma once
#include "wx/wx.h"
#include "wx/listctrl.h"
class MyMemoryPanel : public wxPanel
{
public:
	MyMemoryPanel(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* vbox;
	wxListView* m_view;

	void appendImage(wxString filename);
};

const int wxID_MEMORYVIEW = 11;