#include "GrandFrame.h"
GrandFrame::GrandFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
	wxImage::AddHandler(new wxJPEGHandler);
	wxImage::AddHandler(new wxPNGHandler);


	grandPanel = new wxPanel(this, wxID_ANY);

	wxBoxSizer* tmpVboxLeft = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* tmpVboxRight = new wxBoxSizer(wxVERTICAL);
	vbox = new wxBoxSizer(wxVERTICAL);
	hbox = new wxBoxSizer(wxHORIZONTAL);


	m_gdir = new wxGenericDirCtrl(grandPanel, wxID_DIRCTRL, wxT(""), wxPoint(-1, -1),
									wxSize(300, 400), wxFD_CHANGE_DIR);

	//m_gdir->SetFilter("*.jpg");


	m_imagePanel = new ImagePanel(grandPanel);
	m_propsPanel = new ImagePropsPanel(grandPanel);
	m_memPanel = new MyMemoryPanel(grandPanel);

	m_memPanel->SetBackgroundColour(wxT("#0f0f0f"));

	m_toolBar = new MyToolBar(grandPanel);

	tmpVboxLeft->Add(m_gdir, 0);
	tmpVboxLeft->Add(m_propsPanel, 0, wxEXPAND | wxALL, borderSize/2);
	tmpVboxLeft->Add(m_memPanel, 1, wxEXPAND | wxALL, borderSize / 2);

	tmpVboxRight->Add(m_imagePanel, 1, wxEXPAND | wxRIGHT | wxDOWN);
	tmpVboxRight->Add(m_toolBar, 0, wxEXPAND | wxRIGHT | wxDOWN);

	hbox->Add(tmpVboxLeft, 0, wxEXPAND | wxALL);
	hbox->Add(tmpVboxRight, 1, wxEXPAND | wxRIGHT | wxDOWN);

	vbox->Add(hbox, 1, wxEXPAND | wxBottom, borderSize);
	vbox->Add(new wxStaticText(grandPanel, -1, wxT("")));


	grandPanel->SetSizer(vbox);

	m_menuBar = new MyMenuBar;
	this->SetMenuBar(m_menuBar);
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(GrandFrame::OnQuit));
	Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(GrandFrame::OnOpen));
	
	//Connect(m_gdir->GetTreeCtrl()->GetId(), wxEVT_COMMAND_TREE_ITEM_ACTIVATED,
	//	wxCommandEventHandler(GrandFrame::OnGenericDirOpen));

	Connect(m_gdir->GetId(), wxEVT_DIRCTRL_FILEACTIVATED,
		wxCommandEventHandler(GrandFrame::OnGenericDirOpen));

	Connect(wxID_ROTATELEFT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(GrandFrame::OnRotateLeft));
	Connect(wxID_ROTATERIGHT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(GrandFrame::OnRotateRight));

	Connect(wxID_SCALE, wxEVT_SCROLL_THUMBTRACK,
		wxScrollEventHandler(GrandFrame::OnScale));

	Connect(wxID_SCALE, wxEVT_SCROLL_CHANGED,
		wxScrollEventHandler(GrandFrame::OnScale));

	Connect(wxID_MEMORYVIEW, wxEVT_LIST_ITEM_ACTIVATED,
		wxListEventHandler(GrandFrame::OnMemoryOpen));

	Center();
	m_imagePanel->initImage(defaultWallpaper);

}


void GrandFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void GrandFrame::OnOpen(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog* openFileDialog = new wxFileDialog(this);
	if (openFileDialog->ShowModal() == wxID_OK) {
		wxString fileName = openFileDialog->GetPath();


		if (m_imagePanel->initImage(fileName))
		{
			m_memPanel->appendImage(fileName);
			m_propsPanel->describeImage(fileName);
		}
	}
}

void GrandFrame::OnGenericDirOpen(wxCommandEvent& WXUNUSED(event)) {
	wxTreeCtrl* tree = m_gdir->GetTreeCtrl();
	wxString fileName = m_gdir->GetFilePath();
	if (fileName.empty()) { // Открыть и развернуть папку
		//tree->Toggle(tree->GetSelection());
		return;
	}

	if (m_imagePanel->initImage(fileName)) {
		m_memPanel->appendImage(fileName);
		m_propsPanel->describeImage(fileName);
	}
}


void GrandFrame::OnRotateLeft(wxCommandEvent& WXUNUSED(event)) {
	m_imagePanel->rotateImageLeft();
}

void GrandFrame::OnRotateRight(wxCommandEvent& WXUNUSED(event)) {
	m_imagePanel->rotateImageRight();
}

void GrandFrame::OnScale(wxScrollEvent& WXUNUSED(event)) {
	m_imagePanel->scaleImage(m_toolBar->m_scale->GetValue());
}

void GrandFrame::OnMemoryOpen(wxListEvent& WXUNUSED(event)) {
	long focused = m_memPanel->m_view->GetFocusedItem();
	wxString fileName = m_memPanel->m_view->GetItemText(focused, 0);
	m_imagePanel->initImage(fileName);
}