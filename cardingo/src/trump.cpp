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

struct Round
{
    int team1;
    int team2;
    int round;
    int winner;
    string round_suit = "?";
    string trump;
};

// TRUMP TOOLS START

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

string getValueCard(int value)
{
    string number;
    if (value == 14)
    {
        number = "A";
    }
    else if (value == 13)
    {
        number = "K";
    }
    else if (value == 12)
    {
        number = "Q";
    }
    else if (value == 11)
    {
        number = "J";
    }
    else
    {
        number = to_string(value);
    }
    return number;
}

bool findCard(vector<string> deck, string card)
{
    bool card_found = false;
    for (auto this_card : deck)
    {
        if (this_card == card)
        {
            card_found = true;
            break;
        }
    }
    return card_found;
}

vector<string> getHighestInSuit(vector<string> deck, string suit)
{
    int max = 0;
    int person = -1;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "")
        {
            int value = getCardValue(deck[i]);
            if (getSuit(deck[i]) == suit && value > max)
            {
                max = value;
                person = i;
            }
        }
    }
    return {suit + getValueCard(max), to_string(person)};
}

string getLowestInSuit(vector<string> deck, string suit)
{
    int min = 15;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "")
        {
            int value = getCardValue(deck[i]);
            if (getSuit(deck[i]) == suit && value < min)
            {
                min = value;
            }
        }
    }
    return suit + getValueCard(min);
}

bool hasSuit(vector<string> deck, string suit)
{
    bool has_suit = false;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "" && getSuit(deck[i]) == suit)
        {
            has_suit = true;
        }
    }
    return has_suit;
}

string getLowestCard(vector<string> deck)
{
    int min = 15;
    string suit;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "")
        {
            int value = getCardValue(deck[i]);
            string this_suit = getSuit(deck[i]);
            if (value < min)
            {
                min = value;
                suit = this_suit;
            }
        }
    }
    return suit + getValueCard(min);
}

string getHighestCard(vector<string> deck)
{
    int max = 0;
    string suit;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "")
        {
            int value = getCardValue(deck[i]);
            string this_suit = getSuit(deck[i]);
            if (value > max)
            {
                max = value;
                suit = this_suit;
            }
        }
    }
    return suit + getValueCard(max);
}

string getLowestCardNotInTrump(vector<string> deck, string trump)
{
    int min = 15;
    string suit;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "" && getSuit(deck[i]) != trump)
        {
            int value = getCardValue(deck[i]);
            string this_suit = getSuit(deck[i]);
            if (value < min)
            {
                min = value;
                suit = this_suit;
            }
        }
    }
    if (min == 15)
    {
        return getLowestCard(deck);
    }
    return suit + getValueCard(min);
}

string getHighestCardNotInTrump(vector<string> deck, string trump)
{
    int max = 0;
    string suit;
    for (int i = 0; i < deck.size(); i++)
    {
        if (deck[i] != "" && getSuit(deck[i]) != trump)
        {
            int value = getCardValue(deck[i]);
            string this_suit = getSuit(deck[i]);
            if (value > max)
            {
                max = value;
                suit = this_suit;
            }
        }
    }
    if (max == 0)
    {
        return getHighestCard(deck);
    }
    return suit + getValueCard(max);
}

void roundInfo(Round round, int i)
{
    print("Round: ", "magenta", true, "");
    print(to_string(round.round), "cyan", "", "   ");
    print("Trump: ", "magenta", true, "");
    printSuit(round.trump);
    print("   Playing Suit: ", "magenta", true, "");
    if (i != 0)
    {
        printSuit(round.round_suit);
    }
    else
    {
        print("?", "cyan", "", "");
    }
    print();
    print("Team 1 Sets (Your Team): ", "magenta", true, "");
    print(to_string(round.team1), "cyan", "", "   ");
    print("Team 2 Sets: ", "magenta", true, "");
    print(to_string(round.team2), "cyan", "");
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
        if (suit == "S")
        {
            s += value;
            if (s > max_value)
            {
                max_suit = "S";
                max_value = s;
            }
        }
        else if (suit == "H")
        {
            h += value;
            if (h > max_value)
            {
                max_suit = "H";
                max_value = h;
            }
        }
        else if (suit == "C")
        {
            c += value;
            if (c > max_value)
            {
                max_suit = "C";
                max_value = c;
            }
        }
        else if (suit == "D")
        {
            d += value;
            if (d > max_value)
            {
                max_suit = "D";
                max_value = d;
            }
        }
    }
    return max_suit;
}

string getTrump(int winner)
{
    string trump;
    if (winner == 0)
    {
        printCards(user_deck, 5);
        print("Please choose the trump", "magenta", true);
        print("S: Spades (♠)");
        print("H: Hearts (♥)", "red");
        print("C: Clubs (♣)");
        print("D: Diamonds (♦)", "red");
        cin >> trump;
        while (trump != "S" && trump != "H" && trump != "C" && trump != "D")
        {
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

    return trump;
}

vector<string> getHighestInRound(string trump, string suit, vector<string> deck)
{
    bool has_trump = hasSuit(deck, trump);
    bool has_suit = hasSuit(deck, suit);
    string card = "0H";
    string person = "-1";

    if (has_trump)
    {
        card = getHighestInSuit(deck, trump)[0];
        person = getHighestInSuit(deck, trump)[1];
        return {card, person};
    }
    else if (has_suit)
    {
        card = getHighestInSuit(deck, suit)[0];
        person = getHighestInSuit(deck, suit)[1];
        return {card, person};
    }

    return {card, person};
}

int getPartner(int turn)
{
    if (turn == 0)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

bool higherThan(string card1, string card2)
{
    if (getCardValue(card1) > getCardValue(card2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string getNextHighTrump(vector<string> deck, vector<string> round_cards, string trump)
{
    int max = getCardValue(getHighestInSuit(round_cards, trump)[0]);
    for (int i = 0; i < deck.size(); i++)
    {
        int value = getCardValue(deck[i]);
        string suit = getSuit(deck[i]);
        if (suit == trump && value > max)
        {
            max = value;
            return suit + getValueCard(max);
        }
    }
    return "";
}

string chooseCard(vector<string> deck, vector<string> round_cards, int turn, string trump, string suit)
{
    bool has_trump = hasSuit(round_cards, trump);
    bool has_suit = hasSuit(round_cards, suit);
    string card;
    string highest;
    int highest_player;
    if (has_trump)
    {
        highest = getHighestInSuit(round_cards, trump)[0];
        highest_player = stoi(getHighestInSuit(round_cards, trump)[1]);

        if (trump == suit)
        {
            if (hasSuit(deck, trump))
            {
                if (highest_player == getPartner(turn))
                {
                    card = getLowestInSuit(deck, trump);
                }
                else
                {
                    card = getHighestInSuit(deck, trump)[0];
                }
            }
            else
            {
                card = getLowestCard(deck);
            }
        }
        else
        {
            if (hasSuit(deck, suit))
            {
                card = getLowestInSuit(deck, suit);
            }
            else if (hasSuit(deck, trump))
            {
                if (highest_player == getPartner(turn))
                {
                    card = getLowestCardNotInTrump(deck, trump);
                }
                else
                {
                    string nextHigh = getNextHighTrump(deck, round_cards, trump);
                    if (nextHigh == "")
                    {
                        card = getLowestCardNotInTrump(deck, trump);
                    }
                    else
                    {
                        card = nextHigh;
                    }
                }
            }
            else
            {
                card = getLowestCard(deck);
            }
        }
    }
    else if (has_suit)
    {
        highest = getHighestInSuit(round_cards, suit)[0];
        highest_player = stoi(getHighestInSuit(round_cards, suit)[1]);
        if (hasSuit(deck, suit))
        {
            if (highest_player == getPartner(turn))
            {
                card = getLowestInSuit(deck, suit);
            }
            else
            {
                if (higherThan(getHighestInSuit(deck, suit)[0], highest))
                {
                    card = getHighestInSuit(deck, suit)[0];
                }
                else
                {
                    card = getLowestInSuit(deck, suit);
                }
            }
        }
        else if (hasSuit(deck, trump))
        {
            if (highest_player == getPartner(turn))
            {
                card = getLowestCardNotInTrump(deck, trump);
            }
            else
            {
                card = getLowestInSuit(deck, trump);
            }
        }
        else
        {
            card = getLowestCard(deck);
        }
    }
    else
    {
        card = getHighestCardNotInTrump(deck, trump);
    }

    return card;
}

bool checkUserCard(vector<string> deck, string card, string trump, string suit) {
    if (!findCard(deck, card)) {
        print("Invalid Card (Card not in hand)", "red", true);
        return false;
    }
    else if (hasSuit(deck, suit))
    {
        if (getSuit(card) != suit) {
            print("Invalid Card (Suit already present)", "red", true);
            return false;
        }
    }
    return true;
}
// TRUMP TOOLS END

void startRounds(Round &round)
{
    int turn = round.winner;
    vector<string> round_cards(4, "");
    string card;
    for (int i = 0; i < 4; i++)
    {
        string highest_card = getHighestInRound(round.trump, round.round_suit, round_cards)[0];
        int highest_player = stoi(getHighestInRound(round.trump, round.round_suit, round_cards)[1]);
        if (turn == 0)
        {
            roundInfo(round, i);
            printCards(user_deck, 7, true);
            print("Throw Card: ", "magenta", true, "");
            cin >> card;
            while (!checkUserCard(user_deck, card, round.trump, round.round_suit))
            {
                print("Throw Card: ", "magenta", true, "");
                cin >> card;
            }
            round_cards[0] = card;
        }
        else if (turn == 1)
        {
            printCards(comp1);
            round_cards[1] = chooseCard(comp1, round_cards, turn, round.trump, round.round_suit);
            print(round_cards[1]);
        }
        else if (turn == 2)
        {
            printCards(comp2);
            round_cards[2] = chooseCard(comp2, round_cards, turn, round.trump, round.round_suit);
            print(round_cards[2]);
        }
        else if (turn == 3)
        {
            printCards(comp3);
            round_cards[3] = chooseCard(comp3, round_cards, turn, round.trump, round.round_suit);
            print(round_cards[3]);
        }
        if (i == 0)
        {
            round.round_suit = getSuit(round_cards[turn]);
        }
        else if (i == 3)
        {
            round.winner = stoi(getHighestInRound(round.trump, round.round_suit, round_cards)[1]);
            if (round.winner == 0 || round.winner == 2)
            {
                round.team1++;
            }
            else
            {
                round.team2++;
            }
        }

        turn++;
        if (turn == 4)
        {
            turn = 0;
        }
    }
}

void startGame(int winner)
{
    vector<string> deck = newDeck();
    string trump;
    user_deck = drawCard(deck, 5);
    comp1 = drawCard(deck, 5);
    comp2 = drawCard(deck, 5);
    comp3 = drawCard(deck, 5);
    trump = getTrump(winner);
    print("The trump is ", "magenta", true, "");
    printSuit(trump);
    print();

    for (int i = 0; i < 8; i++)
    {
        user_deck.push_back(drawCard(deck, 1)[0]);
        comp1.push_back(drawCard(deck, 1)[0]);
        comp2.push_back(drawCard(deck, 1)[0]);
        comp3.push_back(drawCard(deck, 1)[0]);
    }

    Round round;
    round.round = 0;
    round.round_suit = "?";
    round.team1 = 0;
    round.team2 = 0;
    round.trump = trump;
    round.winner = winner;

    while (round.round != 13 && round.team1 != 7 && round.team2 != 7)
    {
        startRounds(round);
        round.round++;
    }
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