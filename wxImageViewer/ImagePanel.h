#pragma once
#include "wx/wx.h"
#include "ImagePropsPanel.h"
class ImagePanel : public wxPanel
{
private:
	int basicImageWidth = 0;
	int basicImageHeight = 0;
	int scrollStep = 10;
public:
	ImagePanel(wxPanel* parent);
	wxPanel* m_parent;
	wxBoxSizer* vbox;
	wxScrolledWindow* m_sw;
	ImagePropsPanel* m_propsPanel;
	wxBitmap bmp;
	wxStaticBitmap* sb;

	bool initImage(const wxString filename);
	void updateImage(const wxString filename);
	void updateImage();
	void rotateImageLeft();
	void rotateImageRight();
	void scaleImage(int scale);

};

