#include "MyOutliner.h"

MyOutliner::MyOutliner(wxPanel* parent)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(300, 400),
		wxBORDER_SUNKEN)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);


	vbox->Add(btn);
	this->SetSizer(vbox);
}

