#ifndef PRINT_TEXT_H
#define PRINT_TEXT_H

#include <string>
#include <vector>
using namespace std;

//functions
void print(string text = "", string color = "default", bool bold = false, string end = "\n");
void print_suit(string suit);
void print_main_heading();
void print_main_ending();
void print_game_heading(string game);
void print_user_details(string user, string game, int total = 0, int played = 0, int score = 0);
void print_cards(vector<string> deck, int n = 5);

#endif