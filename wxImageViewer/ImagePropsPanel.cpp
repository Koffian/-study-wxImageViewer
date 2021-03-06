#include "ImagePropsPanel.h"

ImagePropsPanel::ImagePropsPanel(wxPanel* parent)
	:wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);

	wxStaticLine* sl1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
		wxDefaultSize);

	stName = new wxStaticText(this, wxID_ANY, wxT(" ????????:"), wxDefaultPosition);
	stNameVal = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition);
	wxBoxSizer* hboxName = new wxBoxSizer(wxHORIZONTAL);
	hboxName->Add(stName, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxName->Add(stNameVal, 0, wxEXPAND);

	stType = new wxStaticText(this, wxID_ANY, wxT("???:"), wxDefaultPosition);
	stTypeVal = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition);
	wxBoxSizer* hboxType = new wxBoxSizer(wxHORIZONTAL);
	hboxType->Add(stType, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxType->Add(stTypeVal, 0);

	stSrc = new wxStaticText(this, wxID_ANY, wxT("????????????:"), wxDefaultPosition);
	stSrcVal = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition);
	wxBoxSizer* hboxSrc = new wxBoxSizer(wxHORIZONTAL);
	hboxSrc->Add(stSrc, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxSrc->Add(stSrcVal, 0);

	stSize = new wxStaticText(this, wxID_ANY, wxT("??????:"), wxDefaultPosition);
	stSizeVal = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition);
	wxBoxSizer* hboxSize = new wxBoxSizer(wxHORIZONTAL);
	hboxSize->Add(stSize, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxSize->Add(stSizeVal, 0);


	vbox->Add(hboxName, 0, wxEXPAND | wxLEFT, leftIndent);
	vbox->Add(hboxType, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(sl1, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(hboxSrc, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(hboxSize, 0, wxEXPAND | wxLEFT | wxRIGHT | wxDOWN, leftIndent);

	this->SetSizer(vbox);
}

void ImagePropsPanel::describeImage(wxString fileName) {
	wxImage img = wxImage(fileName);
	wxString type = "";
	switch (img.GetType()) {
		case wxBITMAP_TYPE_BMP:
			type = "???????? ??????? bmp";
			break;
		case wxBITMAP_TYPE_PNG:
			type = "??????? png";
			break;
		case wxBITMAP_TYPE_JPEG:
			type = "??????????? jpeg";
			break;
		default:
			type = "??????";
			break;
	}
	stNameVal->SetLabel(fileName);
	stTypeVal->SetLabel(type);
	stSizeVal->SetLabel(std::to_string(img.GetWidth()) +"x"+ std::to_string(img.GetHeight()));
	stSrcVal->SetLabel(fileName);
}