#include "main.h"
#include "game.h"

wxIMPLEMENT_APP(MyApp);

int w,h;

bool MyApp::OnInit()
{
    MyFrame *frame=new MyFrame("CardGame",wxPoint(0,0),wxDefaultSize);
    frame->Show(true);
    frame->Maximize(true);

    w=frame->WindowToClientSize(frame->GetSize()).GetWidth();
    h=frame->WindowToClientSize(frame->GetSize()).GetHeight();

    wxTextEntryDialog *load=new wxTextEntryDialog(frame,"用户名","Load","匿名",wxOK | wxCANCEL | wxCENTRE,wxPoint(w/2-200,h/2-150));
    load->SetMaxLength(14);
    if (load->ShowModal()==wxID_OK)
    {
        frame->setName(load->GetValue());
        if (!frame->getName())
            frame->setName("匿名");
    }
    else
        frame->Close();

    return true;
}
