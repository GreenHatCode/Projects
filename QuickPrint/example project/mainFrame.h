#pragma once
#include "wx\wx.h"
#include "QuickPrint.h"
#include "PrintExample.h"

class mainFrame :
    public wxFrame
{
public:
    mainFrame(const wxString& title);
private:
    PrintExample* printExample; // an example of an instance whose data we are going to print
    void OnPrintDoc(wxCommandEvent& evt); // function of the print button menu handler
    

    DECLARE_EVENT_TABLE();
};

