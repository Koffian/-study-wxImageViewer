#include "MyApp.h"
#include "GrandFrame.h"
bool MyApp::OnInit() {
	GrandFrame* ImageViewer = new GrandFrame("Image viewer v 0.001");
	ImageViewer->Show(true);
	return true;
}