# CARD-INGO

Course Information\
Course Code: ENGG1340\
Course Title: Computer Programming II\
Group: 43

## Team Members
QUETTAWALA Hatim (3036094849)\
SUHANDJAJA Alexander Gaudi (3036029674)\
SUTANTO Winiera (3035964671)\
MANATUNGE Aishani Induja (3035962386)\
YOON Hyunseo (3036029844)

## Introduction
CARD-INGO is a fun and exciting collection of five different card games. The games included are:

Blackjack\
Trump\
Old Maid\
Higher Lower\
Crazy Eights

The name CARD-INGO is inspired by the popular game BINGO. CARD-INGO is sure to provide hours of entertainment and challenge. So, gather your friends and family, and get ready to play these classic card games in a whole new way with CARD-INGO!

## Game Rules
These are game rules for each of the five card games.

All games are played with only one human player and the rest being computer players.

Blackjack:
* Blackjack is a card game played with a standard deck of 52 cards.
* The game can be played with 2-6 players. 
* The cards have a rank of 2-10, with face cards (J/Q/K) worth 10 points each and an Ace worth 1 or 11 points.
* At the start of the game, each player is dealt 2 cards.
* The goal of the game is to have a score of 21, or as close to 21 as possible without going over.
* If a player's score is below 21, they can choose to "hit," which means drawing another card from the deck.
* If a player's score exceeds 21, they lose the game. If a player's score is exactly 21, they win the game. Otherwise, the game continues with the players who have not yet lost or won.
* If a player is satisfied with their score, they can choose to "stand," which means they will not draw any more cards.
* The game ends when all players have either lost, won, or chosen to stand.
* The winners are the players with the highest scores.
* Winners earn points equal to the number of players in the game.

Trump:
- Goal: One team to wins 7 sets first.
- Cards ranked A-K-Q-J-10-9-8-7-6-5-4-3-2, A highest and 2 lowest.
- Player to choose trump decided by toss.
- Four players, each dealt 5 cards initially.
- Winner of toss chooses trump suit from their cards.
- Then, 4 cards dealt to each player, then again 4, resulting in 13 cards each.
- You and Computer 2 vs. Computer 1 and Computer 3.
- Each round, players throw 1 card from same suit as winner of toss or last round.
- Team with highest-ranking card wins the round.
- If no same-suit card, waste another suit or play trump card.
- If multiple trump cards, highest-ranking card wins.
- First team to win 7 sets wins the game.

Old Maid:
* Old Maid is a classic card game where the goal of the game is to remove all pairs from your hand while not being left with the queen of spades
* A pair is defined of cards with the same value and same color (clubs with spades and diamonds with hearts)
* In Cardingo you will play against a computer
* At the start of the game each player draws 26 cards
* Whoever starts with the queen of clubs throws it away and the opponent starts first
* Each turn the current player will take a card from the opponent's hand and if it results in a pair with a card from their hand, they throw away the pair
* The players alternate turns until one player is left with the queen of spades and the other player has no card
* The winner is the player with no cards left
* The loser is the player with the queen of spades left

Higher Lower:
- Higher Lower is a one-person game, in which the player has to guess if the current card drawed is either higher, lower, or similar to the next card with the least amount of lives lost as possible
- At the start of the game the player gets 5 lives and a card from a deck is drawed in the player's hand
- The player will try to guess if the value of the card in hand is higher, lower, or same (which will be considered similar given that the suits of the cards might be different) to the next card drawed
- The next card is revealed and if the player guessed wrong, then the player loses one life
- The next card becomes the current card in the player's hand, and another card is drawed as the next card
- The player repeats guessing until either the player guessed 10 cards correctly or the player runs out of lives
- At the end of the game, the amount of lives left becomes the score point
- If the player has no lives, the player loses and wins no score points

Crazy Eights:
- The basic gameplay of Crazy Eights involves trying to get rid of your cards by matching either the rank or suit of the current card
- The objective of the game is to be the first one to discard all your cards
- At the start of the game each player are dealt 7 cards
- Place the remaining cards face down on the table forming the draw pile and turn the top card over and place it beside the draw pile to start the discard pile
- The first player must play a card that matches the suit or rank of the card on the discard pile (e.g. current card is a 7 of hearts, hence player can play any other 7 or any heart card)
- If a player cannot play a card, they must keep drawing cards from the draw pile until they found a card they can play and play it
- The game's namesake card is the "eight" and when played, the player gets to choose which suit will be played next
- The first player to get rid of all their cards wins the game
- If the draw pile run out of cards, then the player ties and the game is over


## Features Implemented and Coding Requirements
We implemented the following features and coding requirements to support the game:

1. Generation of random game sets or events: In this game we randomly generated a deck of cards.
2. Data structures for storing game status: We utilized vectors and structures to store the deck and hands.
3. Dynamic memory management: We utilized dynamic memory management mainly through the use of pointers.
4. File input/output (e.g., for loading/saving game status): We created a C++ program with the intended purpose of storing the username, total games played, the score for each game, and the total sums of scores in a txt file. This program also has the ability to print a person's score and update that score.
5. Program codes in multiple files: For each game, we separated the C++ programs into multiple files. Through the use of header files and makefile, we were able to combine all of the files into one executable program.

## Non-Standard C/C++ Libraries
We did not use any non-standard C/C++ libraries.

##  Compilation and Execution Instructions (How to Play "CARD-INGO")
To play "CARD-INGO," follow these steps:

1. Open the command terminal.
2. Go to the directory in which you want to create the game files.
3. Clone the project using git clone https://github.com/HatimsUni/engg1340group43.git in that folder.
4. Run cd engg1340group43/cardingo.
5. Run make.
6. Run ./bin/play to play the game.
7. Once you are done playing the game, run make clean to delete clean the directory.
