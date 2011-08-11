#ifndef YATZYIO_H
#define YATZYIO_H

#include "Die.h"
#include "Score.h"
#include "HighScore.h"
#include <string>
#include <vector>

/**
 * A class that handles various inputs and outputs for Yatzy.
 */
class YatzyIO
{
 public:
 /**
   * Prints a string
   *
   * @param s the string to be printed
   */
  void print(std::string s);
  /**
   * Prints an integer
   *
   * @param i the integer to print
   */
  void print(int i);
  /**
   * Draws a single dice in stdout
   *
   * @param die the dice to be drawn.
   */ 
  void drawDice(Die die);
  /**
   * Draws mulitple dices in stdout
   *
   * @param dices the vector of dices that to be drawn
   */
  void drawDices(std::vector<Die> dices);
  /**
   * Prints a players score
   *
   * @param score to be printed
   */
  void printScore(Score score);
  /**
   * Reads a string from stdin
   *
   * @return string the data input to stdin
   */
  std::string readString();
  /**
   * Reads an integer from stdin
   *
   * Will query the user to retry if input is not an integer
   *
   * @return int the integer input do stdin
   */
  int readInt();
  /**
   * Prints muliple integerers on a row
   *
   * @param ints a vector of integers that will be printed
   */
  void printIntVector(std::vector<int> ints);
  /**
   * Prints the a highscore
   *
   * @param highScore the highscore to be printed
   */
  void printHighScore(HighScore highScore);
};

#endif
