#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
using namespace std;

void shuffle_hand(vector<Card>& hand){

}

void remove_pairs(vector<Card>& discard_pile, vector<Card>& hand, string current_player){

}

void print_cards(vector<Card>& hand){
    for(int i = 0; i < hand.size(); i++){
        cout << hand[i]->suit << " " << hand[i]->value << endl;
    }
}

void human_turn(vector<Card>& discard_pile, vector<Card>& human_hand, vector<Card>& robot_hand){
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
        robot_turn(discard_pile, human_hand, robot_hand);
    }
}

void robot_turn(vector<Card>& discard_pile, vector<Card>& human_hand, vector<Card>& robot_hand){
    int choice = rand() % human_hand.size() + 1;
    cout << "Its your opponents turn" << endl;
    cout << "You have" << human_hand.size() << " cards" << endl;
    cout << "The robot picked card number " << choice << endl;
    cout << "The robot took the " << human_hand[choice - 1]->Suit << human_hand[choice - 1]-> value << endl;
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
        human_turn(discard_pile, human_hand, robot_hand);
    }
}


void play_old_maid(vector<Card>& discard_pile, vector<Card>& human_hand, vector<Card>& robot_hand, string current_player){
    remove_pairs(discard_pile, human_hand, current_player);
    remove_pairs(discard_pile, robot_hand, current_player);
    if(current_player == "human"){
        human_turn(discard_pile, human_hand, robot_hand);
    } else if(current_player == "robot"){
        robot_turn(discard_pile, human_hand, robot_hand);
    }
}

void start_old_maid(){
    vector<Card> discard_pile;
    vector<Card> human_hand;
    vector<Card> robot_hand;
    string current_player;
    vector<Card>::iterator queen_finder = human_hand.begin();

    while(queen_finder != human_hand.end(){
        if(queen_finder->Suit == "Clubs" && queen_finder->value == "Q"){
            queen_finder = human_hand.erase(queen_finder);
        } else{
            ++queen_finder;
        }
    })

    vector<Card>::iterator queen_finder = robot_hand.begin();

    while(queen_finder != robot_hand.end(){
        if(queen_finder->Suit == "Clubs" && queen_finder->value == "Q"){
            queen_finder = robot_hand.erase(queen_finder);
        } else{
            ++queen_finder;
        }
    })

    if(human_hand.size() = 25){
        current_player = "robot"
    } else if(robot_hand.size() = 25){
        current_player = "human"
    }
    play_old_maid(discard_pile, human_hand, robot_hand, current_player);

}


void open_old_maid() {
    cout << "Here are the rules of old maid WIP" << endl;
}