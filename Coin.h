#include<string>
#ifndef COIN_H
#define COIN_H

class Coin
{
public:
    Coin();
    void toss();
    std::string getSideUp() const;
private:
    std::string sideUp;
};

#endif