#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED
    #include <string>
    #include <wx/wx.h>
    #include <fstream>
using namespace std;

class RankFrame:public wxFrame
{
private:
    void OnClick1(wxCommandEvent& event);
    void OnClick2(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
protected:
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_TEXT1;
    static const long ID_PANEL1;
public:
    wxButton *ok;
    wxButton *reset;
    wxStaticText *text1;
    wxPanel *panel1;
    RankFrame(wxWindow *parent,const wxString& title,const wxPoint& pos,const wxSize& size,long style);
};
#endif // LOAD_H_INCLUDED
