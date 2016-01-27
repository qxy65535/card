#include "game.h"


const long MyFrame::ID_PANEL1 = wxNewId();
const long MyFrame::ID_BITMAPBUTTON = wxNewId();
const long MyFrame::ID_TEXT = wxNewId();

extern int w;
extern int h;

wxBEGIN_EVENT_TABLE(MyFrame,wxFrame)
    EVT_MENU(ID_Start,MyFrame::OnStart)
    EVT_MENU(ID_Rank,MyFrame::OnRank)
    EVT_MENU(wxID_EXIT,MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT,MyFrame::OnAbout)
    EVT_BUTTON(ID_BITMAPBUTTON1,MyFrame::OnBmpClick1)
    EVT_BUTTON(ID_BITMAPBUTTON2,MyFrame::OnBmpClick2)
    EVT_BUTTON(ID_BITMAPBUTTON3,MyFrame::OnBmpClick3)
    EVT_BUTTON(ID_BITMAPBUTTON4,MyFrame::OnBmpClick4)
    EVT_BUTTON(ID_BITMAPBUTTON5,MyFrame::OnBmpClick5)
    EVT_BUTTON(ID_BITMAPBUTTON6,MyFrame::OnBmpClick6)
    EVT_BUTTON(ID_BITMAPBUTTON7,MyFrame::OnBmpClick7)
    EVT_BUTTON(ID_BITMAPBUTTON8,MyFrame::OnBmpClick8)
    EVT_BUTTON(ID_BITMAPBUTTON9,MyFrame::OnBmpClick9)
    EVT_BUTTON(ID_BITMAPBUTTON10,MyFrame::OnBmpClick10)
    EVT_BUTTON(ID_BITMAPBUTTON11,MyFrame::OnBmpClick11)
    EVT_BUTTON(ID_BITMAPBUTTON12,MyFrame::OnBmpClick12)
    EVT_BUTTON(ID_BITMAPBUTTON13,MyFrame::OnBmpClick13)
    EVT_BUTTON(ID_BITMAPBUTTON14,MyFrame::OnBmpClick14)
    EVT_BUTTON(ID_BITMAPBUTTON15,MyFrame::OnBmpClick15)
    EVT_BUTTON(ID_BITMAPBUTTON16,MyFrame::OnBmpClick16)
    EVT_BUTTON(ID_BITMAPBUTTON17,MyFrame::OnBmpClick17)
    EVT_BUTTON(ID_BTNOUT,MyFrame::OnClickOut)
    EVT_BUTTON(ID_BTNPASS,MyFrame::OnClickPass)
wxEND_EVENT_TABLE()


MyFrame::MyFrame(const wxString& title,const wxPoint& pos,const wxSize& size)
        :wxFrame(NULL,wxID_ANY,title,pos,size)
{

    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxColour(29,135,61));

    wxBitmap dsab=wxImage(_T("img\\55.bmp"));
    BmpButton=new wxBitmapButton(Panel1,wxNewId(),dsab,wxPoint(580,330),wxDefaultSize,wxBORDER_NONE);
    BmpButton->SetBitmapDisabled(dsab);
    BmpButton->Disable();

    int i;
    for (i=0;i<PILE;i++)
    {
        my.push_back(new wxBitmapButton(Panel1,i+1,dsab,wxPoint(580,330),wxDefaultSize,wxBORDER_NONE));
        my[i]->SetBitmapDisabled(dsab);
        my[i]->Disable();
        opnt.push_back(new wxBitmapButton(Panel1,i+18,dsab,wxPoint(580,330),wxDefaultSize,wxBORDER_NONE|wxBU_TOP));
        opnt[i]->SetBitmapDisabled(dsab);
        opnt[i]->Disable();
    }
    my.resize(PILE);
    opnt.resize(PILE);

    text1=new wxStaticText(Panel1,ID_TEXT,"\0",wxPoint(0,0),wxSize(200,28),wxALIGN_CENTRE_HORIZONTAL);
    text1->Hide();
    text1->SetFont(wxFont(28,wxFONTFAMILY_TELETYPE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL));
    text1->SetLabel("您不能这样出牌！");
    text1->SetBackgroundColour(wxColour(29,135,61));

    out=new wxButton(Panel1,35,"出牌",wxPoint(0,0),wxDefaultSize,0,wxDefaultValidator);
    out->Hide();
    pass=new wxButton(Panel1,36,"不出",wxPoint(0,0));
    pass->Hide();

    wxMenu *menuFile=new wxMenu;
    menuFile->Append(ID_Start,"&Start","Start a new game now!");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Rank,"&Rank","Look up the current rank");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp=new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar=new wxMenuBar;
    menuBar->Append(menuFile,"&File");
    menuBar->Append(menuHelp,"&Help");

    SetMenuBar(menuBar);
    CreateStatusBar();
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("这是一个规则类似斗地主的打牌游戏",
                  "About Card Game", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnRank(wxCommandEvent& event)
{
    showData();
}

void MyFrame::myMove(int id)
{
    int i;
    for (i=0;i<PILE;i++)
    {
        if (my[i]->GetId()==id)
        {
            if (my[i]->GetPosition().y==h-150)
                my[i]->Move(my[i]->GetPosition().x,h-170);
            else if (my[i]->GetPosition().y==h-170)
                my[i]->Move(my[i]->GetPosition().x,h-150);
            break;
        }
    }
}

void MyFrame::OnBmpClick1(wxCommandEvent& event)
{
    myMove(1);
}
void MyFrame::OnBmpClick2(wxCommandEvent& event)
{
    myMove(2);
}
void MyFrame::OnBmpClick3(wxCommandEvent& event)
{
    myMove(3);
}
void MyFrame::OnBmpClick4(wxCommandEvent& event)
{
    myMove(4);
}
void MyFrame::OnBmpClick5(wxCommandEvent& event)
{
    myMove(5);
}
void MyFrame::OnBmpClick6(wxCommandEvent& event)
{
    myMove(6);
}
void MyFrame::OnBmpClick7(wxCommandEvent& event)
{
    myMove(7);
}
void MyFrame::OnBmpClick8(wxCommandEvent& event)
{
    myMove(8);
}
void MyFrame::OnBmpClick9(wxCommandEvent& event)
{
    myMove(9);
}
void MyFrame::OnBmpClick10(wxCommandEvent& event)
{
    myMove(10);
}
void MyFrame::OnBmpClick11(wxCommandEvent& event)
{
    myMove(11);
}
void MyFrame::OnBmpClick12(wxCommandEvent& event)
{
    myMove(12);
}
void MyFrame::OnBmpClick13(wxCommandEvent& event)
{
    myMove(13);
}
void MyFrame::OnBmpClick14(wxCommandEvent& event)
{
    myMove(14);
}
void MyFrame::OnBmpClick15(wxCommandEvent& event)
{
    myMove(15);
}
void MyFrame::OnBmpClick16(wxCommandEvent& event)
{
    myMove(16);
}
void MyFrame::OnBmpClick17(wxCommandEvent& event)
{
    myMove(17);
}

void MyFrame::OnStart(wxCommandEvent& event)
{
    c=new Control;

    text1->SetPosition(wxPoint(w/2-112,h/2+70));
    text1->Hide();
    BmpButton->Show();


    c->washCard(my,myC,opnt,opntC);
    c->sandCard(my,opnt,BmpButton);

    srand(time(NULL));
    if (rand()%2)
    {
        wxMessageBox("您获得先手！",
                     "Card Game", wxOK | wxICON_INFORMATION );
        c->setFirst(true);
        out->SetPosition(wxPoint(w/2-100,h-210));
        pass->SetPosition(wxPoint(w/2+40,h-210));
        out->Show();
        pass->Show();
        pass->Disable();
    }
    else
    {
        wxMessageBox("电脑获得先手！",
                     "Card Game", wxOK | wxICON_INFORMATION );
        out->Hide();
        pass->Hide();
        c->setFirst(false);
        c->getOpntC(opntC);

        int j,cnt,x;

        for(j=0,cnt=1;j<opntC.size()-1;j++)
        {
            if (opntC[j]!=opntC[j+1])
                break;
            else
                cnt++;
        }

        for (j=0;j<cnt;j++)
        {
            x=w/2+19*cnt/2;
            opnt[j]->Move(wxPoint(x-19*j,170));
            opnt[j]->Enable();
            opntC[j]=0;
        }
        if (cnt<4)
            c->setType(cnt);
        else
            c->setType(BOMB);
        c->setOpntPos(0,cnt);
        c->orderOpnt(opnt,opntC);

        out->SetPosition(wxPoint(w/2-100,h-210));
        pass->SetPosition(wxPoint(w/2+40,h-210));
        out->Show();
        pass->Enable();
        pass->Show();
    }
}



void MyFrame::OnClickOut(wxCommandEvent& event)
{
    int i,x;
    bool over=true;
    std::vector<int> outCard1;//记录牌型
    std::vector<int> outCard2;//记录位置
    std::vector<int> opntPos;

    for (i=0;i<my.size();i++)
    {
        if (my[i]->GetPosition().y==h-170)
        {
            outCard1.push_back(myC[i]);
            outCard2.push_back(i);
        }
    }
    sort(outCard1.begin(),outCard1.end());
    outCard1.resize(outCard1.size());
    outCard2.resize(outCard2.size());

    for (i=0;i<my.size();i++)
    {
        if (my[i]->GetPosition().y==h-350)
        {
            my[i]->Disable();
            my[i]->Move(wxPoint(20,h/2-60));
        }
    }

    if (c->check(outCard1)&&c->checkType(outCard1))
    {
        c->setType();
        text1->Hide();
        out->Hide();
        pass->Hide();
        x=w/2-19*outCard2.size()/2;
        for (i=0;i<outCard2.size();i++)
        {
            my[outCard2[i]]->Move(wxPoint(x+19*i,h-350));
            myC[outCard2[i]]=0;
        }

        c->orderMy(my,myC);

        for (i=0,over=true;i<myC.size();i++)
        {
            if (myC[i])
            {
                over=false;
                break;
            }
        }
        if (over)
        {
            calPoint(opntC);
            writeData();
            wxString str;
            str<<score_;
            wxMessageBox("你赢了！得分："+str,"You win！", wxOK | wxICON_INFORMATION );
            for (i=0;i<opntC.size();i++)
            {
                if (opntC[i])
                    opnt[i]->Enable();
            }
            delete c;
            return;
        }

        for (i=0;i<opnt.size();i++)
        {
            if (opnt[i]->GetPosition().y==170)
                opnt[i]->Move(wxPoint(20,h/2-60));
        }
        opntPos.clear();
        if (c->opntOut(opntC,opntPos))
        {
            x=w/2+19*opntPos.size()/2;
            for (i=0;i<opntPos.size();i++)
            {
                opnt[opntPos[i]]->Move(wxPoint(x-19*i,170));
                opnt[opntPos[i]]->Enable();
                opnt[opntPos[i]]->Lower();
                opntC[opntPos[i]]=0;
            }

            c->orderOpnt(opnt,opntC);
        }

        for (i=0,over=true;i<opntC.size();i++)
        {
            if (opntC[i])
            {
                over=false;
                break;
            }
        }
        if (over)
        {
            calPoint(myC);
            score_=-score_;
            writeData();
            wxString str;
            str<<score_;
            wxMessageBox("你输了！得分："+str,"You lose！", wxOK | wxICON_INFORMATION );
            delete c;
            return ;
        }

        out->Show();
        pass->Enable();
        pass->Show();
        if (c->getFirst())
            pass->Disable();

    }
    else
        text1->Show();


}

void MyFrame::OnClickPass(wxCommandEvent& event)
{
    text1->Hide();
    out->Hide();
    pass->Hide();
    int i,j,cnt,x,k;
    bool over=true;

    for (i=0;i<opnt.size();i++)
    {
        if (opnt[i]->GetPosition().y==170)
            opnt[i]->Move(wxPoint(20,h/2-60));
        if (my[i]->GetPosition().y==h-350)
        {
            my[i]->Disable();
            my[i]->Move(wxPoint(20,h/2-60));
        }
    }

    for (i=0;i<opntC.size();i++)
    {
        if (opntC[i]>0)
        {
            k=i;
            for(j=i,cnt=1;j<opntC.size()-1;j++)
            {
                if (opntC[j]!=opntC[j+1])
                    break;
                else
                    cnt++;
            }
            c->setOpntPos(i,cnt);
            for (j=0;j<cnt;j++,k++)
            {
                x=w/2+19*cnt/2;
                opnt[k]->Move(wxPoint(x-19*j,170));
                opnt[k]->Enable();
                opntC[k]=0;
            }
            if (cnt<4)
                c->setType(cnt);
            else
                c->setType(BOMB);

            break;
        }
    }

    for (i=0;i<opntC.size();i++)
    {
        if (opntC[i]){
            over=false;
            break;
        }
    }
    if (over)
    {
        calPoint(myC);
        score_=-score_;
        writeData();
        wxString str;
        str<<score_;
        wxMessageBox("你输了！得分："+str,"You lose！", wxOK | wxICON_INFORMATION );
        delete c;
        return ;
    }

    c->orderOpnt(opnt,opntC);

    out->Show();
    pass->Show();

}

void MyFrame::calPoint(std::vector<int> card)
{
    int i;
    score_=0;
    for (i=0;i<card.size();i++)
        score_+=card[i];
}

void MyFrame::writeData()
{
    Player player[6];
    ifstream fin;
    ofstream fout;
    int i,cnt=0;
    std::string name;
    int score;
    fin.open("data.txt",ios_base::in|ios_base::app);
    if (fin.is_open())
    {
        fin>>cnt;
        for (i=0;i<cnt;i++)
        {
            fin>>name;
            fin>>score;
            player[i].setName(name);
            player[i].setScore(score);
        }
        player[i].setName(name_);
        player[i].setScore(score_);
        cnt++;
        orderPlayer(player,cnt);
        fin.close();
        fout.open("data.txt",ios_base::out);
        if (cnt>5)
            cnt=5;
        fout<<cnt<<endl;
        for(i=0;i<cnt;i++)
            fout<<left<<setw(15)<<player[i].getName()<<player[i].getScore()<<endl;
        fout.close();
    }
    else
        wxMessageBox("无法读取数据文件","Error", wxOK | wxICON_HAND );
}

void MyFrame::showData()
{
    int cnt,i=1;
    std::string str="排名         玩家         得分\n";
    char ch;
    ifstream fin("data.txt",ios_base::in|ios_base::app);
    RankFrame *myRank=new RankFrame(this,"Rank",wxPoint(w/2-250,h/2-165),wxSize(500,330),
                                    wxMINIMIZE_BOX | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN);
    if (fin.is_open())
    {
        fin>>cnt;
        while(fin.get(ch))
        {
            if (ch=='\n'&&i<cnt+1)
            {
                str.push_back(ch);
                str+=" ";
                str.push_back((i++)+'0');
                str+="         ";
            }
            else
                str.push_back(ch);
        }

        myRank->text1->SetFont(wxFont(15,70, 90, 90, false, "黑体"));
        myRank->text1->SetPosition(wxPoint(40,20));
        myRank->text1->SetLabel(str);

        myRank->ok->SetPosition(wxPoint(100,230));
        myRank->reset->SetPosition(wxPoint(270,230));
        myRank->Show(true);
    }
    else
        wxMessageBox("无法读取数据文件","Error", wxOK | wxICON_HAND );
}

void MyFrame::orderPlayer(Player n[],int m)
{
    int i,j,max;
    Player tmp;
    for (i=0;i<m;i++)
    {
        max=n[i].getScore();
        for (j=i+1;j<m;j++)
        {
            if (n[j].getScore()>max)
            {
                max=n[j].getScore();
                tmp=n[i];
                n[i]=n[j];
                n[j]=tmp;
            }
        }
    }
}
