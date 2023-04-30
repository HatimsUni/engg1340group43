#include <iostream>
#include <string>
#include "../include/bigtwo.h"
#include "../include/blackjack.h"
#include "../include/higher_lower.h"
#include "../include/trump.h"
#include "../include/old_maid.h"
#include "../include/card_dealer.h"
#include "../include/file_handler.h"
using namespace std;

void choose_bigtwo(){
    string reply;
    play_bigtwo();
    while (true){
        cout << "Would you like to play again? (y/n)" << endl;
        getline(cin, reply);
        if (reply == "y"){
            choose_bigtwo();
            return;
        } else if  (reply == "n"){
            cout << "Thank you. Returning to the game chooser screen" << endl;
            return;
        } else {
            cout << "Wrong input. Please input your answer again" << endl;
        }
    }
}

void choose_blackjack(){
    string reply;
    play_blackjack();
    while (true){
        cout << "Would you like to play again? (y/n)" << endl;
        getline(cin, reply);
        if (reply == "y"){
            choose_blackjack();
            return;
        } else if  (reply == "n"){
            cout << "Thank you. Returning to the game chooser screen" << endl;
            return;
        } else {
            cout << "Wrong input. Please input your answer again" << endl;
        }
    }
}

void choose_higer_lower(){
    string reply;
    play_higher_lower();
    while (true){
        cout << "Would you like to play again? (y/n)" << endl;
        getline(cin, reply);
        if (reply == "y"){
            choose_higer_lower();
            return;
        } else if  (reply == "n"){
            cout << "Thank you. Returning to the game chooser screen" << endl;
            return;
        } else {
            cout << "Wrong input. Please input your answer again" << endl;
        }
    }
}

void choose_trump(){
    string reply;
    play_trump();
    while (true){
        cout << "Would you like to play again? (y/n)" << endl;
        getline(cin, reply);
        if (reply == "y"){
            choose_trump();
            return;
        } else if  (reply == "n"){
            cout << "Thank you. Returning to the game chooser screen" << endl;
            return;
        } else {
            cout << "Wrong input. Please input your answer again" << endl;
        }
    }
}


void choose_old_maid(){
    string reply;
    play_old_maid();
    while (true){
        cout << "Would you like to play again? (y/n)" << endl;
        getline(cin, reply);
        if (reply == "y"){
            choose_old_maid();
            return;
        } else if  (reply == "n"){
            cout << "Thank you. Returning to the game chooser screen" << endl;
            return;
        } else {
            cout << "Wrong input. Please input your answer again" << endl;
        }
    }
}

void choose_game(){
    string input;
    int number;
    while(true){
        cout << "We have many card games, please pick one by entering the number (0-5)" << endl;
        cout << "1 Big Two" << endl;
        cout << "2 Blackjack" << endl;
        cout << "3 Higer Lower" << endl;
        cout << "4 Trump" << endl;
        cout << "5 Old Maid" << endl;
        cout << "0 Exit" << endl;
        getline(cin, input);
        
        if (input.size() == 1 && input.find_first_not_of("012345") == string::npos){
            number = stoi(input);
            if (number == 0){
                cout << "Thank you for playing" << endl;
                return;
            } else if (number == 1){
                choose_bigtwo();
            } else if (number == 2){
                choose_blackjack();
            } else if (number == 3){
                choose_higer_lower();
            } else if (number == 4){
                choose_trump();
            } else if (number == 5){
                choose_old_maid();
            }
        } else {
            cout << "Invalid input, please reenter a number from 0-5" << endl;
        }
    }
}



int main() {
    cout << "Welcome to Cardingo (This is the welcome message still work in progress)" << endl;
    choose_game();
    cout << "Thank you for playing";
    return 0;
}