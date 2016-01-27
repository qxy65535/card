#ifndef CONTORL_H_INCLUDED
#define CONTORL_H_INCLUDED
    #include <wx/wx.h>
    #include <vector>
    #include <cstdlib>
    #include <wx/settings.h>
const int PILE=17;
const int TOTAL=54;

enum {
    SINGLE=1,//3
    PAIR=2,//33
    TRIPLE=3,//333
    TRIPLE_WITH_ONE=4,
    TRIPLE_WITH_TWO=5,
    SEQUENCE_QUENCE=6,//34567
    SEQUENCE_QUENCE_OF_PAIRS=7,//334455
    SEQUENCE_QUENCE_OF_TRIPLETS=8,//333444
    SEQUENCE_QUENCE_OF_TRIPLETS_WITH_ONE=9,//33344456
    SEQUENCE_QUENCE_OF_TRIPLETS_WITH_TWO=10,//3334445566
    BOMB=11,
    ROCKET=12
};

using namespace std;

class Control
{
public:
    void washCard(vector<wxBitmapButton*>& my,vector<int> &myC,vector<wxBitmapButton*>& opnt,vector<int> &opntC);
    void sandCard(vector<wxBitmapButton*>& my,vector<wxBitmapButton*>& opnt,wxBitmapButton* BmpButton);
    void sortMy(vector<wxBitmapButton*>& card,vector<int> &n);
    void sortOpnt(vector<wxBitmapButton*>& card,vector<int> &n);
    void setOpntPos(int i,int cnt);
    inline bool getFirst(){return first;}
    inline void setFirst(bool first){this->first=first;}
    inline void setType(){type=typeMy;}
    inline void setType(int type){this->type=type;}
    inline void getOpntC(vector<int> opntC){this->opntC.assign(opntC.begin(),opntC.end());}
    bool check(vector<int> &n);
    bool checkType(std::vector<int> &n);
    void orderMy(vector<wxBitmapButton*>& card,vector<int> &n);
    void orderOpnt(std::vector<wxBitmapButton*>& card,std::vector<int> &n);
    void getOutCard(vector<int> outCard1);
    bool opntOut(vector<int> opntC,vector<int> &opntPos);
    ~Control(){}
private:
    int type;
    int typeMy;
    bool first=true;
    vector<int> myThree;
    vector<int> myOut;
    vector<int> opntC;
    vector<int> opntThree;
    vector<int> opntPos;
    bool checkSequence();
    bool checkSequenceOfPairs();
    bool checkSequenceOfPairs2(vector<int> tmp);
    bool checkSequenceOfTriplets(vector<int> tmp);
    inline bool check1(){typeMy=SINGLE;return true;}
    bool check2();
    bool check3();
    bool check4();
    bool check5();
    bool check6();
    bool check7();
    bool check8();
    bool check9();
    bool check10();
    bool check12();
    bool check14();
    bool check15();
    bool check16();
    bool checkType1();
    bool checkType2();
    bool findBomb();
    bool opntFind1();
    bool opntFind2(int n);
    bool opntFind3(int n);
    bool opntFind4();
    bool opntFind5();
    bool opntFind6();
    bool opntFind7();
    void findThree();
    bool opntFind8();
    bool opntFind9();
    bool opntFind10();
    bool opntFind11();
};

#endif // CONTORL_H_INCLUDED
