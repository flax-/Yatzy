#include "Score.h"
#include <sstream>

Score::Score()
{
  scores.resize(15);
  scoresSet.resize(15);
  for (int i = 0; i < 15; i++)
    {
      scores[i] = 0;
      scoresSet[i] = false;
    }
}

void Score::clearScore()
{
  for (int i = 0; i < 15; i++)
    {
      scores[i] = 0;
      scoresSet[i] = false;
    }
}

/**
   * Adds a score
   *
   * @param row the row on which the score should be placed
   * @param score the score
   */
void Score::addScore(int row, int score)
{  
  scores[row] = score;
  scoresSet[row] = true;
}

/**
   * Returns the score of a given row
   *
   * @param row the row which will be returned
   */
std::string Score::getScore(int row)
{
  if (!scoresSet[row])
    {
      return "";
    }
  std::ostringstream s;
  s << scores[row];
  return s.str();
}

/**
   * Checks whether a score has been set on a row
   *
   * @param row the row to be checked
   * @return bool true if the row already has been set, false if the row is blank
   */
bool Score::scoreSet(int row)
{
  return scoresSet[row];
}

/**
   * Calculates the sum of the score on row 1-6
   *
   * @return int the sum of the scores on row 1-6
   */
int Score::getTopSum()
{
  int result = 0;
  for (int i = 0; i < 6; i++)
    {
      result += scores[i];
    }
  return result;
}

/**
   * Calculates whether the player has earned a bonus for the top score
   *
   * If the sum is above 62 then the player will get a bonus of 25 
   */  
int Score::getTopBonus()
{
  if (getTopSum() > 62)
    {
      return 25;
    }
  return 0;
}

/**
   * Calculates the total score
   *
   * @return int the total sum.
   */
int Score::getSum()
{
  int result = 0;
  for (int i = 0; i < 15; i++)
    {
      result += scores[i];
    }
  result += getTopBonus();
  return result;
}
