#include <iostream>
#include <string>
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

int main()
{
    print_main_heading();
    return 0;
}