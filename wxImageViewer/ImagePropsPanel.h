#pragma once
#include "wx/wx.h"
#include "wx/statline.h"
class ImagePropsPanel : public wxPanel
{
public:
	ImagePropsPanel(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* vbox;
	void describeImage(wxString fileName);

	wxStaticText* stName;
	wxStaticText* stNameVal;

	wxStaticText* stType;
	wxStaticText* stTypeVal;

	wxStaticText* stSrc;
	wxStaticText* stSrcVal;

	wxStaticText* stSize;
	wxStaticText* stSizeVal;
};

const int propsIndent = 50; // Отступ вправо для создания пустого места
const int leftIndent = 10; // Отступ cлева