#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "../include/crazy_eights.h"
#include "../include/card_dealer.h"
#include "../include/print_text.h"
#include "../include/sleep.h"
#include "../include/score.h"

using namespace std;

// Human class
void Human::handSetup(vector<string> &deck, int k)
{ // draw k amount of card from the deck for initial setup
    hand = drawCard(deck, k);
}
void Human::printHand()
{ // print cards in hand as strings
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}
bool Human::isValidCard(string card, string &currentSuit, string &currentValue)
{ // check if the given card is valid to be played and match the currentSuit or currentValue
    if (currentValue == "8" && getSuit(card) == currentSuit)
    {
        return true;
    }
    else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8")
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Human::isWinner()
{ // check winning condition by counting the number of card in hand and return a boolean
    if (hand.size() == 0)
        return true;
    else
        return false;
}
void Human::pickSuit(string &currentSuit)
{ // set the currentSuit by taking input from player

    int input;

    cout << endl;
    cout << "1:";
    printSuit("D");
    cout << "\t2:";
    printSuit("C");
    cout << "\t3:";
    printSuit("H");
    cout << "\t4:";
    printSuit("S");
    cout << endl;
    cout << "Pick a suit [Enter 1 to 4]... ";

    bool isValidMove = false;
    while (!isValidMove)
    {

        while (true)
        {
            cin >> input;
            if (!cin)
            {
                cout << "Input an integer! ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else
                break;
        }

        if (1 <= input && input <= 4)
        {
            isValidMove = true;
        }
        else
        {
            cout << "\t1:D\t2:C\t3:H\t4:S" << endl;
            cout << "Invalid move! Pick a suit [Enter 1 to 4]... ";
        }
    }

    if (input == 1)
        currentSuit = "D";
    else if (input == 2)
        currentSuit = "C";
    else if (input == 3)
        currentSuit = "H";
    else if (input == 4)
        currentSuit = "S";

    cout << endl;
    cout << "You picked suit ";
    printSuit(currentSuit);
    cout << endl;
}
void Human::turn(vector<string> &deck, string &currentSuit, string &currentValue)
{ // execute one whole player turn

    if (currentValue == "8")
    {
        print("Current suit: ", "blue", true, "");
        printSuit(currentSuit); // cout << currentSuit << endl;
        print();
    }
    else
    {
        print("Current Card:", "yellow", true);
        printCard(currentSuit + currentValue, false); // cout << currentSuit << currentValue << endl;
    }
    wait(750);

    cout << endl;
    print("Your Cards: ", "yellow");
    printCards(hand, 5, false); // printHand();

    if (currentValue == "8")
    {
        print("Pick any ", "magenta", true, "");
        printSuit(currentSuit);
        print(" card [Enter 1 to " + to_string(hand.size()) + "] or draw a card [Enter 0]... ", "magenta", true, "");
    }
    else if (hand.size() > 1)
    {
        print("Pick a card [Enter 1 to " + to_string(hand.size()) + "] or draw a card [Enter 0]... ", "magenta", true, "");
    }
    else if (hand.size() == 1)
    {
        print("Pick a card [Enter 1] or draw a card [Enter 0]... ", "magenta", true, "");
    }

    // check if there are move available
    bool isMoveAvail = false;
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++)
    {
        if (isValidCard(*itr, currentSuit, currentValue))
        {
            isMoveAvail = true;
            break;
        }
    }

    int input;
    while (true)
    {
        cin >> input;
        if (!cin)
        {
            print("Input an integer! ", "red", true, "");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
            break;
    }

    bool isValidMove = false;
    while (!isValidMove)
    {
        if (isMoveAvail == true)
        {
            while (!(0 < input && input <= hand.size()) || !isValidCard(hand[input - 1], currentSuit, currentValue))
            {
                if (currentValue == "8")
                {
                    print("Invalid move! Pick a " + currentSuit + " card [Enter 1 to " + to_string(hand.size()) + "]... ", "red", true, "");
                }
                else if (hand.size() > 1)
                {
                    print("Invalid move! Pick a card [Enter 1 to " + to_string(hand.size()) + "]... ", "red", true, "");
                }
                else if (hand.size() == 1)
                {
                    print("Invalid move! Pick a card [Enter 1]... ", "red", true, "");
                }

                while (true)
                {
                    cin >> input;
                    if (!cin)
                    {
                        print("Input an integer! ", "red", true, "");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    else
                        break;
                }
            }
            isValidMove = true;
        }
        else if (isMoveAvail == false)
        {
            while (input != 0)
            {
                print("Invalid move! Draw a card [Enter 0]... ", "red", true, "");

                while (true)
                {
                    cin >> input;
                    if (!cin)
                    {
                        print("Input an integer! ", "red", true, "");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    else
                        break;
                }
            }
            isValidMove = true;
        }
    }
    wait(300);
    cout << endl;

    if (input == 0)
    {
        vector<string> temp = drawCard(deck, 1);
        print("You drew...", "cyan");
        wait(150);
        printSuit(getSuit(temp.front()));
        cout << getValue(temp.front()) << endl;

        while (!isValidCard(temp.front(), currentSuit, currentValue))
        {
            hand.push_back(temp.front());

            print("Draw a card again, you drew... ", "cyan");
            wait(850);

            temp = drawCard(deck, 1);
            printSuit(getSuit(temp.front()));
            cout << getValue(temp.front()) << endl;
        }
        wait(300);
        print("You picked..", "green", true);
        printSuit(getSuit(temp.front()));
        cout << getValue(temp.front()) << endl;

        currentSuit = getSuit(temp.front());
        currentValue = getValue(temp.front());

        if (currentValue == "8")
        {
            printCards(hand, 5, false);
        }
    }
    else if (input > 0)
    {
        print("You picked..", "green", true);
        printSuit(getSuit(hand[input - 1]));
        cout << getValue(hand[input - 1]) << endl;
        currentSuit = getSuit(hand[input - 1]);
        currentValue = getValue(hand[input - 1]);
        hand.erase(hand.begin() + input - 1);
    }

    if (currentValue == "8")
    {
        pickSuit(currentSuit);
    }
    wait(650);
    cout << endl;
}

// Robot class
void Robot::handSetup(vector<string> &deck, int k)
{ // draw k amount of card from the deck for initial setup
    hand = drawCard(deck, k);
}
void Robot::printHand()
{ // print cards in hand as strings
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++)
    {
        print(*itr, "", "", "");
    }
    print();
}
bool Robot::isValidCard(string card, string &currentSuit, string &currentValue)
{ // check if the given card is valid to be played and match the currentSuit or currentValue

    if (currentValue == "8" && getSuit(card) == currentSuit)
    {
        return true;
    }
    else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8")
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Robot::isWinner()
{ // check winning condition by counting the number of card in hand and return a boolean
    if (hand.size() == 0)
        return true;
    else
        return false;
}
void Robot::pickSuit(string &currentSuit)
{ // set the currentSuit by taking input from player

    wait(250);
    cout << endl;

    int input = (rand() % 4) + 1;
    if (input == 1)
        currentSuit = "D";
    else if (input == 2)
        currentSuit = "C";
    else if (input == 3)
        currentSuit = "H";
    else if (input == 4)
        currentSuit = "S";

    print("Computer picked suit ", "cyan", true, "");
    printSuit(currentSuit);
    cout << endl;
}
void Robot::turn(vector<string> &deck, string &currentSuit, string &currentValue)
{ // execute one whole player turn

    cout << endl;

    bool isMoveAvail = false;
    vector<int> validInput;
    vector<string>::iterator itr;
    int i = 1;
    for (itr = hand.begin(); itr != hand.end(); itr++)
    {
        if (isValidCard(*itr, currentSuit, currentValue))
        {
            isMoveAvail = true;
            validInput.push_back(i);
        }
        i++;
    }
    if (!isMoveAvail)
    {
        validInput.push_back(0);
    }

    int random = rand() % validInput.size();
    int input = validInput[random];

    if (input == 0)
    {

        wait(750);
        vector<string> temp = drawCard(deck, 1);
        print("Computer drew a card ", "cyan", "", "");

        while (!isValidCard(temp.front(), currentSuit, currentValue))
        {
            wait(900);
            hand.push_back(temp.front());
            print("\nComputer drew a card again ", "cyan", "", "");
            temp = drawCard(deck, 1);
        }
        wait(150);
        print("[Computer's card(s) left: " + to_string(hand.size()) + "]", "blue");

        wait(200);
        cout << endl;
        print("Computer picked.. ", "cyan");
        printSuit(getSuit(temp.front()));
        cout << getValue(temp.front()) << endl;

        currentSuit = getSuit(temp.front());
        currentValue = getValue(temp.front());
        wait(350);
    }
    else if (input > 0)
    {

        wait(750);
        print("Computer picked.. ", "cyan");

        wait(1050);
        printSuit(getSuit(hand[input - 1]));
        cout << getValue(hand[input - 1]) << endl;

        currentSuit = getSuit(hand[input - 1]);
        currentValue = getValue(hand[input - 1]);
        hand.erase(hand.begin() + input - 1);

        wait(150);
        print("[Computer's card(s) left: " + to_string(hand.size()) + "]", "blue");
        wait(1350);
    }

    if (currentValue == "8")
    {
        pickSuit(currentSuit);
    }
    cout << endl;
}

// Deck class
void Deck::getStartingCard(vector<string> &deck, string &currentSuit, string &currentValue)
{ // draw a non-eight card to be use as the current card
    vector<string>::iterator itr = deck.begin();
    while (getValue(*itr) == "8")
    {
        itr++;
    }
    currentValue = getValue(*itr);
    currentSuit = getSuit(*itr);
    deck.erase(itr);
}

// starts the crazy eights game
int playCrazyEights()
{


    vector<string> deck = newDeck(true);
    string currentValue;
    string currentSuit;
    game_score = 0;

    Human h;
    h.handSetup(deck, 7);
    Robot r;
    r.handSetup(deck, 7);
    Deck d;
    d.getStartingCard(deck, currentSuit, currentValue);

    while (true)
    {
        if (deck.size() == 0)
        {
            print("tie!", "cyan", true);
            break;
        }
        h.turn(deck, currentSuit, currentValue);
        if (h.isWinner())
        {
            print("you win!", "green", true);
            game_score = 2;
            break;
        }

        if (deck.size() == 0)
        {
            print("tie!", "cyan", true);
            game_score = 1;
            break;
        }
        r.turn(deck, currentSuit, currentValue);
        if (r.isWinner())
        {
            print("you lose!", "red", true);
            game_score = 0;
            break;
        }
    }

    cout << endl;
    return game_score;
}