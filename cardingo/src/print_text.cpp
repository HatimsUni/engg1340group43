#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "../include/card_dealer.h"
using namespace std;

string get_escape_seq(string color)
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
    else
    {
        escape_sequence = "\033[0m";
    }

    return escape_sequence;
}

void print(string text = "", string color = "default", bool bold = false, string end = "\n")
{
    string def = "\033[0m";
    string esc = get_escape_seq(color);
    string bold_esc = "";
    if (bold == true)
    {
        bold_esc = "\033[1m";
    }
    cout << bold_esc << esc << text << def << end;
}

void print_suit(string suit)
{
    if (suit == "H")
    {
        print("\xE2\x99\xA5", "red", "", "");
    }
    else if (suit == "D")
    {
        print("\xE2\x99\xA6", "red", "", "");
    }
    else if (suit == "S")
    {
        print("\xE2\x99\xA0", "", "", "");
    }
    else if (suit == "C")
    {
        print("\xE2\x99\xA3", "", "", "");
    }
}

void print_main_heading()
{
    for (int i = 0; i < 5; i++)
    {
        print_suit("S");
        print_suit("H");
        print_suit("C");
        print_suit("D");
    }
    print();
    for (int i = 0; i < 5; i++)
    {
        print_suit("H");
        print_suit("C");
        print_suit("D");
        print_suit("S");
    }
    print();
    print_suit("C");
    print_suit("D");
    print("                ", "", "", "");
    print_suit("S");
    print_suit("H");
    print();
    print_suit("D");
    print_suit("S");
    print("    CARDINGO    ", "cyan", true, "");
    print_suit("H");
    print_suit("C");
    print();
    print_suit("S");
    print_suit("H");
    print("                ", "", "", "");
    print_suit("C");
    print_suit("D");
    print();
    for (int i = 0; i < 5; i++)
    {
        print_suit("H");
        print_suit("C");
        print_suit("D");
        print_suit("S");
    }
    print();
    for (int i = 0; i < 5; i++)
    {
        print_suit("C");
        print_suit("D");
        print_suit("S");
        print_suit("H");
    }
    print();
}

void print_main_ending()
{
    for (int i = 0; i < 8; i++)
    {
        print_suit("S");
        print_suit("H");
        print_suit("C");
        print_suit("D");
    }
    print_suit("S");
    print();
    for (int i = 0; i < 8; i++)
    {
        print_suit("H");
        print_suit("C");
        print_suit("D");
        print_suit("S");
    }
    print_suit("H");
    print();
    print_suit("C");
    print_suit("D");
    print("                             ", "", "", "");
    print_suit("H");
    print_suit("C");
    print();
    print_suit("D");
    print_suit("S");
    print("    THANK YOU FOR PLAYING    ", "cyan", true, "");
    print_suit("C");
    print_suit("D");
    print();
    print_suit("S");
    print_suit("H");
    print("                             ", "", "", "");
    print_suit("D");
    print_suit("S");
    print();
    for (int i = 0; i < 8; i++)
    {
        print_suit("H");
        print_suit("C");
        print_suit("D");
        print_suit("S");
    }
    print_suit("H");
    print();
    for (int i = 0; i < 8; i++)
    {
        print_suit("C");
        print_suit("D");
        print_suit("S");
        print_suit("H");
    }
    print_suit("C");
    print();
}

void print_game_heading(string game)
{
    print("YOU ARE NOW PLAYING", "blue", true);
    string game_name;
    if (game == "bigtwo")
    {
        game_name = "BIG TWO";
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
    print_suit("H");
    print("  " + game_name + "  ", "green", true, "");
    print_suit("H");
    print();
}

void print_user_details(string user, string game, int total = 0, int played = 0, int score = 0)
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

void print_cards(vector<string> deck, int n = 5)
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
            print_suit(getSuit(deck[i * n + j]));
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
        print("|" + getValue(deck[j]) + "        |", "", "", end);
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
        print_suit(getSuit(deck[j]));
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
        print("|        " + getValue(deck[j]) + "|", "", "", end);
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
    // print("┌─────────┐");
    // print("|A        |");
    // print("|         |");
    // print("|    ♥    |");
    // print("|         |");
    // print("|        A|");
    // print("└─────────┘");
}

int main()
{
    vector<string> deck = newDeck(false);
    print_cards(deck);
    return 0;
}