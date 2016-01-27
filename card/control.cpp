#include "control.h"

extern int w;
extern int h;

void Control::washCard(std::vector<wxBitmapButton*>& my,std::vector<int> &myC,std::vector<wxBitmapButton*>& opnt,std::vector<int> &opntC)
{
    std::vector<int> card;
    int i,m;
    wxString str;
    srand(time(NULL));

    for (i=0;i<TOTAL;i++)
        card.push_back(i+1);

    card.resize(TOTAL);

    for (i=0;i<TOTAL;i++)
    {
        m=rand()%54+1;
        std::swap(card[i],card[m-1]);
    }

    myC.clear();
    opntC.clear();

    for (i=0;i<PILE;i++)
    {
        str<<card[i];
        my[i]->SetBitmap(wxImage(_T("img\\"+str+".bmp")));
        if (card[i]<=13)
            myC.push_back(card[i]);
        else if (card[i]<=26)
            myC.push_back(card[i]-13);
        else if (card[i]<=39)
            myC.push_back(card[i]-26);
        else
            myC.push_back(card[i]-39);
        str.Clear();

        str<<card[54-i-1];
        opnt[i]->SetBitmap(wxImage(_T("img\\"+str+".bmp")));
        if (card[54-i-1]<=13)
            opntC.push_back(card[54-i-1]);
        else if (card[54-i-1]<=26)
            opntC.push_back(card[54-i-1]-13);
        else if (card[54-i-1]<=39)
            opntC.push_back(card[54-i-1]-26);
        else
            opntC.push_back(card[54-i-1]-39);
        str.Clear();
    }

    myC.resize(PILE);
    opntC.resize(PILE);

    sortMy(my,myC);
    sortOpnt(opnt,opntC);

}

void Control::sandCard(std::vector<wxBitmapButton*>& my,std::vector<wxBitmapButton*>& opnt,wxBitmapButton* BmpButton)
{
    int i,x1,x2;
    x1=w/2-19*my.size()/2;
    x2=w/2+19*my.size()/2;
    for (i=0;i<PILE;i++)
    {
        my[i]->Move(wxPoint(x1+19*i,h-150));
        my[i]->Enable();
        my[i]->Raise();
        opnt[i]->Move(wxPoint(x2-19*i,30));
        opnt[i]->Disable();
        opnt[i]->Lower();
    }
    BmpButton->Move(wxPoint(20,h/2-60));
}

void Control::sortMy(std::vector<wxBitmapButton*>& card,std::vector<int> &n)
{
    int i,j,max_,pos;
    for(i=0;i<PILE;i++)
    {
        pos=i;
        max_=n[i];
        for(j=i+1;j<PILE;j++)
        {
            if (n[j]>max_)
            {
                pos=j;
                max_=n[j];
            }
        }
        if (pos!=i)
        {
            std::swap(n[i],n[pos]);
            std::swap(card[i],card[pos]);
        }
    }
}

void Control::sortOpnt(std::vector<wxBitmapButton*>& card,std::vector<int> &n)
{
    int i,j,min_,pos;
    for(i=0;i<PILE;i++)
    {
        pos=i;
        min_=n[i];
        for(j=i+1;j<PILE;j++)
        {
            if (n[j]<min_)
            {
                pos=j;
                min_=n[j];
            }
        }
        if (pos!=i)
        {
            std::swap(n[i],n[pos]);
            std::swap(card[i],card[pos]);
        }
    }
}

bool Control::check(std::vector<int> &n)
{
    getOutCard(n);

    bool result=false;
    switch (n.size())
    {
    case 1:
        result=check1();
        break;
    case 2:
        result=check2();
        break;
    case 3:
        result=check3();
        break;
    case 4:
        result=check4();
        break;
    case 5:
        result=check5();
        break;
    case 6:
        result=check6();
        break;
    case 7:
    case 11:
    case 13:
        result=check7();
        break;
    case 8:
        result=check8();
        break;
    case 9:
        result=check9();
        break;
    case 10:
        result=check10();
        break;
    case 12:
        result=check12();
        break;
    case 14:
        result=check14();
        break;
    case 15:
        result=check15();
        break;
    case 16:
        result=check16();
        break;
    }
    return result;
}

void Control::orderMy(std::vector<wxBitmapButton*>& card,std::vector<int> &n)
{
    int i,x,m,cnt=0;
    for (i=0;i<card.size();i++)
        if (n[i])
            cnt++;

    x=w/2-19*cnt/2;

    for (i=0,m=0;i<card.size();i++)
        if (card[i]->GetPosition().y>h-350)
        {
            card[i]->Move(wxPoint(x+19*m++,h-150));
            card[i]->Raise();
        }
}

void Control::orderOpnt(std::vector<wxBitmapButton*>& card,std::vector<int> &n)
{
    int i,x,m,cnt=0;
    for (i=0;i<card.size();i++)
        if (n[i])
            cnt++;

    x=w/2+19*cnt/2;

    for (i=0,m=0;i<card.size();i++)
        if (card[i]->GetPosition().y==30)
            card[i]->Move(wxPoint(x-19*m++,30));
}

void Control::getOutCard(std::vector<int> outCard1)
{
    myOut.assign(outCard1.begin(),outCard1.end());
}

void Control::setOpntPos(int i,int cnt)
{
    opntPos.clear();
    int n;
    for(n=0;n<cnt;n++)
        opntPos.push_back(i++);
}

bool Control::checkSequence()
{
    int i;
    for(i=0;i<myOut.size()-1;i++)
        if (myOut[i+1]>12||myOut[i]!=myOut[i+1]-1)
            return false;
    return true;
}

bool Control::checkSequenceOfPairs2(vector<int> tmp)
{
    int i;
    bool check=true;
    for (i=0;i<tmp.size()-1;i++)
    {
        if (i%2==0&&tmp[i]!=tmp[i+1])
        {
            check=false;
            break;
        }
    }

    return check;
}

bool Control::checkSequenceOfPairs()
{
    int i;
    bool check=true;
    vector<int>::iterator iter=myOut.end()-1;
    for (i=0;i<myOut.size()-1;i++)
    {
        if (i%2==0&&myOut[i]!=myOut[i+1])
        {
            check=false;
            break;
        }
        else if (i%2&&myOut[i]!=myOut[i+1]-1)
        {
            check=false;
            break;
        }
    }
    if (*iter>12)
        check=false;
    return check;
}

bool Control::checkSequenceOfTriplets(vector<int> tmp)
{
    int i;
    bool check=true;
    vector<int>::iterator iter=tmp.end()-1;
    myThree.clear();
    for (i=0;i<tmp.size()-1;i++)
    {
        if (i%3==0||i%3==1)
        {
            if (tmp[i]!=tmp[i+1])
            {
                check=false;
                break;
            }
        }
        else if (i%3==2&&tmp[i]!=tmp[i+1]-1)
        {
            check=false;
            break;
        }
        if (i%3==2)
            myThree.push_back(tmp[i]);
    }
    if (check)
        myThree.push_back(*iter);
    if (*iter>12)
        check=false;
    return check;
}

bool Control::check2()
{
    if (myOut[0]==myOut[1])
    {
        typeMy=PAIR;
        return true;
    }
    else if (myOut[0]==14&&myOut[1]==15)//王炸
    {
        typeMy=ROCKET;
        return true;
    }
    else
        return false;
}

bool Control::check3()
{
    if (myOut[0]==myOut[1]&&myOut[1]==myOut[2])
    {
        typeMy=TRIPLE;
        return true;
    }
    else
        return false;
}

bool Control::check4()
{
    if (myOut[0]==myOut[1]&&myOut[1]==myOut[2]&&myOut[2]!=myOut[3])//三带一，如3334
    {
        myThree.clear();
        myThree.push_back(myOut[0]);
        typeMy=TRIPLE_WITH_ONE;
        return true;
    }
    else if (myOut[1]==myOut[2]&&myOut[2]==myOut[3]&&myOut[3]!=myOut[0])//三带一，如3444
    {
        myThree.clear();
        myThree.push_back(myOut[1]);
        typeMy=TRIPLE_WITH_ONE;
        return true;
    }
    else if (myOut[0]==myOut[1]&&myOut[1]==myOut[2]&&myOut[2]==myOut[3])//炸弹
    {
        typeMy=BOMB;
        return true;
    }
    else return false;
}

bool Control::check5()
{
    if (myOut[0]==myOut[1]&&myOut[1]==myOut[2]&&myOut[2]!=myOut[3]&&myOut[3]==myOut[4])//三带二，如33344
    {
        myThree.clear();
        myThree.push_back(myOut[0]);
        typeMy=TRIPLE_WITH_TWO;
        return true;
    }
    else if (myOut[0]==myOut[1]&&myOut[1]!=myOut[2]&&myOut[2]==myOut[3]&&myOut[3]==myOut[4])//三带二，如33444
    {
        myThree.clear();
        myThree.push_back(myOut[2]);
        typeMy=TRIPLE_WITH_TWO;
        return true;
    }
    else if (checkSequence())    //单顺 34567
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }

    return false;
}

bool Control::check6()
{
    if (checkSequenceOfPairs())
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }
    if (checkSequenceOfTriplets(myOut))
    {
        typeMy=SEQUENCE_QUENCE_OF_TRIPLETS;
        return true;
    }
    if (checkSequence())
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }
    return false;
}

bool Control::check7()
{
    if (checkSequence())
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }
    return false;
}

bool Control::check8()
{
    int i;
    vector<int> tmp;

    if (checkSequenceOfPairs())    //连对33445566
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }

    for (i=0;i<3;i++)
    {
        tmp.assign(myOut.begin()+i,myOut.begin()+i+6);  //飞机带翅膀33344456
        if (checkSequenceOfTriplets(tmp))
        {
            typeMy=SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE;
            return true;
        }
    }

    if (checkSequence())   //单顺345678910
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }

    return false;
}

bool Control::check9()
{
    if (checkSequenceOfTriplets(myOut))    //飞机 333444555
    {
        typeMy=SEQUENCE_QUENCE_OF_TRIPLETS;
        return true;
    }

    if (checkSequence())     //单顺345678910J
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }

    return false;
}

bool Control::check10()
{
    vector<int> tmp;
    int i;

    if (checkSequenceOfPairs())    //连对3344556677
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }

    for(i=0;i<3;i++)             //飞机带翅膀3334445566
    {
        tmp.assign(myOut.begin()+2*i,myOut.begin()+2*i+6);
        if (checkSequenceOfTriplets(tmp))
        {
            tmp.assign(myOut.begin(),myOut.end());
            tmp.erase(tmp.begin()+2*i,tmp.begin()+2*i+6);
            if (checkSequenceOfPairs2(tmp))
            {
                typeMy=SEQUENCE_QUENCE_OF_TRIPLETS_WITH_TWO;
                return true;
            }
        }
    }
    if (checkSequence())       //单顺345678910JQ
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }
    return false;
}

bool Control::check12()
{
    int i;
    vector<int> tmp;

    if (checkSequence())
    {
        typeMy=SEQUENCE_QUENCE;
        return true;
    }

    if (checkSequenceOfPairs())
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }

    if (checkSequenceOfTriplets(myOut))
    {
        typeMy=SEQUENCE_QUENCE_OF_TRIPLETS;
        return true;
    }

    for (i=0;i<3;i++)
    {
        tmp.assign(myOut.begin()+i,myOut.begin()+i+9);  //飞机带翅膀333444555678
        if (checkSequenceOfTriplets(tmp))
        {
            typeMy=SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE;
            return true;
        }
    }

    return false;
}

bool Control::check14()
{
    if (checkSequenceOfPairs())    //连对33445566778899
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }
    return false;
}

bool Control::check15()
{
    vector<int> tmp;
    int i;

    if (checkSequenceOfTriplets(myOut))
    {
        typeMy=SEQUENCE_QUENCE_OF_TRIPLETS;
        return true;
    }

    for(i=0;i<4;i++)            //飞机带翅膀333444555667788
    {
        tmp.assign(myOut.begin()+2*i,myOut.begin()+2*i+9);
        if (checkSequenceOfTriplets(tmp))
        {
            tmp.assign(myOut.begin(),myOut.end());
            tmp.erase(tmp.begin()+2*i,tmp.begin()+2*i+9);
            if (checkSequenceOfPairs2(tmp))
            {
                typeMy=SEQUENCE_QUENCE_OF_TRIPLETS_WITH_TWO;
                return true;
            }
        }
    }
    return false;
}

bool Control::check16()
{
    int i;
    vector<int> tmp;

    if (checkSequenceOfPairs())    //连对334455667788991010
    {
        typeMy=SEQUENCE_QUENCE_OF_PAIRS;
        return true;
    }

    for (i=0;i<4;i++)
    {
        tmp.assign(myOut.begin()+i,myOut.begin()+i+9);  //飞机带翅膀333444555678
        if (checkSequenceOfTriplets(tmp))
        {
            typeMy=SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE;
            return true;
        }
    }

    return false;
}

bool Control::checkType(std::vector<int> &n)
{
    if (first)
        return true;

    if (type==ROCKET)
        return false;
    else if (typeMy!=type&&(typeMy==BOMB||typeMy==ROCKET))
    {
        type=typeMy;
        return true;
    }
    else if (typeMy!=type)
        return false;

    getOutCard(n);

    bool result=false;
    switch(type)
    {
    case SINGLE:
    case PAIR:
    case TRIPLE:
    case SEQUENCE_QUENCE:
    case SEQUENCE_QUENCE_OF_PAIRS:
    case BOMB:
        result=checkType1();
        break;
    case TRIPLE_WITH_ONE:
    case TRIPLE_WITH_TWO:
    case SEQUENCE_QUENCE_OF_TRIPLETS:
    case SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE:
    case SEQUENCE_QUENCE_OF_TRIPLETS_WITH_TWO:
        result=checkType2();
        break;
    case ROCKET:
        result=false;
        break;
    }
    return result;
}

bool Control::checkType1()
{
    vector<int>::iterator iter1=myOut.end()-1,iter2=opntPos.end()-1,iter3=opntC.begin();
    if (myOut.size()!=opntPos.size())
        return false;
    if (*iter1>*(iter3+*iter2))
        return true;
    else return false;
}

bool Control::checkType2()
{
    vector<int>::iterator iter1=myThree.end()-1,iter2=opntThree.end()-1;
    if (*iter1>*iter2)
        return true;
    else return false;
}

bool Control::opntOut(vector<int> opntC,vector<int> &opntPos)
{
    this->opntC.clear();
    this->opntC.assign(opntC.begin(),opntC.end());
    this->opntPos.clear();

    int i,cnt;
    for (i=0,cnt=0;i<opntC.size();i++)
        if (opntC[i]!=0)
            cnt++;

    if (cnt<myOut.size()&&!findBomb())
    {
        first=true;
        return false;
    }
    else if (cnt<myOut.size()&&findBomb())
    {
        first=false;
        opntPos.assign(this->opntPos.begin(),this->opntPos.end());
        return true;
    }

    this->opntPos.clear();
    bool found=false;

    switch(type)
    {
    case SINGLE:
        found=opntFind1();
        break;
    case PAIR:
        found=opntFind2(0);
        break;
    case TRIPLE:
        found=opntFind3(0);
        break;
    case TRIPLE_WITH_ONE:
        found=opntFind4();
        break;
    case TRIPLE_WITH_TWO:
        found=opntFind5();
        break;
    case SEQUENCE_QUENCE:
        found=opntFind6();
        break;
    case SEQUENCE_QUENCE_OF_PAIRS:
        found=opntFind7();
        break;
    case SEQUENCE_QUENCE_OF_TRIPLETS:
        found=opntFind8();
        break;
    case SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE:
        found=opntFind9();
        break;
    case SEQUENCE_QUENCE_OF_TRIPLETS_WITH_TWO:
        found=opntFind10();
        break;
    case BOMB:
        found=opntFind11();
        break;
    case ROCKET:
        found=false;
        break;
    }

    if (found)
    {
        first=false;
        opntPos.assign(this->opntPos.begin(),this->opntPos.end());
    }
    else
        first=true;
    return found;
}

bool Control::findBomb()
{
    int i;
    opntPos.clear();
    for (i=0;i<opntC.size()-3;i++)
    {
        if (opntC[i]==opntC[i+1]&&opntC[i]==opntC[i+2]&&opntC[i]==opntC[i+3]&&opntC[i]!=0)
        {
            opntPos.push_back(i);
            opntPos.push_back(i+1);
            opntPos.push_back(i+2);
            opntPos.push_back(i+3);
            type=BOMB;
            return true;
        }
    }

    if (opntC[15]==14&&opntC[16]==15){
        opntPos.push_back(15);
        opntPos.push_back(16);
        type=ROCKET;
        return true;
    }

    return false;
}
bool Control::opntFind1()
{
    int i;
    for (i=0;i<opntC.size();i++)
        if (opntC[i]>myOut[0])
        {
            opntPos.push_back(i);
            return true;
        }

    if (findBomb())
        return true;

    return false;
}

bool Control::opntFind2(int n)
{
    int i;
    for (i=n;i<opntC.size()-1;i++)
        if (opntC[i]>myOut[0]&&opntC[i+1]==opntC[i])
        {
            opntPos.push_back(i);
            opntPos.push_back(i+1);
            return true;
        }

    if (findBomb())
        return true;

    return false;
}

bool Control::opntFind3(int n)
{
    int i;
    for (i=n;i<opntC.size()-2;i++)
        if (opntC[i]>myOut[0]&&opntC[i+1]==opntC[i]&&opntC[i+1]==opntC[i+2])
        {
            opntPos.push_back(i);
            opntPos.push_back(i+1);
            opntPos.push_back(i+2);
            opntThree.push_back(opntC[i]);
            return true;
        }

    if (findBomb())
        return true;

    return false;
}

bool Control::opntFind4()
{
    opntThree.clear();
    int i,j;
    bool found=false;
    for (i=0;i<opntC.size()-2;i++)
        if (opntFind3(i)&&opntThree[0]>myThree[0])
        {
            found=true;
            break;
        }

    if (found)
    {
        for (j=0;j<opntC.size();j++)
            if (opntC[j]!=0&&opntC[j]!=opntThree[0])
            {
                opntPos.push_back(j);
                break;
            }
    }

    if (found)
        return true;
    else if (findBomb())
        return true;
    else
        return false;

}

bool Control::opntFind5()
{
    opntThree.clear();
    int i,j;
    bool found=false;
    for (i=0;i<opntC.size()-2;i++)
        if (opntFind3(i)&&opntThree[0]>myThree[0])
        {
            found=true;
            break;
        }

    if (found)
    {
        for (j=0;j<opntC.size()-1;j++)
            if (opntC[j]!=0&&opntC[j]!=opntThree[0]&&opntC[j]==opntC[j+1])
            {
                opntPos.push_back(j);
                opntPos.push_back(j+1);
                break;
            }
    }

    if (found)
        return true;
    else if (findBomb())
        return true;
    else
        return false;
}

bool Control::opntFind6()
{
    int i,j,k,n=myOut.size();
    vector<int>::iterator iter=myOut.end()-1;
    if (*iter==12&&!findBomb())
        return false;
    else if (*iter==12&&findBomb())
        return true;

    for (i=0;i<opntC.size();i++)
    {
        if (opntC[i]>myOut[0])
        {
            j=i;
            opntPos.push_back(j);
            for (k=j+1;k<opntC.size();k++)
                if (opntC[j]==opntC[k]-1&&opntC[k]<13)
                {
                    opntPos.push_back(k);
                    j=k;
                }

            if (opntPos.size()>=n)
                break;
            else
                opntPos.clear();
        }
    }

    if (opntPos.size()>=n)
    {
        opntPos.assign(opntPos.begin(),opntPos.begin()+n);
        return true;
    }
    else if(findBomb())
        return true;
    else
    {
        opntPos.clear();
        return false;
    }
}

bool Control::opntFind7()
{
    int i,j,k,n=myOut.size();
    vector<int>::iterator iter=myOut.end()-1;
    if (*iter==12&&!findBomb())
        return false;
    else if (*iter==12&&findBomb())
        return true;

    for (i=0;i<opntC.size()-1;i++)
    {
        if (opntC[i]>myOut[0]&&opntC[i]==opntC[i+1])
        {
            j=i;
            opntPos.push_back(j);
            opntPos.push_back(j+1);
            for (k=j+1;k<opntC.size()-1;k++)
                if (opntC[j]==opntC[k]-1&&opntC[k]==opntC[k+1]&&opntC[k]<13)
                {
                    opntPos.push_back(k);
                    opntPos.push_back(k+1);
                    j=k+1;
                }

            if (opntPos.size()>=n)
                break;
            else
                opntPos.clear();
        }
    }

    if (opntPos.size()>=n)
    {
        opntPos.assign(opntPos.begin(),opntPos.begin()+n);
        return true;
    }
    else if(findBomb())
        return true;
    else{
        opntPos.clear();
        return false;
    }
}

void Control::findThree()
{
    int i,j,k,n=myThree.size();
    opntThree.clear();

    for (i=0;i<opntC.size()-2;i++)
    {
        if (opntC[i]>myOut[0]&&opntC[i]==opntC[i+1]&&opntC[i]==opntC[i+2])
        {
            j=i;
            opntPos.push_back(j);
            opntPos.push_back(j+1);
            opntPos.push_back(j+2);
            opntThree.push_back(opntC[j]);
            for (k=j+1;k<opntC.size()-2;k++)
                if (opntC[j]==opntC[k]-1&&opntC[k]==opntC[k+1]&&opntC[k]==opntC[k+2]&&opntC[k]<13)
                {
                    opntPos.push_back(k);
                    opntPos.push_back(k+1);
                    opntPos.push_back(k+2);
                    opntThree.push_back(opntC[k]);
                    j=k+2;
                }

            if (opntPos.size()>=3*n)
            {
                opntPos.assign(opntPos.begin(),opntPos.begin()+3*n);
                opntThree.assign(opntThree.begin(),opntThree.begin()+n);
                break;
            }
            else
            {
                opntPos.clear();
                opntThree.clear();
            }
        }
    }
}

bool Control::opntFind8()
{
    int n=myThree.size();
    vector<int>::iterator iter=myThree.end()-1;
    if (*iter==12&&!findBomb())
        return false;
    else if (*iter==12&&findBomb())
        return true;

    findThree();

    std::cout<<"p";

    if (opntPos.size()>=3*n)
    {
        opntPos.assign(opntPos.begin(),opntPos.begin()+3*n);
        return true;
    }
    else if(findBomb())
    {
        opntThree.clear();
        return true;
    }
    else
    {
        opntPos.clear();
        opntThree.clear();
        return false;
    }
}

bool Control::opntFind9()
{
    int i,cnt=0,n=myThree.size();
    vector<int> tmp(opntC.begin(),opntC.end()-1);
    vector<int>::iterator iter=myThree.end()-1,iter2;
    if (*iter==12&&!findBomb())
        return false;
    else if (*iter==12&&findBomb())
        return true;

    findThree();
    iter2=opntThree.end()-1;

    if (opntPos.size()>=3*n)
    {
        for (i=0;i<opntPos.size();i++)
            tmp[opntPos[i]]=0;
        for (i=0;i<tmp.size()&&cnt<myThree.size();i++)
            if (tmp[i]&&(tmp[i]>*iter2||tmp[i]<opntThree[0]))
            {
                opntPos.insert(opntPos.begin()+cnt+3*(cnt+1),i);
                cnt++;
            }

        if (cnt==n)
            return true;
        else if(findBomb())
        {
            opntThree.clear();
            return true;
        }
        else
        {
            opntPos.clear();
            opntThree.clear();
            return false;
        }
    }
    else if(findBomb())
    {
        opntThree.clear();
        return true;
    }
    else
    {
        opntPos.clear();
        opntThree.clear();
        return false;
    }
}

bool Control::opntFind10()
{
    int i,cnt=0,n=myThree.size();
    vector<int> tmp(opntC.begin(),opntC.end()-1);
    vector<int>::iterator iter=myThree.end()-1,iter2;
    if (*iter==12&&!findBomb())
        return false;
    else if (*iter==12&&findBomb())
        return true;

    findThree();
    iter2=opntThree.end()-1;

    if (opntPos.size()>=3*n)
    {
        for (i=0;i<opntPos.size();i++)
            tmp[opntPos[i]]=0;
        for (i=0,cnt=0;i<tmp.size()-1&&cnt<myThree.size();i++)
            if (tmp[i]&&(tmp[i]>*iter2||tmp[i]<opntThree[0])&&tmp[i]==tmp[i+1])
            {
                opntPos.insert(opntPos.begin()+2*cnt+3*(cnt+1),i);
                cnt++;
                opntPos.insert(opntPos.begin()+4*cnt,i+1);
                i++;
            }

        if (cnt==n)
            return true;
        else if(findBomb())
        {
            opntThree.clear();
            return true;
        }
        else
        {
            opntPos.clear();
            opntThree.clear();
            return false;
        }
    }
    else if(findBomb())
    {
        opntThree.clear();
        return true;
    }
    else
    {
        opntPos.clear();
        opntThree.clear();
        return false;
    }
}

bool Control::opntFind11()
{
    int i;
    opntPos.clear();
    for (i=0;i<opntC.size()-3;i++)
    {
        if (opntC[i]>myOut[0]&&opntC[i]==opntC[i+1]&&opntC[i]==opntC[i+2]&&opntC[i]==opntC[i+3])
        {
            opntPos.push_back(i);
            opntPos.push_back(i+1);
            opntPos.push_back(i+2);
            opntPos.push_back(i+3);
            return true;
        }
    }

    if (opntC[15]==14&&opntC[16]==15)
    {
        opntPos.push_back(15);
        opntPos.push_back(16);
        type=ROCKET;
        return true;
    }

    return false;
}
