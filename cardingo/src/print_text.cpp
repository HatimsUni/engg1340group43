#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "../include/card_dealer.h"
#include "../include/file_handler.h"
using namespace std;

// take color as string input and return the escape sequence characters of the color
string getEscapeSequence(string color)
{
    string escape_sequence;
    if (color == "black")
    {
        escape_sequence = "\033[30m";
    }
    else if (color == "red")
    {
        escape_sequence = "\033[31m";
    }
    else if (color == "green")
    {
        escape_sequence = "\033[32m";
    }
    else if (color == "yellow")
    {
        escape_sequence = "\033[33m";
    }
    else if (color == "blue")
    {
        escape_sequence = "\033[34m";
    }
    else if (color == "magenta")
    {
        escape_sequence = "\033[35m";
    }
    else if (color == "cyan")
    {
        escape_sequence = "\033[36m";
    }
    else if (color == "white")
    {
        escape_sequence = "\033[37m";
    }
    else if (color == "bronze")
    {
        escape_sequence = "\033[38;5;130m";
    }
    else if (color == "grey")
    {
        escape_sequence = "\033[90m";
    }
    else
    {
        escape_sequence = "\033[0m";
    }

    return escape_sequence;
}

// print one line of text, with the options of bold, color, and end of line.
void print(string text = "", string color = "default", bool bold = false, string end = "\n")
{
    string def = "\033[0m";
    string esc = getEscapeSequence(color);
    string bold_esc = "";
    if (bold == true)
    {
        bold_esc = "\033[1m";
    }
    cout << bold_esc << esc << text << def << end;
}

// takes suit as string input prints the suit in it's appropriate symbol and color
void printSuit(string suit)
{
    if (suit == "H")
    {
        print("♥", "red", "", "");
    }
    else if (suit == "D")
    {
        print("♦", "red", "", "");
    }
    else if (suit == "S")
    {
        print("♠", "", "", "");
    }
    else if (suit == "C")
    {
        print("♣", "", "", "");
    }
}

// prints the main heading for Cardingo
void printMainHeading()
{
    for (int i = 0; i < 5; i++)
    {
        printSuit("S");
        printSuit("H");
        printSuit("C");
        printSuit("D");
    }
    print();
    for (int i = 0; i < 5; i++)
    {
        printSuit("H");
        printSuit("C");
        printSuit("D");
        printSuit("S");
    }
    print();
    printSuit("C");
    printSuit("D");
    print("                ", "", "", "");
    printSuit("S");
    printSuit("H");
    print();
    printSuit("D");
    printSuit("S");
    print("    CARDINGO    ", "cyan", true, "");
    printSuit("H");
    printSuit("C");
    print();
    printSuit("S");
    printSuit("H");
    print("                ", "", "", "");
    printSuit("C");
    printSuit("D");
    print();
    for (int i = 0; i < 5; i++)
    {
        printSuit("H");
        printSuit("C");
        printSuit("D");
        printSuit("S");
    }
    print();
    for (int i = 0; i < 5; i++)
    {
        printSuit("C");
        printSuit("D");
        printSuit("S");
        printSuit("H");
    }
    print();
}

// prints the main thank you message at the end of the game
void printMainEnding()
{
    for (int i = 0; i < 8; i++)
    {
        printSuit("S");
        printSuit("H");
        printSuit("C");
        printSuit("D");
    }
    printSuit("S");
    print();
    for (int i = 0; i < 8; i++)
    {
        printSuit("H");
        printSuit("C");
        printSuit("D");
        printSuit("S");
    }
    printSuit("H");
    print();
    printSuit("C");
    printSuit("D");
    print("                             ", "", "", "");
    printSuit("H");
    printSuit("C");
    print();
    printSuit("D");
    printSuit("S");
    print("    THANK YOU FOR PLAYING    ", "cyan", true, "");
    printSuit("C");
    printSuit("D");
    print();
    printSuit("S");
    printSuit("H");
    print("                             ", "", "", "");
    printSuit("D");
    printSuit("S");
    print();
    for (int i = 0; i < 8; i++)
    {
        printSuit("H");
        printSuit("C");
        printSuit("D");
        printSuit("S");
    }
    printSuit("H");
    print();
    for (int i = 0; i < 8; i++)
    {
        printSuit("C");
        printSuit("D");
        printSuit("S");
        printSuit("H");
    }
    printSuit("C");
    print();
}

// takes the game name as string input and prints the game heading
void printGameHeading(string game)
{
    print("YOU ARE NOW PLAYING", "blue", true);
    string game_name;
    if (game == "crazyeights")
    {
        game_name = "CRAZY EIGHTS";
    }
    else if (game == "blackjack")
    {
        game_name = "BLACK JACK";
    }
    else if (game == "higherlower")
    {
        game_name = "HIGHER LOWER";
    }
    else if (game == "oldmaid")
    {
        game_name = "OLD MAID";
    }
    else if (game == "trump")
    {
        game_name = "TRUMP";
    }
    printSuit("H");
    print("  " + game_name + "  ", "green", true, "");
    printSuit("H");
    print();
}

// handle the output of user information before and after the game, previous score, and new score etc.
void printUserDetails(string user, string game, int total, int played, int score)
{
    string game_name;
    if (game == "bigtwo")
    {
        game_name = "Big Two Played";
    }
    else if (game == "blackjack")
    {
        game_name = "Black Jack Played";
    }
    else if (game == "higherlower")
    {
        game_name = "Higher Lower Played";
    }
    else if (game == "oldmaid")
    {
        game_name = "Old Maid Played";
    }
    else if (game == "trump")
    {
        game_name = "Trump Played";
    }
    print("Username", "red", true, ": ");
    print(user, "", "", "    ");
    print("Total Games Played", "cyan", true, ": ");
    print(to_string(total), "", "", "    ");
    print(game_name, "red", true, ": ");
    print(to_string(played), "", "", "    ");
    print("Score", "cyan", true, ": ");
    print(to_string(score), "", "", "    ");
    print();
}

// takes a single card as string input and prints the card as ASCII art
void printCard(string card, bool show)
{
    string value = getValue(card);
    string suit = getSuit(card);
    print("┌─────────┐");
    if (value != "10")
    {
        print("|" + value + "        |");
    }
    else
    {
        print("|" + value + "       |");
    }
    print("|         |");
    print("|    ", "", "", "");
    printSuit(suit);
    print("    |");
    print("|         |");
    if (value != "10")
    {
        print("|        " + value + "|");
    }
    else
    {
        print("|       " + value + "|");
    }
    print("└─────────┘");
    if (show)
    {
        print(card);
    }
}

// takes cards as vector<string> input and prints the cards as ASCII art
void printCards(vector<string> deck, int n, bool show)
{
    int size = deck.size();
    for (int i = 0; i < size / n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            print("┌─────────┐", "", "", end);
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            string num = getValue(deck[i * n + j]);
            if (num != "10")
            {
                print("|" + getValue(deck[i * n + j]) + "        |", "", "", end);
            }
            else
            {
                print("|" + getValue(deck[i * n + j]) + "       |", "", "", end);
            }
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            print("|         |", "", "", end);
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            print("|", "", "", "    ");
            printSuit(getSuit(deck[i * n + j]));
            print("    |", "", "", end);
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            print("|         |", "", "", end);
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            string num = getValue(deck[i * n + j]);
            if (num != "10")
            {
                print("|        " + getValue(deck[i * n + j]) + "|", "", "", end);
            }
            else
            {
                print("|       " + getValue(deck[i * n + j]) + "|", "", "", end);
            }
        }
        for (int j = 0; j < n; j++)
        {
            string end = "  ";
            if (j == n - 1)
            {
                end = "\n";
            }
            print("└─────────┘", "", "", end);
        }
        if (show)
        {
            for (int j = 0; j < n; j++)
            {
                string end = "  ";
                if (j == n - 1)
                {
                    end = "\n";
                }
                string num = getValue(deck[i * n + j]);
                if (num != "10")
                {
                    print(deck[i * n + j] + "         ", "", "", end);
                }
                else
                {
                    print(deck[i * n + j] + "        ", "", "", end);
                }
            }
        }
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        print("┌─────────┐", "", "", end);
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        string value = getValue(deck[j]);
        if (value != "10")
        {
            print("|" + value + "        |", "", "", end);
        }
        else
        {
            print("|" + value + "       |", "", "", end);
        }
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        print("|         |", "", "", end);
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        print("|", "", "", "    ");
        printSuit(getSuit(deck[j]));
        print("    |", "", "", end);
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        print("|         |", "", "", end);
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        string value = getValue(deck[j]);
        if (value != "10")
        {
            print("|        " + value + "|", "", "", end);
        }
        else
        {
            print("|       " + value + "|", "", "", end);
        }
    }
    for (int j = (size / n) * n; j < size; j++)
    {
        string end = "  ";
        if (j == size - 1)
        {
            end = "\n";
        }
        print("└─────────┘", "", "", end);
    }
    if (show)
    {
        for (int j = (size / n) * n; j < size; j++)
        {
            string end = "  ";
            if (j == size - 1)
            {
                end = "\n";
            }
            string value = getValue(deck[j]);
            if (value != "10")
            {
                print(deck[j] + "         ", "", "", end);
            }
            else
            {
                print(deck[j] + "        ", "", "", end);
            }
        }
    }
    // print("┌─────────┐");
    // print("|A        |");
    // print("|         |");
    // print("|    ♥    |");
    // print("|         |");
    // print("|        A|");
    // print("└─────────┘");
}

// prints the rules of the corresponding games
void printRules(string game_name)
{
    print();
    string choice;
    while (true)
    {
        print("Do you want to see the rules? (Y/N): ", "blue", true, "");
        cin >> choice;
        if (choice == "Y" || choice == "y")
        {
            vector<string> rules = getRules(game_name);
            print();
            print("Rules: ", "green", true);
            for (int i = 0; i < rules.size(); i++)
            {
                print(" - " + rules[i], "cyan");
            }
            break;
        }
        else if (choice == "N" || choice == "n")
        {
            break;
        }
        else
        {
            print("Invalid Choice!", "red", true);
        }
    }
    print();
    print("Continue? (Y): ", "blue", true, "");
    string input;
    while (true)
    {
        cin >> input;
        if (input == "Y" || input == "y")
        {
            break;
        }
        print("Invalid input!", "red", true);
        print("Continue? (Y): ", "blue", true, "");
    }
    print();
}

// Prints the medal of the user
void printMedal(int score)
{
    if (score > 0 && score <= 10)
    {
        print("Bronze 🥉 Medal", "bronze", true, "");
    }
    else if (score > 10 && score <= 20)
    {
        print("Silver 🥈 Medal", "grey", true, "");
    }
    else if (score > 20)
    {
        print("Gold 🥇 Medal", "yellow", true, "");
    }
}

// int main()
// {
//     return 0;
// }