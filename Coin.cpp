#include<string>
#include <cstdlib>  // rand()
#include "Coin.h"
using namespace std;

// Comment 1: Constructor initializes the sideUp member variable
Coin::Coin()
{
    toss();
}

// Comment 2: Member function randomly determines which side of the coin is facing up,
//            then hold the results to the sideUp member variable.
void Coin::toss()
{
    int result;
    result = rand() % 2;    // Comment 3: A coin has only two sides.
    
    if (result == 1)
        sideUp = "heads";
    else if (result == 0)
        sideUp = "tails";
}

// Comment 4: sideUp holds "heads" or "tails" to show which side of the coin is facing up.
string Coin::getSideUp() const
{
    return sideUp;
}