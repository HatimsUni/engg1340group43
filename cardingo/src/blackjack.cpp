#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/blackjack.h"
#include "../include/print_text.h"
#include "../include/card_dealer.h"
#include "../include/sleep.h"
using namespace std;

vector<string> deck;
vector<string> user_deck;
vector<string> comp1;
vector<string> comp2;
vector<string> comp3;
vector<string> comp4;
vector<string> comp5;
int score = 0;

// BLACKJACK TOOLS START

// BLACKJACK TOOLS END

void startRound(int n)
{
}

void startGame()
{
    int n;
    print("You will be playing against computers, Good Luck!", "green", true);
    print("Number of Players (2-6): ", "magenta", true, "");
    cin >> n;
    while (n > 6 || n < 2)
    {
        print("Invalid input!", "red", true);
        print("Number of Players (2-6): ", "magenta", true, "");
        cin >> n;
    }
    startRound(n);
}

int playBlackjack()
{
    deck = newDeck();
    startGame();

    return score;
}