#include<iostream>
#include<iomanip>
#include<string>
#include "Coin.h"
using namespace std;

void startBalance(double, double);
double headOrTail(string, string, string);
void accumulateBalance(double, double);
void endBalance(double, double);
string results(double, double);

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Coin quatar;
    Coin dime;
    Coin nickel;
    
    double playerBalance = 0;
    double computerBalance = 0;

    startBalance(playerBalance, computerBalance);
    do
    {
        quatar.toss();
        dime.toss();
        nickel.toss();
        playerBalance += headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
        
        quatar.toss();
        dime.toss();
        nickel.toss();
        computerBalance += headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
        
        accumulateBalance(playerBalance, computerBalance);
    } while (playerBalance < 1 && computerBalance < 1);
    endBalance(playerBalance, computerBalance);

    return 0;
}
void startBalance(double startOfPlayer, double startOfComputer)
{   
    cout << fixed << setprecision(2);
    cout << "Your starting balance: $" << startOfPlayer << endl;
    cout << "The computer's starting balance: $" << startOfComputer << endl << endl;
}
double headOrTail(string quatarSide, string dimeSide, string nickelSide)
{
    double total = 0;
    if (quatarSide == "heads")
        total += 0.25;
    if (dimeSide == "heads")
        total += 0.10;
    if (nickelSide == "heads")
        total += 0.05;
    return total;
}
void accumulateBalance(double playerSum, double computerSum)
{
    static int round = 1;
    cout << fixed << setprecision(2);
    cout << "Your balance after round " << round << ": $" << playerSum << endl;
    cout << "The computer's balance after round " << round++ << ": $" << computerSum << endl << endl;
}
void endBalance(double endOfPlayer, double endOfComputer)
{
    string display;
    cout << fixed << setprecision(2);
    cout << "Your ending balance: $" << endOfPlayer << endl;
    cout << "The computer's ending balance: $" << endOfComputer << endl << endl;
    display = results(endOfPlayer, endOfComputer);
    cout << display << endl << endl;
}
string results(double player, double computer)
{
    if (player > 1 && computer > 1)
    {
        if (player == computer)
            return "Tie! Nobody wins.";
        else
            return (player < computer) ? "Congratulations! You won." : "Sorry! The computer won.";
        
    }
    else if (player <= 1 && computer <= 1)
    {
        if (player == computer)
            return "Tie! Nobody wins.";
        else
            return (player > computer) ? "Congratulations! You won." : "Sorry! The computer won.";
    }
    else
        return (player > 1 && computer < 1) ? "Congratulations! You won." : "Sorry! The computer won.";
}