#include "mainFrame.h"

BEGIN_EVENT_TABLE(mainFrame, wxFrame)
EVT_MENU(wxID_PRINT, mainFrame::OnPrintDoc)
END_EVENT_TABLE()

mainFrame::mainFrame(const wxString& title)
	:wxFrame(NULL, wxID_ANY, title)
{
	// creating menu for window
	wxMenu* file_menu = new wxMenu;
	file_menu->Append(wxID_PRINT);

	wxMenuBar* menu_bar = new wxMenuBar;
	menu_bar->Append(file_menu, wxT("&File"));
	SetMenuBar(menu_bar);

	printExample = new PrintExample(); // creating a sample instance

}

void mainFrame::OnPrintDoc(wxCommandEvent& evt)
{
	// here we create a pointer to a method, 
	// which we will use to print data from the instance. 
	// In this case, the name of the instance is printExample.
	// A function can be: instance function, class member function, lambda, object function.
	// But you should always use the same signature as in the example.
	std::function<void(wxDC& dc, int pageNum, wxSize dc_size)> print_method = 
		std::bind(&PrintExample::Print, printExample, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

	QuickPrint* preview_print = new QuickPrint(1, wxT("Print preview"), 30, print_method); // Now all you need to do is pass a pointer to the print function to the class constructor

	// preforming page setup
	if (!preview_print->performPageSetup(true))
	{
		// the user cancelled
		return;
	}

	QuickPrint* finish_print = new QuickPrint(*preview_print); // making a copy of the object, the preview window will use it for printing

	// invoking preview window
	wxPrintData print_data = preview_print->getPrintData();
	wxPrintPreview* preview = new wxPrintPreview(preview_print, finish_print, &print_data);
	wxPreviewFrame* frame = new wxPreviewFrame(preview, this,
		"Print Preview",
		wxPoint(100, 100),
		wxSize(600, 650));
	frame->Centre(wxBOTH);
	frame->Initialize();
	frame->Show(true);
}


