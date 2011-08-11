#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include <string>

/**
 * Class that handles one players score. 
 */
class Score
{
 public:
  Score();
  /**
   * Adds a score
   *
   * @param row the row on which the score should be placed
   * @param score the score
   */
  void addScore(int row, int score);
  void clearScore();
  /**
   * Returns the score of a given row
   *
   * @param row the row which will be returned
   */
  std::string getScore(int row);
  /**
   * Checks whether a score has been set on a row
   *
   * @param row the row to be checked
   * @return bool true if the row already has been set, false if the row is blank
   */
  bool scoreSet(int row);
  /**
   * Calculates the sum of the score on row 1-6
   *
   * @return int the sum of the scores on row 1-6
   */
  int getTopSum();
  /**
   * Calculates whether the player has earned a bonus for the top score
   *
   * If the sum is above 62 then the player will get a bonus of 25 
   */  
  int getTopBonus();
  /**
   * Calculates the total score
   *
   * @return int the total sum.
   */
  int getSum();
 private:
  std::vector<int> scores;
  std::vector<bool> scoresSet;
};

#endif
