#ifndef PRINT_TEXT_H
#define PRINT_TEXT_H

#include <string>
#include <vector>
using namespace std;

//functions
void print(string text = "", string color = "default", bool bold = false, string end = "\n");
void printSuit(string suit);
void printMainHeading();
void printMainEnding();
void printGameHeading(string game);
void printUserDetails(string user, string game, int total = 0, int played = 0, int score = 0);
void printCard(string card, bool show = false);
void printCards(vector<string> deck, int n = 5, bool show = false);
void printRules(string game_name);

#endif