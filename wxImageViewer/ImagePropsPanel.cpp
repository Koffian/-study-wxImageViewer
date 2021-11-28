#include "ImagePropsPanel.h"


ImagePropsPanel::ImagePropsPanel(wxPanel* parent)
	:wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);
	//vbox->Add(tmp_btn,1,  wxEXPAND | wxBOTTOM);

	wxStaticLine* sl1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
		wxDefaultSize);
	//wxStaticLine* sl2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition,
	//	wxSize(220, 1));

	stName = new wxStaticText(this, wxID_ANY, wxT("Название:"), wxDefaultPosition);
	stNameVal = new wxStaticText(this, wxID_ANY, wxT("ИЗОБРАЖЕНИЕ"), wxDefaultPosition);
	wxBoxSizer* hboxName = new wxBoxSizer(wxHORIZONTAL);
	hboxName->Add(stName, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxName->Add(stNameVal, 0, wxEXPAND | wxALIGN_RIGHT);

	stType = new wxStaticText(this, wxID_ANY, wxT("ТИП:"), wxDefaultPosition);
	stTypeVal = new wxStaticText(this, wxID_ANY, wxT("JPEG"), wxDefaultPosition);
	wxBoxSizer* hboxType = new wxBoxSizer(wxHORIZONTAL);
	hboxType->Add(stType, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxType->Add(stTypeVal, 0, wxALIGN_RIGHT);

	stSrc = new wxStaticText(this, wxID_ANY, wxT("Расположение:"), wxDefaultPosition);
	stSrcVal = new wxStaticText(this, wxID_ANY, wxT("/home:"), wxDefaultPosition);
	wxBoxSizer* hboxSrc = new wxBoxSizer(wxHORIZONTAL);
	hboxSrc->Add(stSrc, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxSrc->Add(stSrcVal, 0, wxALIGN_RIGHT);

	stSize = new wxStaticText(this, wxID_ANY, wxT("Размер:"), wxDefaultPosition);
	stSizeVal = new wxStaticText(this, wxID_ANY, wxT("7.24 Мб"), wxDefaultPosition);
	wxBoxSizer* hboxSize = new wxBoxSizer(wxHORIZONTAL);
	hboxSize->Add(stSize, 0, wxALIGN_LEFT | wxRIGHT, propsIndent);
	hboxSize->Add(stSizeVal, 0, wxALIGN_RIGHT);


	vbox->Add(hboxName, 0, wxEXPAND | wxLEFT, leftIndent);
	vbox->Add(hboxType, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(sl1, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(hboxSrc, 0, wxEXPAND | wxLEFT | wxRIGHT, leftIndent);
	vbox->Add(hboxSize, 0, wxEXPAND | wxLEFT | wxRIGHT | wxDOWN, leftIndent);
	//vbox->Add(sl2, 1, wxEXPAND | wxLEFT | wxRIGHT);

	this->SetSizer(vbox);
}

void ImagePropsPanel::describeImage(wxString fileName) {
	wxImage img = wxImage(fileName);
	wxString type = "";
	switch (img.GetType()) {
		case wxBITMAP_TYPE_BMP:
			type = "Точечный рисунок bmp";
			break;
		case wxBITMAP_TYPE_PNG:
			type = "рисунок png";
			break;
		case wxBITMAP_TYPE_JPEG:
			type = "Изображение jpeg";
			break;
		default:
			type = "Другое";
			break;
	}
	stNameVal->SetLabel(fileName);
	stTypeVal->SetLabel(type);
	stSizeVal->SetLabel(std::to_string(img.GetWidth()) +"x"+ std::to_string(img.GetHeight()));
	stSrcVal->SetLabel(fileName);
}