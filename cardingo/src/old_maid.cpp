#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <algorithm>
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
using namespace std;

struct Card {
    int rank;
    string suit;
    string value;
};

void shuffle_hand(vector<Card>& hand){
    random_device rd;
    mt19937 g(rd());
    shuffle(hand.begin(), hand.end(), g);
}

void remove_pairs(vector<Card>& discard_pile, vector<Card>& hand, string current_player){
    vector<Card> duplicate_hand;
    duplicate_hand = hand;
    vector<Card>:: iterator pair_finder = duplicate_hand.begin();
    for(int i = 0; i < hand.size(); ++i){
        while(pair_finder != duplicate_hand.end()){
            if((hand[i].suit == pair_finder->suit) && ((hand[i].value == "H" && pair_finder->value == "D") || (hand[i].value == "S" && pair_finder->value == "C"))){
                discard_pile.push_back(*pair_finder);
                duplicate_hand.erase(pair_finder);
                pair_finder = duplicate_hand.begin();
            } else if((hand[i].suit == pair_finder->suit) && ((hand[i].value == "D" && pair_finder->value == "H") || (hand[i].value == "C" && pair_finder->value == "S"))){
                discard_pile.push_back(*pair_finder);
                duplicate_hand.erase(pair_finder);
                pair_finder = duplicate_hand.begin();
            } else if ((hand[i].suit == pair_finder->suit) && (hand[i].value == pair_finder->value)){
                discard_pile.push_back(*pair_finder);
                duplicate_hand.erase(pair_finder);
                pair_finder = duplicate_hand.begin();
            } else{
                ++pair_finder;
            }
        }
    }
    hand = duplicate_hand;
    
}

void print_cards(vector<Card>& hand){
    for(int i = 0; i < hand.size(); i++){
        cout << hand[i].suit << " " << hand[i].value << endl;
    }
}


void play_turn(vector<Card>& discard_pile, vector<Card>& human_hand, vector<Card>& robot_hand, string current_player){
    if(current_player == "human"){
        int choice;
        cout << "Its your turn" << endl;
        cout << "The robot has" << robot_hand.size() << " cards";
        while (true){
            cout << "Please pick a card between 1 and " << robot_hand.size() << endl;
            cin >> choice;
            if((choice < 1) || (choice > robot_hand.size())){
                cout << "Invalid input. Please pick again";
            } else{
                break;
            }
        }
        human_hand.push_back(robot_hand[choice-1]);
        robot_hand.erase(robot_hand.begin() + (choice-1));
        remove_pairs(discard_pile, human_hand, "human");
        if(robot_hand.size()==0 && human_hand.size() == 1){
            cout << "The robot wins";
            return;
        } else if (robot_hand.size() == 1 && human_hand.size() == 0){
            cout << "The player wins";
            return;
        } else{
            shuffle_hand(human_hand);
            play_turn(discard_pile, human_hand, robot_hand, "robot");
        }
    } else if (current_player == "robot"){
        int choice = rand() % human_hand.size() + 1;
        cout << "Its your opponents turn" << endl;
        cout << "You have" << human_hand.size() << " cards" << endl;
        cout << "The robot picked card number " << choice << endl;
        cout << "The robot took the " << human_hand[choice - 1].suit << human_hand[choice - 1].value << endl;
        robot_hand.push_back(human_hand[choice-1]);
        human_hand.erase(human_hand.begin() + (choice-1));
        remove_pairs(discard_pile, robot_hand, "robot");
        if(robot_hand.size()==0 && human_hand.size() == 1){
            cout << "The robot wins";
            return;
        } else if (robot_hand.size() == 1 && human_hand.size() == 0){
            cout << "The player wins";
            return;
        } else{
            shuffle_hand(robot_hand);
            play_turn(discard_pile, human_hand, robot_hand, "human");
        }
    }
}

void play_old_maid(vector<Card>& discard_pile, vector<Card>& human_hand, vector<Card>& robot_hand, string current_player){
    remove_pairs(discard_pile, human_hand, current_player);
    remove_pairs(discard_pile, robot_hand, current_player);
    if(current_player == "human"){
        play_turn(discard_pile, human_hand, robot_hand, "human");
    } else if(current_player == "robot"){
        play_turn(discard_pile, human_hand, robot_hand, "robot");
    }
}

void start_old_maid(){
    vector<Card> deck = newDeck();
    vector<Card> discard_pile;
    vector<Card> human_hand(deck.begin(), deck.begin()+50);
    vector<Card> robot_hand(deck.end() - 50, deck.end());
    string current_player;
    vector<Card>::iterator queen_finder1 = human_hand.begin();

    while(queen_finder1 != human_hand.end()){
        if(queen_finder1->suit == "C" && queen_finder1->value == "Q"){
            queen_finder1 = human_hand.erase(queen_finder1);
        } else{
            ++queen_finder1;
        }
    }

    vector<Card>::iterator queen_finder2 = robot_hand.begin();

    while(queen_finder2 != robot_hand.end()){
        if(queen_finder2->suit == "C" && queen_finder2->value == "Q"){
            queen_finder2 = robot_hand.erase(queen_finder2);
        } else{
            ++queen_finder2;
        }
    }

    if(human_hand.size() == 25){
        current_player = "robot";
    } else if(robot_hand.size() == 25){
        current_player = "human";
    }
    play_old_maid(discard_pile, human_hand, robot_hand, current_player);

}


void open_old_maid() {
    cout << "Here are the rules of old maid WIP" << endl;
}