#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
    #include <string>


class Player
{
public:
    Player(std::string name="\0",int score=0);
    inline void setName(std::string name){name_=name;}
    inline std::string getName(){return name_;}
    inline void setScore(int score){score_=score;}
    inline int getScore(){return score_;}
    ~Player(){}
private:
    std::string name_;
    int score_;
};

#endif // PLAYER_H_INCLUDED
