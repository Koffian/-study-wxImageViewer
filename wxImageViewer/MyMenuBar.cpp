#include "MyMenuBar.h"

MyMenuBar::MyMenuBar()
	: wxMenuBar()
{
	wxMenu* file = new wxMenu;
	file->Append(wxID_EXIT, wxT("&�����"));
	file->Append(wxID_OPEN, wxT("&������� � ���������� windows"));
	this->Append(file, wxT("&����"));
}