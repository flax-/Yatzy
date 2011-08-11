#ifndef YATZY_H
#define YATZY_H

#include "YatzyIO.h"
#include "YatzyRules.h"
#include <vector>
#include "Die.h"

/**
 * Class that handles the main part of the 
 * game mechanics.
 */
class Yatzy
{
 public:
  Yatzy();
  /**
   * Starts the game of yatzy
   *
   * Only function that will be used from outside the class
   */
  void play();
 private:
 /**
   * Queries the player to (R)oll of (Q)uit
   *
   * @return bool True if the player wants to quit and false if the player wants to roll
   */
  bool quit();
  /**
   * Rolls the players hand
   */
  void rollHand();
  /**
   * Gets input from the player and rerolls chosen dices
   */
  void rollChoice();
  /**
   * Placed the current players hand on the row of choice
   */
  void placeHand();
  /**
   * Checks if any of the players made the highscore and queries them for their names if so.
   */
  void checkHighScores();
  void writeHighScores();
  std::string getHighScoreName(int player);

  YatzyIO yatzyIO;
  YatzyRules yatzyRules;
  HighScore highScore;

  int player;
  int players;
  std::vector<Die> dices;
  std::vector<Score> scores;
};

#endif
