#include <iostream>
#include <vector>
#include <cstring>
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


int playHigherLower() {
    startHigherLower();
    return game_score;
}

vector<string> getCards() {
    vector<string> deck = newDeck(true);
    return drawCard(deck, 10);
}

void startHigherLower() {
    vector<string> answer_cards = getCards();
    continueHigherLower(answer_cards);
} 

void continueHigherLower(vector<string> answer_cards) {
    string guess;
    string answer;

    for (int i = 0; i <= answer_cards.size() - 1; i++) {
        string current_card = answer_cards[i];
        cout << "Current card: " << endl;
        cout << current_card << endl;
        cout << "Input your guess of how the current card compares to the next card (Higher, Lower, Similar): ";
        cin >> guess;

        if (guess == "Higher" || guess == "Lower" || guess == "Similar") {
            continue;
        } else {
            cout << "Please input your guess correctly (Higher / Lower / Similar): " << endl;
            cin >> guess;
        }

        string next_card = answer_cards[i+1];
        cout << next_card << endl;

        answer = compareCards(current_card, next_card);

        if (answer == guess) {
            cout << "Congratulation! Your guess is correct!" << endl;
        } else {
            cout << "You are wrong. The correct answer is: " << answer << endl;
            cout << "One life will be lost." << endl;
            life_count--;
            cout << "Total life left: " << life_count << endl;
        }

        if (life_count == 0) {
            cout << "You have lost all your lives." << endl;
            break;
        }
    }
    
    higherLowerWinner();
}

int getRank(string val) {
    string newval = val.substr(1, val.length() - 1);
    vector<string> vect_ranks = { "A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2" };
    int rank;
    for (int i = 0; i <= vect_ranks.size(); i++) {
        if (newval == vect_ranks[i]) {
            rank = i;
        }
    }
    rank = 13 - rank;
    return rank;
}

string compareCards(string current_card, string next_card) {
    string answer;

    string current_value = getValue(current_card);
    int current_rank = getRank(current_card);
    string next_value = getValue(next_card);
    int next_rank = getRank(next_card);

    if(next_value == current_value) {
        answer = "Similar";
    } else {
        if (current_rank > next_rank) {
            answer = "Higher";
        } else {
            answer = "Lower";
        }
    }

    return answer;
}

void higherLowerWinner() {
    if (life_count == 5) {
        game_score = 5;
        cout << "Congratulations! You are the winner!" << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    } else if (life_count == 4) {
        game_score = 4;
        cout << "Congratulations! You are the winner!" << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    } else if (life_count == 3) {
        game_score = 3;
        cout << "Congratulations! You are the winner!" << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    } else if (life_count == 2) {
        game_score = 2;
        cout << "Congratulations! You are the winner!" << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    } else if (life_count == 1) {
        game_score = 1;
        cout << "Congratulations! You are the winner!" << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    } else {
        game_score = 0;
        cout << "Try again.. You have lost due to incorrect guesses..." << endl;
        cout << "Your score: " << game_score << endl;
        cout << "Thank you for playing!";
    }
}