#include "MyMemoryPanel.h"

MyMemoryPanel::MyMemoryPanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);

	wxStaticText* tmp_btn = new wxStaticText(this, 
		wxID_ANY, wxT("Последние изображения"),
		wxDefaultPosition,
		wxDefaultSize);

	m_view = new wxListView(this, wxID_MEMORYVIEW, wxDefaultPosition, wxDefaultSize);
	m_view->InsertColumn(0, "Путь", wxLIST_ALIGN_LEFT, wxLIST_AUTOSIZE);
	m_view->InsertColumn(1, "Дата открытия", wxLIST_ALIGN_LEFT, wxLIST_AUTOSIZE);

	vbox->Add(tmp_btn, 0, wxEXPAND );
	vbox->Add(m_view, 1, wxEXPAND | wxBottom);

	this->SetSizer(vbox);
}

void MyMemoryPanel::appendImage(wxString filename) {
	wxDateTime now = wxDateTime::Now();
	wxString date = now.Format();


	int index = m_view->GetItemCount();

	m_view->InsertItem(index, filename);
	m_view->SetItem(index, 1, date);

	m_view->SetItemData(index, 15);
}