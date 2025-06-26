#include<string>
#include "Coin.h"
using namespace std;

Coin::Coin()
{
    toss();
}

void Coin::toss()
{
    int result;
    result = rand() % 2;
    
    if (result == 1)
        sideUp = "heads";
    else if (result == 0)
        sideUp = "tails";
}

string Coin::getSideUp()
{
    return sideUp;
}