#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

//functions
#include <string>
#include <vector>
using namespace std;

void printData(string username);
void updateFile(string username, int games_played = 0, int crazyeights = 0, int blackjack = 0, int higher_lower = 0, int old_maid = 0, int trump = 0, int score = 0);
vector <string> getRules(string game_name);

#endif