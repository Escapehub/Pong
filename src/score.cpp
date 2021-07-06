#include "score.h"

Score::Score(float width) 
{
  m_font.loadFromFile("assets/fonts/arcade.ttf");

  m_score.setFont(m_font);
  m_score.setCharacterSize(50);
  m_score.setFillColor(sf::Color::White);
  m_score.setPosition(sf::Vector2f((width / 2) - m_score.getScale().x, 50));
}

Score::~Score() 
{

}

void 
Score::addPlayer1() 
{
  m_player1++;
}

void 
Score::addPlayer2() 
{
  m_player2++;
}

void 
Score::Reset() 
{
  m_player1 = 0;
  m_player2 = 0;
}

sf::Text 
Score::getScore()
{
  char buffer[6];
  sprintf(buffer, "%d:%d", this->m_player1, this->m_player2);
  m_score.setString(buffer);
  return m_score;
}
