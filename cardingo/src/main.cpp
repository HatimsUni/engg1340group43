#include <iostream>
#include "../include/bigtwo.h"
#include "../include/blackjack.h"
#include "../include/higher_lower.h"
#include "../include/trump.h"
#include "../include/war.h"
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a == 1) {play_bigtwo();}
    if (a == 2) {play_blackjack();}
}