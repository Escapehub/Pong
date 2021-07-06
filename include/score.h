#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef __SCORE__
#define __SCORE__

class Score
{
private:
  int m_player1 = 0;
  int m_player2 = 0;
  sf::Text m_score;
  sf::Font m_font;

public:
  Score(float);
  virtual ~Score();
  void addPlayer1();
  void addPlayer2();
  void Reset();
  sf::Text getScore();
};

#endif // !++SCORE__
