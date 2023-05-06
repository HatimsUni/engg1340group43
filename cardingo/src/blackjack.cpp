#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/blackjack.h"
#include "../include/print_text.h"
#include "../include/card_dealer.h"
#include "../include/sleep.h"
#include "../include/score.h"
using namespace std;

vector<string> deck;
int n;
vector<vector<string>> player_cards;
vector<string> status;
vector<int> scores;

// BLACKJACK TOOLS START

void finalWinners() {
    
}

void printStatus(int i)
{
    if (i == 0)
    {
        if (status[i] == "L")
        {
            print("You have lost the game!", "red", true);
        }
        else if (status[i] == "S")
        {
            print("You have chosen to stand!", "blue", true);
        }
        else if (status[i] == "W")
        {
            print("Your score is 21, you have won!", "magenta", true);
        }
    }
    else
    {
        if (status[i] == "L")
        {
            print("Computer " + to_string(i) + " has lost the game!", "red", true);
        }
        else if (status[i] == "S")
        {
            print("Computer " + to_string(i) + " has chosen to stand!", "blue", true);
        }
        else if (status[i] == "W")
        {
            print("Computer " + to_string(i) + " has won, it's score is 21!", "magenta", true);
        }
    }
}

int getCardRank(string value)
{
    if (value == "J" || value == "Q" || value == "K")
    {
        return 10;
    }
    else if (value == "A")
    {
        return 11;
    }
    else
    {
        return stoi(value);
    }
}

int getPlayerScore(int i)
{
    return scores[i];
}
void updatePlayerScore(int i)
{
    int score = getPlayerScore(i);
    int n = player_cards[i].size();
    string value = getValue(player_cards[i][n - 1]);
    if (value == "A")
    {
        if (score <= 10)
        {
            score += 11;
        }
        else
        {
            score += 1;
        }
    }
    else
    {
        score += getCardRank(value);
    }
    scores[i] = score;
    if (score > 21)
    {
        status[i] = "L";
    }
    else if (score == 21)
    {
        status[i] = "W";
    }
}

void hit(int i)
{
    if (i == 0)
    {
        print("You chose to Hit!", "magenta", true);
        player_cards[i].push_back(drawCard(deck, 1)[0]);
        updatePlayerScore(i);
        printCards(player_cards[i]);
        print("Your score: " + to_string(getPlayerScore(i)), "blue", true);
        printStatus(i);
    }
    else
    {
        print("Computer " + to_string(i) + " chose to Hit!", "cyan");
        player_cards[i].push_back(drawCard(deck, 1)[0]);
        updatePlayerScore(i);
        printCards(player_cards[i]);
        print("Computer " + to_string(i) + "'s score: " + to_string(getPlayerScore(i)), "blue");
        printStatus(i);
    }
}

void stand(int i)
{
    if (i == 0)
    {
        print("You chose to Stand!", "magenta", true);
        status[i] = "S";
    }
    else
    {
        print("Computer " + to_string(i) + " chose to Stand!", "cyan");
        status[i] = "S";
    }
}

string getChoice(int i)
{
    string choice;
    int score;
    if (i == 0)
    {
        print("Hit (H) or Stand (S): ", "blue", true, "");
        cin >> choice;
        while (choice != "H" && choice != "S")
        {
            print("Invalid Choice!", "red", true);
            print("Hit (H) or Stand (S): ", "blue", true, "");
            cin >> choice;
        }
    }
    else
    {
        score = getPlayerScore(i);
        if (score <= 16)
        {
            choice = "H";
        }
        else
        {
            choice = "S";
        }
    }
    return choice;
}

bool isFinished()
{
    bool finished = true;
    for (int i = 0; i < n; i++)
    {
        if (status[i] == "P")
        {
            finished = false;
        }
    }
    return finished;
}
// BLACKJACK TOOLS END

void startRound()
{
    string choice;
    for (int i = 0; i < n; i++)
    {
        player_cards[i].push_back(drawCard(deck, 1)[0]);
        updatePlayerScore(i);
    }
    for (int i = 0; i < n; i++)
    {
        player_cards[i].push_back(drawCard(deck, 1)[0]);
        updatePlayerScore(i);
    }
    while (!isFinished())
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                print("It is your turn!", "magenta", true);
                printCards(player_cards[i]);
                print("Your score: " + to_string(getPlayerScore(i)), "blue", true);
            }
            else
            {
                print("It is Computer " + to_string(i) + "'s turn!", "cyan");
                printCards(player_cards[i]);
                print("Computer " + to_string(i) + "'s score: " + to_string(getPlayerScore(i)), "blue");
            }
            if (status[i] == "P")
            {
                choice = getChoice(i);
                if (choice == "H")
                {
                    hit(i);
                }
                else
                {
                    stand(i);
                }
            } else {
                printStatus(i);
            }
        }
    }
}

void startGame()
{
    print("You will be playing against computers, Good Luck!", "green", true);
    print("Number of Players (2-6): ", "magenta", true, "");
    cin >> n;
    while (n > 6 || n < 2)
    {
        print("Invalid input!", "red", true);
        print("Number of Players (2-6): ", "magenta", true, "");
        cin >> n;
    }
    vector<vector<string>> player_cards_temp(n);
    vector<string> status_temp(n, "P");
    vector<int> scores_temp(n, 0);
    player_cards = player_cards_temp;
    status = status_temp;
    scores = scores_temp;
    startRound();
}

int playBlackjack()
{
    deck = newDeck();
    startGame();

    return game_score;
}