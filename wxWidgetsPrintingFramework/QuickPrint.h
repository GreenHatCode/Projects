#pragma once
#include "wx/print.h"
#include "wx/printdlg.h"
#include "wx/wx.h"


class QuickPrint :
    public wxPrintout
{
public:
    /**
      * @param page_amount    number of pages we want to print. Here it's static because it's just a test, but in
      *                       real code you will often want to calculate dynamically once you know the size of the
      *                       printable area from page setup
      * @param title          name of the print job / of the printed document
      * @param units_per_cem  we'll use this to determine the coordinate system; it describes the number of units
      *                       per centimeter (i.e. how fine the coordinate system is)
      */
    QuickPrint(const QuickPrint& obj);
    QuickPrint(int page_amount, wxString title, float units_per_cm, void(*print_fun)(wxDC& dc, int pageNum, wxSize pageSize));
    bool performPageSetup(const bool showPageSetupDialog);
    void OnBeginPrinting();
    wxPrintData getPrintData();
    bool OnBeginDocument(int startPage, int endPage);
    void GetPageInfo(int* minPage, int* maxPage, int* pageSelFrom, int* pageSelTo);
    bool HasPage(int pageNum);
    bool OnPrintPage(int pageNum);


private:
    wxPageSetupData m_page_setup;
    wxPaperSize m_paper_type; // the type of paper: latter, A4, etc
    int m_orient; // horizontal or vertical
    int m_page_amount;
    int m_margin_left, m_margin_right, m_margin_top, m_margin_bottom; // margins in millimeters
    float m_units_per_cm; //how fine the coordinate system is
    int m_coord_system_width, m_coord_system_height;
    void(*m_print_function)(wxDC& dc, int pageNum, wxSize pageSize);
};

