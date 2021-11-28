#pragma once
#include "wx/wx.h"
class MyToolBar : public wxPanel
{
private:
	int imageScale = 1;
public:
	MyToolBar(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* hbox;
	wxBoxSizer* vbox;
	wxButton* m_rotateButtonLeft;
	wxButton* m_rotateButtonRight;
	wxSlider* m_scale;
};

const int wxID_ROTATELEFT = 8;
const int wxID_ROTATERIGHT = 9;
const int wxID_SCALE = 10;