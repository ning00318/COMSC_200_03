#include<string>
#include "Coin.h"
using namespace std;

Coin::Coin()
{
    toss();
}

void Coin::toss()
{
    int results = rand() % 2;
    if (results == 1)
        sideUp = "heads";
    else if (results == 0)
        sideUp = "tails";
}

string Coin::getSideUp()
{
    return sideUp;
}