#include <iostream>
#include "../include/blackjack.h"
using namespace std;

// Human class
class Human {
public:
    void handSetup(vector<string> &deck, int k);
    void printHand();
    bool isValidCard(string card, string &currentSuit, string &currentValue);
    bool isWinner();
    void pickSuit(string &currentSuit);
    void turn(vector<string> &deck, string &currentSuit, string &currentValue);

private:
    vector<string> hand;
    int handSize;
};

void Human::handSetup(vector<string> &deck, int k) {
    hand = drawCard(deck, k);
}
void Human::printHand() {
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << endl;
}
bool Human::isValidCard(string card, string &currentSuit, string &currentValue) {
    if (currentValue == "8" && getSuit(card) == currentSuit) {
        return true;
    } else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8") {
        return true;
    } else {
        return false;
    }
}
bool Human::isWinner() {
    if (hand.size() == 0) return true;
    else return false;
}
void Human::pickSuit(string &currentSuit) {
    
    int input;
    cout << "\t1:D\t2:C\t3:H\t4:S" << endl;
    cout << "pick a suit... ";
    
    bool isValidMove = false;
    while (!isValidMove) {
        cin >> input;
        if (1 <= input && input <= 4) {
            isValidMove = true;
        } else {
            cout << "\t1:D\t2:C\t3:H\t4:S" << endl;
            cout << "invalid move! pick a suit... "; 
        }
    }
    
    if (input == 1) currentSuit = "D";
    else if (input == 2) currentSuit = "C";
    else if (input == 3) currentSuit = "H";
    else if (input == 4) currentSuit = "S";
}
void Human::turn(vector<string> &deck, string &currentSuit, string &currentValue) {
    cout << "current card:" << endl;
    cout << currentSuit << currentValue << endl;
    
    cout << "your cards: " << endl;
    printHand();
    
    if (currentValue == "8") {
        cout << "pick any " << currentSuit << " card [Enter 1 to " << hand.size() << "] or draw a card [Enter 0]... ";
    }
    else if (hand.size() > 1) {
        cout << "pick a card [Enter 1 to " << hand.size() << "] or draw a card [Enter 0]... ";
    } else if (hand.size() == 1) {
        cout << "pick a card [Enter 1] or draw a card [Enter 0]... ";
    }
    
    // check if there are move available
    bool isMoveAvail = false;
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        if (isValidCard(*itr, currentSuit, currentValue)) {
            isMoveAvail = true;
            break;
        }
    }
    
    int input;
    cin >> input;
    
    bool isValidMove = false;
    while (!isValidMove) {
        if (isMoveAvail == true) {
            while (!(0 < input && input <= hand.size()) || !isValidCard(hand[input-1], currentSuit, currentValue)) {
                if (currentValue == "8") {
                    cout << "invalid move! pick a " << currentSuit << " card [Enter 1 to " << hand.size() << "]... ";
                }
                else if (hand.size() > 1) {
                    cout << "invalid move! pick a card [Enter 1 to " << hand.size() << "]... ";
                } else if (hand.size() == 1) {
                    cout << "invalid move! pick a card [Enter 1]... ";
                }
                cin >> input;
            }
            isValidMove = true;
        } else if (isMoveAvail == false) {
            while (input != 0) {
                cout << "invalid move! draw a card [Enter 0]... ";
                cin >> input;
            }
            isValidMove = true;
        }
    }
    
    if (input == 0) {
        vector<string> temp = drawCard(deck, 1);
        cout << "you draw.." << endl;
        cout << temp.front() << endl;
        
        while (!isValidCard(temp.front(), currentSuit, currentValue)) {
            hand.push_back(temp.front());
            
            cout << "draw card again [Enter 0]... ";
            cin >> input;
            while (input != 0) {
                cout << "invalid move! draw a card [Enter 0]... ";
                cin >> input;
            }
            temp = drawCard(deck, 1);
            cout << "you draw.." << endl;
            cout << temp.front() << endl;
        }
        currentSuit = getSuit(temp.front()); currentValue = getValue(temp.front());
    }
    else if (input > 0) {
        cout << "you pick.." << endl;
        cout << getSuit(hand[input-1]) << getValue(hand[input-1]) << endl;
        currentSuit = getSuit(hand[input-1]); currentValue = getValue(hand[input-1]);
        hand.erase(hand.begin() + input-1);
    }
    
    if (currentValue == "8") {
        pickSuit(currentSuit);
    }
    
}


// Robot class
class Robot {
public:
    void handSetup(vector<string> &deck, int k);
    void printHand();
    bool isValidCard(string card, string &currentSuit, string &currentValue);
    bool isWinner();
    void pickSuit(string &currentSuit);
    void turn(vector<string> &deck, string &currentSuit, string &currentValue);
    
private:
    vector<string> hand;
    int seri;
};

void Robot::handSetup(vector<string> &deck, int k) {
    hand = drawCard(deck, k);
}
void Robot::printHand() {
    vector<string>::iterator itr;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << endl;
}
bool Robot::isValidCard(string card, string &currentSuit, string &currentValue) {
    if (currentValue == "8" && getSuit(card) == currentSuit) {
        return true;
    } else if (getSuit(card) == currentSuit || getValue(card) == currentValue || getValue(card) == "8") {
        return true;
    } else {
        return false;
    }
}
bool Robot::isWinner() {
    if (hand.size() == 0) return true;
    else return false;
}
void Robot::pickSuit(string &currentSuit) {
    int input = (rand() % 4) + 1;
    if (input == 1) currentSuit = "D";
    else if (input == 2) currentSuit = "C";
    else if (input == 3) currentSuit = "H";
    else if (input == 4) currentSuit = "S";
}
void Robot::turn(vector<string> &deck, string &currentSuit, string &currentValue) {
    
    bool isMoveAvail = false;
    vector<int> validInput;
    vector<string>::iterator itr; int i = 1;
    for (itr = hand.begin(); itr != hand.end(); itr++) {
        if (isValidCard(*itr, currentSuit, currentValue)) {
            isMoveAvail = true;
            validInput.push_back(i);
        }
        i++;
    }
    if (!isMoveAvail) {
        validInput.push_back(0);
    }
    
    int random = rand() % validInput.size();
    int input = validInput[random];
    
    if (input == 0) {
        
        wait(750);
        vector<string> temp = drawCard(deck, 1);
        // cout << "robot draw a card [card left: " << hand.size() << "]" << endl;
        cout << "robot draw a card";
        
        while (!isValidCard(temp.front(), currentSuit, currentValue)) {
            wait(1250);
            hand.push_back(temp.front());
            cout << endl << "robot draw a card again";
            temp = drawCard(deck, 1);
        }
        cout << "[card left: " << hand.size() << "]" << endl;
        
        currentSuit = getSuit(temp.front()); 
        currentValue = getValue(temp.front());
        wait(350);
        
    } else if (input > 0) {
        
        wait(750);
        cout << "robot pick.." << endl;
        
        wait(1050);
        cout << getSuit(hand[input-1]) << getValue(hand[input-1]) << endl;
        
        currentSuit = getSuit(hand[input-1]); currentValue = getValue(hand[input-1]);
        hand.erase(hand.begin() + input-1);
        
        cout << "[card left: " << hand.size() << "]" << endl;
        wait(1350);
    }
    
    if (currentValue == "8") {
        pickSuit(currentSuit);
    }
}


// Deck class
class Deck {
public:
    void getStartingCard(vector<string> &deck, string &currentSuit, string &currentValue);
};

void Deck::getStartingCard(vector<string> &deck, string &currentSuit, string &currentValue) {
    vector<string>::iterator itr = deck.begin();
    while (getValue(*itr) == "8") {
        itr++;
    }
    currentValue = getValue(*itr);
    currentSuit = getSuit(*itr);
    deck.erase(itr);
}



void play_crazy_eights() {
    vector<string> deck = newDeck(true);
    string currentValue;
    string currentSuit;
    
    Human h; h.handSetup(deck, 7);
    Robot r; r.handSetup(deck, 7);
    Deck d; d.getStartingCard(deck, currentSuit, currentValue);
    
    while (true) {
        h.turn(deck, currentSuit, currentValue);
        if (h.isWinner()) {
            cout << "you win!" << endl;
            break;
        }
        
        r.turn(deck, currentSuit, currentValue);
        if (r.isWinner()) {
            cout << "you lose!" << endl;
            break;
        }
    }
    cout << "\t--- GAME OVER ---" << endl;
}