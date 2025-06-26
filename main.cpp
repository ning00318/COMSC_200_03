#include<iostream>
#include <cstdlib>  // srand()
#include <ctime>
#include<iomanip>   // setprecision()
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

    // Comment 5: Create 3 objects -> quatar, dime, and nickel.
    Coin quatar;
    Coin dime;
    Coin nickel;
    
    // Comment 6: Set both the player and computer's initial balance to $0.00.
    double playerBalance = 0;
    double computerBalance = 0;
    startBalance(playerBalance, computerBalance);

    do
    {
        // Comment 8: The player tosses 3 types of the coin and accumulates the values to their balance.
        quatar.toss();
        dime.toss();
        nickel.toss();
        playerBalance += headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
        
        // Comment 10: The computer tosses 3 types of the coin, and accumulates the values to its balance.
        quatar.toss();
        dime.toss();
        nickel.toss();
        computerBalance += headOrTail(quatar.getSideUp(), dime.getSideUp(), nickel.getSideUp());
        
        // Comment 11: Print out both the player and computer's balance for each round.
        accumulateBalance(playerBalance, computerBalance);
    } while (playerBalance < 1 && computerBalance < 1); // Comment 12: Toss until one of their balance >= 1.
    
    // Comment 13: Output the final balance and results of the player and computer when the game ends.
    endBalance(playerBalance, computerBalance);

    return 0;
}

// Comment 7: Output the starting balance of the player and computer when the game begins.
void startBalance(double startOfPlayer, double startOfComputer)
{   
    cout << fixed << setprecision(2);
    cout << "Your starting balance: $" << startOfPlayer << endl;
    cout << "The computer's starting balance: $" << startOfComputer << endl << endl;
}

// Comment 9: For each type of coin, if it shows the head is facing up, then add up its respective value
//            to the total and return to the balance of who tossed, otherwise, nothing is added.
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

// Comment 14: Comparing the final balance of the player and computer, we already determined the game ends when
//             one of their balance greater than or equal to 1 in line #45. So there's no need to compare that again.
string results(double player, double computer)
{
    if (player == computer)     // Comment 15: When both balances are >= 1 and have the same amount, nobody wins.
        return "Tie! Nobody wins.";
    else if (player >= 1 && computer >= 1)  // Comment 16: When both balances are >= 1, the smaller amount wins.
        return (player < computer) ? "(1)Congratulations! You won." : "(2)Sorry! The computer won.";
    else    // Comment 17: When one's is balance >= 1 and another one's is < 1, the bigger amount wins.
        return (player >= 1 && computer < 1) ? "(3)Congratulations! You won." : "(4)Sorry! The computer won.";
}