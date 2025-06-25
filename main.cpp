#include<iostream>
#include<iomanip>
#include "Coin.h"
using namespace std;

void startBalance(double, double);
void headOrTail(string, string, string);
void accumulateBalance(double);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Coin quatar;
    Coin dime;
    Coin nickel;
    
    double playerBalance = 0;
    double computerBalance = 0;

    startBalance(playerBalance, computerBalance);
    headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
    headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
    
    return 0;
}
void startBalance(double balanceOfPlayer, double balanceOfComputer)
{   
    cout << fixed << setprecision(2);
    cout << "Your starting balance: $" << balanceOfPlayer << endl;
    cout << "The computer's starting balance: $" << balanceOfComputer << endl << endl;
}
void headOrTail(string quatarSide, string dimeSide, string nickelSide)
{
    static double total = 0;
    if (quatarSide == "heads")
        total += 0.25;
    if (dimeSide == "heads")
        total += 0.10;
    if (nickelSide == "heads")
        total += 0.05;
    accumulateBalance(total);
}
void accumulateBalance(double sum)
{
    static int round = 1;
    cout << fixed << setprecision(2);
    cout << "Your balance after round " << round << ": $" << sum << endl;
    cout << "The computer's balance after round " << round++ << ": $" << sum << endl << endl;
}