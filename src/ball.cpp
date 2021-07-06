#include "ball.h"

Ball::Ball(float width, float height) 
{
  this->m_currentState = Ball::State::Idle;
  m_windowWidth = width;
  m_windowHeight = height;
  this->setPosition(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
  this->setRadius(5.0f);
  this->setFillColor(sf::Color::White);
}

Ball::~Ball() {

}

void Ball::Update(sf::RenderWindow& window) 
{
  if (m_currentState != State::Idle) 
  {
    this->move(sf::Vector2f(getSpeed(m_currentState), m_elevation));
    if (this->getPosition().y > window.getSize().y)
      m_elevation *= -1;
    if (this->getPosition().y < 0)
      m_elevation = fabsf(m_elevation);
  }
  window.draw(*this);
}

void Ball::Start() 
{
  int rand = std::rand() % 2 + 1;
  if (rand == 1) {
    m_currentState = State::MovingLeft;
  }
  else {
    m_currentState = State::MovingRight;
  }
  m_elevation = 0.1;
}

void Ball::Reset() 
{
  this->setPosition(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
  m_currentState = State::Idle;
}

void Ball::Deflect() 
{
  if (m_currentState == State::MovingLeft) 
  {
    m_currentState = State::MovingRight;
    m_elevation -= m_elevation * 2;
  }
  else if (m_currentState == State::MovingRight) 
  {
    m_currentState = State::MovingLeft;
    m_elevation += m_elevation * 2;
  }
}

float Ball::getSpeed(State s) 
{
  float m_speed;
  switch (s) {
    case State::Idle:
      m_speed = 0;
      break;
    case State::MovingLeft:
      m_speed = 0.2;
      break;
    case State::MovingRight:
      m_speed = -0.2;
      break;
  }
  return m_speed;
}
