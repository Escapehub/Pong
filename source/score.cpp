#include "../header/score.h"

Score::Score(float width) {
  _font.loadFromFile("fonts/arcade.ttf");

  _score.setFont(_font);
  _score.setCharacterSize(50);
  _score.setFillColor(sf::Color::White);
  _score.setPosition(sf::Vector2f((width / 2) - _score.getScale().x, 50));
}

Score::~Score() {

}

void Score::addPlayer1() {
  _player1++;
}

void Score::addPlayer2() {
  _player2++;
}

void Score::Reset() {
  _player1 = 0;
  _player2 = 0;
}

sf::Text Score::getScore() {
  _score.setString(std::to_string(_player1) + ":" + std::to_string(_player2));
  return _score;
}
