#pragma once
#include "wx/wx.h"
class MyOutliner : public wxPanel
{
public:
	MyOutliner(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* vbox;
	wxButton* btn;

};

