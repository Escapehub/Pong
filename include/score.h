#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SCORE
#define SCORE

class Score
{
private:
  int _player1 = 0;
  int _player2 = 0;
  sf::Text _score;
  sf::Font _font;
public:
  Score(float);
  virtual ~Score();
  void addPlayer1();
  void addPlayer2();
  void Reset();
  sf::Text getScore();
};
#endif
