#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>

/**
 * Class that handles the persistent highscore. Reads and writes to "highscore.txt"
 */
class HighScore
{
 public:
  HighScore();
  /**
   * Gets the names on the highscore
   *
   * @return vector of strings, the names on the highscore
   */
  std::vector<std::string> getNames();
  /**
   * Gets the scores on the highscore
   *
   * @return vector of integers, the scores on the highscore
   */
  std::vector<int> getScores();
  /**
   * Adds an entry to the highscore
   *
   * @param name of the player
   * @param score to be inserted
   * @param index where to insert the row
   */
  void insertPost(std::string name, int score, int index);
  /**
   * Adds a score to the highscore
   *
   * @param index the position on the highscore
   * @param score the score to be inserted
   */
  void insertScore(int index, int score);
  /**
   * Adds a name to the highscore
   *
   * @param index the position on the highscore
   * @param name the name to be inserted
   */
  void insertName(int index, std::string name);
  /**
   * Writes the highscore to "highscore.txt" in plain text
   */
  void writeScore();
 private:
  std::vector<std::string> names;
  std::vector<int> scores;
};

#endif
