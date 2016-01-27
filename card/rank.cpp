#include "rank.h"

const long RankFrame::ID_BUTTON1 = wxNewId();
const long RankFrame::ID_BUTTON2 = wxNewId();
const long RankFrame::ID_TEXT1 = wxNewId();
const long RankFrame::ID_PANEL1 = wxNewId();

wxBEGIN_EVENT_TABLE(RankFrame,wxFrame)
    EVT_BUTTON(ID_BUTTON1,RankFrame::OnClick1)
    EVT_BUTTON(ID_BUTTON2,RankFrame::OnClick2)
wxEND_EVENT_TABLE()

RankFrame::RankFrame(wxWindow *parent,const wxString& title,const wxPoint& pos,const wxSize& size,long style)
          :wxFrame(parent,wxID_ANY,title,pos,size,style)
{
    panel1 = new wxPanel(this, ID_PANEL1, wxPoint(), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	panel1->SetBackgroundColour(wxColour(255,255,255));
	text1=new wxStaticText(panel1,ID_TEXT1,"",wxPoint());
	ok=new wxButton(panel1,ID_BUTTON1,"确定");
	reset=new wxButton(panel1,ID_BUTTON2,"清空");
}

void RankFrame::OnClick1(wxCommandEvent& event)
{
    this->Close();
}

void RankFrame::OnClick2(wxCommandEvent& event)
{
    ofstream fout("data.txt",ios_base::out);
    fout.close();
    text1->SetLabel("排名         玩家         得分");
}
