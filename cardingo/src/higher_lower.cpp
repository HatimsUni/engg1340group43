#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include "../include/higher_lower.h"
#include "../include/card_dealer.h"
#include "../include/print_text.h"
#include "../include/sleep.h"
#include "../include/score.h"
using namespace std;

int life_count = 5;

void startHigherLower();
vector<string> getCards();
void startHigherLower();
void continueHigherLower(vector<string> answer_cards);
int getRank(string val);
string compareCards(string current_card, string next_card);
void higherLowerWinner();

int playHigherLower()
{
    life_count = 5;
    startHigherLower();
    return game_score;
}

vector<string> getCards()
{
    vector<string> deck = newDeck(true);
    return drawCard(deck, 11);
}

void startHigherLower()
{
    vector<string> answer_cards = getCards();
    continueHigherLower(answer_cards);
}

void continueHigherLower(vector<string> answer_cards)
{
    string guess;
    string answer;
    string answer_char;

    for (int i = 0; i <= answer_cards.size() - 2; i++)
    {
        string current_card = answer_cards[i];
        print("Current card: ", "yellow", true);
        printCard(current_card);
        print("Is the current card (H: Higher, L: Lower, S: Similar) than the next card: ", "magenta", true, "");
        cin >> guess;

        while (!(guess == "H" || guess == "L" || guess == "S" || guess == "h" || guess == "l" || guess == "s"))
        {
            print("Invalid guess (H/L/S): ", "red", true);
            wait(500);
            print("Is the current card (H: Higher, L: Lower, S: Similar) than the next card: ", "magenta", true, "");
            cin >> guess;
        }
        wait();

        string next_card = answer_cards[i + 1];
        print("Next card: ", "yellow", true);
        printCard(next_card);

        answer = compareCards(current_card, next_card);
        const char answer_char = answer[0];
        const char guess_char = toupper(guess[0]);

        if (answer_char == guess_char)
        {
            print("Congratulation! Your guess is correct!", "green", true, "\n");
        }
        else
        {
            print("Incorrect guess, the correct answer was: " + answer, "red", true);
            print("You lost one life.", "magenta", false, "\n");
            life_count--;
            print("Total lives left: " + to_string(life_count), "red");
        }

        if (life_count == 0)
        {
            print("You lost all your lives.\n", "red", true);
            break;
        }
    }

    higherLowerWinner();
}

int getRank(string val)
{
    string newval = val.substr(1, val.length() - 1);
    vector<string> vect_ranks = {"A", "K", "Q", "J", "10", "9", "8",
                                 "7", "6", "5", "4", "3", "2"};
    int rank;
    for (int i = 0; i <= vect_ranks.size(); i++)
    {
        if (newval == vect_ranks[i])
        {
            rank = i;
        }
    }
    rank = 13 - rank;
    return rank;
}

string compareCards(string current_card, string next_card)
{
    string answer;

    string current_value = getValue(current_card);
    int current_rank = getRank(current_card);
    string next_value = getValue(next_card);
    int next_rank = getRank(next_card);

    if (next_value == current_value)
    {
        answer = "Similar";
    }
    else
    {
        if (current_rank > next_rank)
        {
            answer = "Higher";
        }
        else
        {
            answer = "Lower";
        }
    }

    return answer;
}

void higherLowerWinner()
{
    if (life_count == 5)
    {
        game_score = 5;
        print("You Won!", "green", true);
    }
    else if (life_count == 4)
    {
        game_score = 4;
        print("You Won!", "green", true);
    }
    else if (life_count == 3)
    {
        game_score = 3;
        print("You Won!", "green", true);
    }
    else if (life_count == 2)
    {
        game_score = 2;
        print("You Won!", "green", true);
    }
    else if (life_count == 1)
    {
        game_score = 1;
        print("You Won!", "green", true, "\n");
    }
    else
    {
        game_score = 0;
        print("You Lost!", "red", true);
    }
}