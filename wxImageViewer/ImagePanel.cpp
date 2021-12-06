#include "ImagePanel.h"

ImagePanel::ImagePanel(wxPanel* parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	m_parent = parent;
	vbox = new wxBoxSizer(wxVERTICAL);

	m_sw = new wxScrolledWindow(this);
		sb = new wxStaticBitmap(m_sw, wxID_ANY, bmp);

	vbox->Add(m_sw, 1, wxEXPAND | wxALL);
	this->SetSizer(vbox);
	this->Centre();
}

bool ImagePanel::initImage(const wxString filename) {
	wxBitmap tmp = wxBitmap(filename, wxBITMAP_TYPE_ANY);
	if (tmp.IsOk() == false) //"not " is not working
		return false;
	bmp = tmp;

	m_sw->Scroll(0, 0);
	sb->SetBitmap(bmp);
	basicImageWidth = bmp.GetWidth();
	basicImageHeight = bmp.GetHeight();

	m_sw->SetScrollbars(scrollStep, scrollStep, 
		basicImageWidth / scrollStep,
		basicImageHeight / scrollStep);

	return true;
}

void ImagePanel::updateImage(const wxString filename) {

	bmp = wxBitmap(filename, wxBITMAP_TYPE_ANY);

	m_sw->Scroll(0, 0);
	sb->SetBitmap(bmp);
	int w = bmp.GetWidth();
	int h = bmp.GetHeight();

	m_sw->SetScrollbars(scrollStep, scrollStep,
		w/ scrollStep,
		h/ scrollStep);

	//m_sw->Scroll(50, 10); // Немного прокрутить полоски
}

void ImagePanel::updateImage() {

	m_sw->Scroll(0, 0);
	sb->SetBitmap(bmp);
	int w = bmp.GetWidth();
	int h = bmp.GetHeight();

	m_sw->SetScrollbars(scrollStep, scrollStep,
		w / scrollStep,
		h / scrollStep);

	//m_sw->Scroll(50, 10); // Немного прокрутить полоски
}

void ImagePanel::rotateImageLeft() {
	wxImage img = bmp.ConvertToImage();
	img = img.Rotate90(false);
	bmp = wxBitmap(img);
	updateImage();
}
void ImagePanel::rotateImageRight() {
	wxImage img = bmp.ConvertToImage();
	img = img.Rotate90(true);
	bmp = wxBitmap(img);
	updateImage();
}

void ImagePanel::scaleImage(int scale) {
	wxImage img = bmp.ConvertToImage();
	img.Rescale(basicImageWidth+scale, basicImageHeight+scale);
	bmp = wxBitmap(img);
	updateImage();
}