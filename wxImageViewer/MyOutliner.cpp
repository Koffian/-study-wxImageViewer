#include "MyOutliner.h"


MyOutliner::MyOutliner(wxPanel* parent)
	: wxPanel(	parent,
				-1,
				wxPoint(-1, -1),
				wxSize(300, 400),
				wxBORDER_SUNKEN)
{

	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);
	m_gdir = new wxGenericDirCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1),
		wxSize(300, 400), wxFD_CHANGE_DIR);

	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

	hbox->Add(new wxStaticText(this, wxID_ANY, wxT("Фильтры: ")));
	hbox->Add(new wxRadioButton(this, ID_JPEG_FILTER, wxT("jpg")));
	hbox->Add(new wxRadioButton(this, ID_PNG_FILTER, wxT("png")));
	hbox->Add(new wxRadioButton(this, ID_BMP_FILTER, wxT("bmp")));

	vbox->Add(m_gdir, 1, wxEXPAND | wxALL);
	vbox->Add(hbox, 0);
	this->SetSizer(vbox);

	Connect(ID_JPEG_FILTER, wxEVT_RADIOBUTTON,
		wxCommandEventHandler(MyOutliner::OnJpegFilter));
}

void MyOutliner::OnJpegFilter(wxCommandEvent& event) {
	m_gdir->SetFilter(wxT("*.jpg"));
	m_gdir->Update();
}

