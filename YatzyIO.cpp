#include <iostream>
#include <sstream>
#include "YatzyIO.h"

using namespace std;

/**
   * Prints a players score
   *
   * @param score to be printed
   */
void YatzyIO::printScore(Score score)
{
  
  cout << "1  Ones            " << score.getScore(0) <<  endl;
  cout << "2  Twos            " << score.getScore(1) << endl;
  cout << "3  Threes          " << score.getScore(2) << endl;
  cout << "4  Fours           " << score.getScore(3) << endl;
  cout << "5  Fives           " << score.getScore(4) << endl;
  cout << "6  Sixes           " << score.getScore(5) << endl;
  cout << "   Sum             " << score.getTopSum() << endl;
  cout << "   Bonus           " << score.getTopBonus() << endl;
  cout << "7  Pair            " << score.getScore(6) << endl;
  cout << "8  Two Pairs       " << score.getScore(7) << endl;
  cout << "9  Three-of-a-kind " << score.getScore(8) << endl;
  cout << "10 Four-of-a-kind  " << score.getScore(9) << endl;
  cout << "11 Small Straight  " << score.getScore(10) << endl;
  cout << "12 Large Straight  " << score.getScore(11) << endl;
  cout << "13 Full House      " << score.getScore(12) << endl;
  cout << "14 Chance          " << score.getScore(13) << endl;
  cout << "15 Yatzy           " << score.getScore(14) << endl;
  cout << "   Sum             " << score.getSum() << endl;
}

/**
   * Reads a string from stdin
   *
   * @return string the data input to stdin
   */
string YatzyIO::readString()
{
  string s;
  cin >> s;
  cin.clear();
  cin.ignore(10000, '\n');
  return s;
}

/**
   * Reads an integer from stdin
   *
   * Will query the user to retry if input is not an integer
   *
   * @return int the integer input do stdin
   */
int YatzyIO::readInt()
{
  int i;
  while (!(cin >> i))
    {
      cout << "Expected an integer. Try again!" << endl;
      cin.clear();
      cin.ignore(10000, '\n');
    }
  return i;
}

/**
   * Prints a string
   *
   * @param s the string to be printed
   */
void YatzyIO::print(string s)
{
  cout << s;
}

/**
   * Prints an integer
   *
   * @param i the integer to print
   */
void YatzyIO::print(int i)
{
  cout << i;
}

/**
   * Draws mulitple dices in stdout
   *
   * @param dices the vector of dices that to be drawn
   */
void YatzyIO::drawDices(std::vector<Die> dices)
{
  string top = "";
  string middle = "";
  string bottom = "";
  string edge = "";

  for (int i = 0; i < dices.size(); i++)
    {
      switch (dices[i].getDieValue())
	{
	case 1:
	  top    += " |     |";
	  middle += " |  *  |";
	  bottom += " |     |";
	  break;
	case 2:
	  top    += " |*    |";
          middle += " |     |";
          bottom += " |    *|";
	  break;
	case 3:
	  top    += " |*    |";
          middle += " |  *  |";
          bottom += " |    *|";
	  break;
	case 4:
	  top    += " |*   *|";
          middle += " |     |";
          bottom += " |*   *|";
	  break;
	case 5:
	  top    += " |*   *|";
          middle += " |  *  |";
          bottom += " |*   *|";
	  break;
	case 6:
	  top    += " |*   *|";
          middle += " |*   *|";
          bottom += " |*   *|";
	  break;
	};
    };

  for (int i = 0; i < dices.size(); i++)
    {
      edge += " -------";
    }
  
  cout << edge << endl;
  cout << top << endl;
  cout << middle << endl;
  cout << bottom << endl;
  cout << edge << endl;
  }

/**
   * Draws a single dice in stdout
   *
   * @param die the dice to be drawn.
   */ 
void YatzyIO::drawDice(Die die)
{
  cout << "-------" << endl;

  switch (die.getDieValue()) 
    {
    case 1: 
      cout << "|     |" << endl;
      cout << "|  *  |" << endl;
      cout << "|     |" << endl;
      break;
    case 2:
      cout << "|*    |" << endl;
      cout << "|     |" << endl;
      cout << "|    *|" << endl;
      break;
    case 3:
      cout << "|*    |" << endl;
      cout << "|  *  |" << endl;
      cout << "|    *|" << endl;
      break;
    case 4:
      cout << "|*   *|" << endl;
      cout << "|     |" << endl;
      cout << "|*   *|" << endl;
      break;
    case 5:
      cout << "|*   *|" << endl;
      cout << "|  *  |" << endl;
      cout << "|*   *|" << endl;
      break;
    case 6:
      cout << "|*   *|" << endl;
      cout << "|*   *|" << endl;
      cout << "|*   *|" << endl;
    }

  cout << "-------" << endl; 
}

/**
   * Prints muliple integerers on a row
   *
   * @param ints a vector of integers that will be printed
   */
void YatzyIO::printIntVector(std::vector<int> ints)
{
  cout << "(";
  for (int i = 0; i < ints.size(); i++)
    {
      cout << ints[i];
      if (i != ints.size()-1)
	{
	  cout << (", ");
	}
    }
  cout << ")";
}

/**
   * Prints the a highscore
   *
   * @param highScore the highscore to be printed
   */
void YatzyIO::printHighScore(HighScore highScore)
{
  std::vector<std::string> names = highScore.getNames();
  std::vector<int> scores = highScore.getScores();
  cout << "Highscore:" << endl;
  for (int i = 0; i < 3; i++)
   {
      cout << i+1 << "\t" << names[i] << "\t" << scores[i] << endl;
   }
}
