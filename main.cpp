#include<iostream>
#include "Coin.h"
using namespace std;

void startBalance(double, double);
void accumulateBalance(double);
void headOrTail(string, string, string);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Coin quatar;
    Coin dime;
    Coin nickel;
    
    double playerBalance = 0.00;
    double computerBalance = 0.00;

    startBalance(playerBalance, computerBalance);
    headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
    headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
    
    return 0;
}
void startBalance(double balanceOfPlayer, double balanceOfComputer)
{
    cout << "Your starting balance: $" << balanceOfPlayer << endl;
    cout << "The computer's starting balance: $" << balanceOfComputer << endl << endl;
}
void headOrTail(string quatarSide, string dimeSide, string nickelSide)
{
    double total = 0.00;
    if (quatarSide == "heads")
        total += 0.25;
    else if (dimeSide == "heads")
        total += 0.10;
    else if (nickelSide == "heads")
        total += 0.05;
    accumulateBalance(total);
}
void accumulateBalance(double sum)
{
    int round = 1;
    cout << "Your balance after round " << round << ": $" << sum << endl;
    cout << "The computer's balance after round " << round << ": $" << sum << endl;
    round++;
}