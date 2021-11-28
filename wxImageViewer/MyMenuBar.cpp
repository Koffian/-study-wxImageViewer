#include "MyMenuBar.h"

MyMenuBar::MyMenuBar()
	: wxMenuBar()
{
	wxMenu* file = new wxMenu;
	file->Append(wxID_EXIT, wxT("&Выйти"));
	file->Append(wxID_OPEN, wxT("&Открыть в проводнике windows"));
	this->Append(file, wxT("&Файл"));
}