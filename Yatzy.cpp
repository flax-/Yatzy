#include "Yatzy.h"
#include <string>
#include <algorithm>

Yatzy::Yatzy()
{
  dices.resize(5);
}

/**
   * Queries the player to (R)oll of (Q)uit
   *
   * @return bool True if the player wants to quit and false if the player wants to roll
   */
bool Yatzy::quit()
{
  std::string choice = "";
  while ((choice != "r") || (choice != "q"))
    {
      yatzyIO.print("Do you want to roll (r) or quit (q)? ");
      choice = yatzyIO.readString();
      if (choice == "r")
	{
	  return false;
	}
      else if (choice == "q")
	{
	  return true;
	}
    }  
}

/**
   * Rolls the players hand
   */
void Yatzy::rollHand()
{
  for (int i = 0; i < dices.size(); i++)
    {
      dices[i].rollDie();
    }
}

/**
   * Gets input from the player and rerolls chosen dices
   */
void Yatzy::rollChoice()
{
  for (int rolls = 0; rolls < 2; rolls++)
    {
      yatzyIO.drawDices(dices);
      int nr = -1;
      while ((nr < 0) || (nr > 5))
	{
	  yatzyIO.print("How many dices do you want to reroll?: ");
	  nr = yatzyIO.readInt();
	}
      yatzyIO.print("\n");

      if (nr == 0)
	{
	  break;
	}

      bool rolled [5] = {false, false, false, false, false};
      int choice;

      for (int i = 0; i < nr;)
	{     
	  yatzyIO.print("Choose a dice to reroll: ");
	  choice = yatzyIO.readInt()-1;
	  if (choice < 0 || choice > 4)
	    {
	      yatzyIO.print("Invalid Choice.\n");
	    }
	  else if (!rolled[choice])
	    {
	      rolled[choice] = true;
	      dices[choice].rollDie();
	      i++;
	    }
	  else
	    {
	      yatzyIO.print("You have already rerolled that dice! Choose a new one.\n");
	    }      
	}
    }
  yatzyIO.drawDices(dices);
}

/**
   * Placed the current players hand on the row of choice
   */
void Yatzy::placeHand()
{
  std::vector<int> validRows = yatzyRules.getValidRows(dices);

  // clear valid rows of already placed scores
  int size = validRows.size();
  for (int i = 0; i < size;)
    {
      if (scores[player].scoreSet(validRows[i]-1))
	{
	  validRows.erase(validRows.begin() + i);
	  size--;
	}
      else
	{
	  i++;
	}
    }

  int choice;
  bool placed = false;
  if (validRows.size() == 0)
    {
      std::vector<int> emptyRows;
      for (int i = 0; i < 15; i++)
	{
	  if (!scores[player].scoreSet(i))
	    {
	      emptyRows.insert(emptyRows.end(), i+1);
	    }
	}

      while (!placed)
	{
	  yatzyIO.print("You can't place this hand anywhere. What score do you want to <stryka>?");
	  yatzyIO.printIntVector(emptyRows);
	  choice = yatzyIO.readInt();
	  for (int i = 0; i < emptyRows.size(); i++)
	    {
	      if (choice == emptyRows[i])
		{
		  scores[player].addScore(choice-1, 0);
		  placed = true;
		  break;
		}
	    }
	}
    }
  else
    {
      while (!placed)
	{
	  yatzyIO.print("Where do you want to place the hand? ");
	  yatzyIO.printIntVector(validRows);
	  yatzyIO.print(": ");
	  choice = yatzyIO.readInt();
	  for (int i = 0; i < validRows.size(); i++)
	    {
	      if (choice == validRows[i])
		{
		  scores[player].addScore(choice-1, yatzyRules.placeDice(dices, choice));
		  placed = true;
		  break;
		}
	    }
	}
    }
}

/**
   * Checks if any of the players made the highscore and queries them for their names if so.
   */
void Yatzy::checkHighScores()
{  
  int highest = 0;
  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < scores.size(); j++)
	{
	  if (scores[j].getSum() > scores[highest].getSum())
	    {
	      highest = j;
	    }
	}
      for (int k = 0; k < 3; k++)
	{
	  if (scores[highest].getSum() > highScore.getScores()[k])
	    {
	      highScore.insertPost(getHighScoreName(highest), scores[highest].getSum(), k);
	      scores[highest].clearScore();
	      break;
	    }
	}
    }
  highScore.writeScore();
}

std::string Yatzy::getHighScoreName(int player)
{
  yatzyIO.print("Congratulations player ");
  yatzyIO.print(player + 1);
  yatzyIO.print("! You made the highscore list with ");
  yatzyIO.print(scores[player].getSum());
  yatzyIO.print("!\nPlease enter your name: ");
  return yatzyIO.readString();
}

/**
   * Starts the game of yatzy
   *
   * Only function that will be used from outside the class
   */
void Yatzy::play()
{

  yatzyIO.print("Welcome to Yatzy!\n");
  yatzyIO.printHighScore(highScore);
  yatzyIO.print("How many players are there? ");
  players = yatzyIO.readInt();
  scores.resize(players);
  player = 0;

  
  while (true)
    {
      yatzyIO.print("\n\n\n\nPlayer ");
      yatzyIO.print(player + 1);
      yatzyIO.print(":s turn.\n");

      yatzyIO.printScore(scores[player]);

      // check if the player want to continue playing
      if (quit())
	{
	  break;
	}
      
      // roll the hand
      rollHand();
 
      // Reroll chosen dices
      rollChoice();
     
      // Place the hand on the score.
      yatzyIO.printScore(scores[player]);
      placeHand();
      yatzyIO.printScore(scores[player]);

      player = (player + 1) % players;
    }

  checkHighScores();
  yatzyIO.printHighScore(highScore);
}
