#include "MyToolBar.h"

MyToolBar::MyToolBar(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);
	hbox = new wxBoxSizer(wxHORIZONTAL);

	m_rotateButtonLeft = new wxButton(this, wxID_ROTATELEFT, "Повернуть влево");
	m_rotateButtonRight = new wxButton(this, wxID_ROTATERIGHT, "Повернуть вправо");
	m_scale = new wxSlider(this, wxID_SCALE, this->imageScale, 0, 500,
		wxDefaultPosition, wxDefaultSize, wxSL_LABELS);

	hbox->Add(m_rotateButtonLeft, 0, wxEXPAND | wxALIGN_CENTER);
	hbox->Add(m_rotateButtonRight, 0, wxEXPAND | wxALIGN_CENTER);
	hbox->Add(m_scale, 1, wxEXPAND | wxALIGN_RIGHT);

	this->SetSizer(hbox);
}