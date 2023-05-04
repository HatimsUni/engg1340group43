#include <iostream>
#include <string>
#include <vector>
#include "../include/trump.h"
#include "../include/print_text.h"
#include "../include/card_dealer.h"
#include "../include/sleep.h"
using namespace std;
vector<string> order = {"A", "K", "Q"};
vector<string> user_deck;
vector<string> comp1;
vector<string> comp2;
vector<string> comp3;

int getCardValue(string card)
{
    int number;
    string value = getValue(card);
    if (value == "A")
    {
        number = 14;
    }
    else if (value == "K")
    {
        number = 13;
    }
    else if (value == "Q")
    {
        number = 12;
    }
    else if (value == "J")
    {
        number = 11;
    }
    else
    {
        number = stoi(value);
    }
    return number;
}

string calculateTrump(vector<string> deck)
{
    int s = 0;
    int h = 0;
    int c = 0;
    int d = 0;
    int max_value = 0;
    string max_suit;
    string suit;
    int value;
    for (int i = 0; i < 5; i++)
    {
        suit = getSuit(deck[i]);
        value = getCardValue(deck[i]);
        if (suit == "S") {
            s += value;
            if (s > max_value) {
                max_suit = "S";
                max_value = s;
            }
        } else if (suit == "H") {
            h += value;
            if (h > max_value) {
                max_suit = "H";
                max_value = h;
            }
        } else if (suit == "C") {
            c += value;
            if (c > max_value) {
                max_suit = "C";
                max_value = c;
            }
        } else if (suit == "D") {
            d += value;
            if (d > max_value) {
                max_suit = "D";
                max_value = d;
            }
        }
    }
    return max_suit;
}

void startGame(int winner)
{
    vector<string> deck = newDeck();
    string trump;
    user_deck = drawCard(deck, 5);
    comp1 = drawCard(deck, 5);
    comp2 = drawCard(deck, 5);
    comp3 = drawCard(deck, 5);
    if (winner == 0)
    {
        printCards(user_deck, 5);
        print("Please choose the trump", "magenta", true);
        print("S: Spades (♠)");
        print("H: Hearts (♥)", "red");
        print("C: Clubs (♣)");
        print("D: Diamonds (♦)", "red");
        cin >> trump;
        while (trump != "S" && trump != "H" && trump != "C" && trump != "D") {
            print("Wrong input! Please input again", "red", true);
            print("Trump: ", "magenta", false, "");
            cin >> trump;
        }
    }
    else if (winner == 1)
    {
        trump = calculateTrump(comp1);
    }
    else if (winner == 2)
    {
        trump = calculateTrump(comp2);
    }
    else if (winner == 3)
    {
        trump = calculateTrump(comp3);
    }

    print();
}


void toss(vector<string> deck)
{
    vector<string> draw4 = drawCard(deck, 4);
    wait(500);
    print("This is a toss, the player with the highest number starts!", "magenta", true);
    wait();
    print("Your card: ", "green", true, "  ");
    print("Computer 1:  Computer 2:  Computer 3:", "cyan");
    printCards(draw4);
    wait(2000);
    int highest = 0;
    string value;
    int number = 0;
    int winner;
    for (int i = 0; i < 4; i++)
    {
        number = getCardValue(draw4[i]);
        if (number > highest)
        {
            highest = number;
            winner = i;
        }
    }
    if (winner == 0)
    {
        print("You won the toss!", "magenta", true);
    }
    else
    {
        print("Computer " + to_string(winner) + " won the toss!", "cyan");
    }
    wait();
    startGame(winner);
}

void playTrump()
{
    toss(newDeck());
}