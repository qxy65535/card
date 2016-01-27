#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
    #include <wx/wx.h>
    #include <vector>
    #include <cstdlib>
    #include <fstream>
    #include <algorithm>
    #include <iomanip>
    #include <sstream>
    #include "control.h"
    #include "player.h"
    #include "rank.h"

enum {
    ID_BITMAPBUTTON1=1,
    ID_BITMAPBUTTON2=2,
    ID_BITMAPBUTTON3=3,
    ID_BITMAPBUTTON4=4,
    ID_BITMAPBUTTON5=5,
    ID_BITMAPBUTTON6=6,
    ID_BITMAPBUTTON7=7,
    ID_BITMAPBUTTON8=8,
    ID_BITMAPBUTTON9=9,
    ID_BITMAPBUTTON10=10,
    ID_BITMAPBUTTON11=11,
    ID_BITMAPBUTTON12=12,
    ID_BITMAPBUTTON13=13,
    ID_BITMAPBUTTON14=14,
    ID_BITMAPBUTTON15=15,
    ID_BITMAPBUTTON16=16,
    ID_BITMAPBUTTON17=17,
    ID_BITMAPBUTTON18=18,
    ID_BITMAPBUTTON19=19,
    ID_BITMAPBUTTON20=20,
    ID_BITMAPBUTTON21=21,
    ID_BITMAPBUTTON22=22,
    ID_BITMAPBUTTON23=23,
    ID_BITMAPBUTTON24=24,
    ID_BITMAPBUTTON25=25,
    ID_BITMAPBUTTON26=26,
    ID_BITMAPBUTTON27=27,
    ID_BITMAPBUTTON28=28,
    ID_BITMAPBUTTON29=29,
    ID_BITMAPBUTTON30=30,
    ID_BITMAPBUTTON31=31,
    ID_BITMAPBUTTON32=32,
    ID_BITMAPBUTTON33=33,
    ID_BITMAPBUTTON34=34,
    ID_BTNOUT=35,
    ID_BTNPASS=36,
    ID_Start=37,
    ID_Rank=38
};


class MyFrame:public wxFrame
{
public:
    wxPanel* Panel1;
    wxBitmapButton* BmpButton;
    wxButton* out;
    wxButton* pass;
    wxStaticText* text1;
    std::vector<wxBitmapButton *> my;
    std::vector<wxBitmapButton *> opnt;
    inline void setName(wxString name){name_=name;}
    inline wxString getName(){return name_;}
    void calPoint(std::vector<int> card);
    MyFrame(const wxString& title,const wxPoint& pos,const wxSize& size);
    void showData();
    void writeData();
    ~MyFrame(){}
protected:
    static const long ID_PANEL1;
    static const long ID_BITMAPBUTTON;
    static const long ID_TEXT;
private:
    std::string name_;
    int score_;
    std::vector<int> myC;
    std::vector<int> opntC;
    Control *c;
    void OnStart(wxCommandEvent& event);
    void OnRank(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void myMove(int id);
    void OnBmpClick1(wxCommandEvent& event);
    void OnBmpClick2(wxCommandEvent& event);
    void OnBmpClick3(wxCommandEvent& event);
    void OnBmpClick4(wxCommandEvent& event);
    void OnBmpClick5(wxCommandEvent& event);
    void OnBmpClick6(wxCommandEvent& event);
    void OnBmpClick7(wxCommandEvent& event);
    void OnBmpClick8(wxCommandEvent& event);
    void OnBmpClick9(wxCommandEvent& event);
    void OnBmpClick10(wxCommandEvent& event);
    void OnBmpClick11(wxCommandEvent& event);
    void OnBmpClick12(wxCommandEvent& event);
    void OnBmpClick13(wxCommandEvent& event);
    void OnBmpClick14(wxCommandEvent& event);
    void OnBmpClick15(wxCommandEvent& event);
    void OnBmpClick16(wxCommandEvent& event);
    void OnBmpClick17(wxCommandEvent& event);
    void OnClickOut(wxCommandEvent& event);
    void OnClickPass(wxCommandEvent& event);
    void orderPlayer(Player n[],int m);
    wxDECLARE_EVENT_TABLE();
};



#endif // GAME_H_INCLUDED
