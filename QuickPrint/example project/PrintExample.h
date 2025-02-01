#pragma once
#include "wx/wx.h"
#include <functional>

/*
    This class is an example of a data 
    structure whose data we are going to print.
    As you can see, I have defined a method
    print, which prints some data to the wxDC of the printer.
    You can define any class or structure and define any
    method in it, but use the same function signature
    (otherwise you won't be able to use it for printing).
    In it, draw all the data you need to output.

    See mainFrame.cpp for how to use this method in print
*/

class PrintExample
{
public:
	void Print(wxDC& dc, int pageNum, wxSize pg_size)
	{
        dc.Clear();

        dc.SetPen(wxPen(wxColour(0, 0, 0), 3));
        dc.SetBrush(*wxTRANSPARENT_BRUSH);

        // draw a rectangle to show its bounds.
        dc.DrawRectangle(0, 0, pg_size.x, pg_size.y);

        // draw wxWidgets logo
        dc.SetBrush(*wxRED_BRUSH);
        dc.DrawRectangle((pg_size.x / 2) - 45 - 38, (pg_size.y / 2), 76, 76);
        dc.SetBrush(*wxBLUE_BRUSH);
        dc.DrawRectangle((pg_size.x / 2) - 38, (pg_size.y / 2) - 45, 76, 76);
        dc.SetBrush(wxBrush(wxColor(255, 244, 0)));
        dc.DrawRectangle((pg_size.x / 2) + 45 - 38, (pg_size.y / 2) - 10, 76, 76);

        // draw page number label
        wxString label(wxT("This is page #"));
        label << pageNum;
        dc.SetTextBackground(wxColour(255, 255, 0));
        dc.SetTextForeground(wxColour(0, 0, 0));
        dc.DrawText(label, 0 + pg_size.x / 5, 0 + pg_size.y - 50);
	}
};

