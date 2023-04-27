#include <iostream>
#include "../include/bigtwo.h"
#include "../include/blackjack.h"
#include "../include/higher_lower.h"
#include "../include/trump.h"
#include "../include/war.h"
#include "../include/card_dealer.h"
#include "../include/file_handler.h"
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a == 1) {play_bigtwo();}
    if (a == 2) {play_blackjack();}
    if (a == 3) {play_higher_lower();}
    if (a == 4) {play_trump();}
    if (a == 5) {play_war();}
    if (a == 6) {play_file_handler();}
    if (a == 7) {play_card_dealer();}
}