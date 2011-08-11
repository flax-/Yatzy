#include "HighScore.h"
#include <iostream>
#include <fstream>
#include <sstream>

HighScore::HighScore()
{
  int score;
  std::string line;
  std::ifstream file("highscore.txt");

  for (int i = 0; i < 3; i++)
    {
      getline(file, line);
      names.insert(names.end(), line);

      getline(file, line);
      std::stringstream s(line);
      s >> score;
      scores.insert(scores.end(), score);
    }

  file.close();
}

/**
   * Gets the names on the highscore
   *
   * @return vector of strings, the names on the highscore
   */
std::vector<std::string> HighScore::getNames()
{
  return names;
}

/**
   * Gets the scores on the highscore
   *
   * @return vector of integers, the scores on the highscore
   */
std::vector<int> HighScore::getScores()
{
  return scores;
}

/**
   * Writes the highscore to "highscore.txt" in plain text
   */
void HighScore::writeScore()
{
  std::ofstream file("highscore.txt");
  for (int i = 0; i < 3; i++)
    {
      file << names[i];
      file << "\n";
      file << scores[i];
      file << "\n";
    }
  file.close();
}

/**
   * Adds an entry to the highscore
   *
   * @param name of the player
   * @param score to be inserted
   * @param index where to insert the row
   */
void HighScore::insertPost(std::string name, int score, int index)
  {
    scores.insert(scores.begin() + index, score);
    names.insert(names.begin() + index, name);
  }

/**
   * Adds a score to the highscore
   *
   * @param index the position on the highscore
   * @param score the score to be inserted
   */
void HighScore::insertScore(int index, int score)
{
  scores.insert(scores.begin() + index, score);
}

/**
   * Adds a name to the highscore
   *
   * @param index the position on the highscore
   * @param name the name to be inserted
   */
void HighScore::insertName(int index, std::string name)
{
  names.insert(names.begin() + index, name);
}


