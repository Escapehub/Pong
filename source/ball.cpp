#include "../header/ball.h"

Ball::Ball(float width, float height) {
  _windowWidth = width;
  _windowHeight = height;
  this->setPosition(sf::Vector2f(_windowWidth / 2, _windowHeight / 2));
  this->setRadius(5.0f);
  this->setFillColor(sf::Color::White);
}

Ball::~Ball() {

}

void Ball::Update(sf::RenderWindow& window) {
  if (_currentState != State::Idle) {
    this->move(sf::Vector2f(getSpeed(_currentState), _elevation));
    if (this->getPosition().y > window.getSize().y)
      _elevation *= -1;
    if (this->getPosition().y < 0)
      _elevation = fabsf(_elevation);
  }
  window.draw(*this);
}

void Ball::Start() {
  int rand = std::rand() % 2 + 1;
  if (rand == 1) {
    _currentState = State::MovingLeft;
  }
  else {
    _currentState = State::MovingRight;
  }
  _elevation = 0.1;
}

void Ball::Reset() {
  this->setPosition(sf::Vector2f(_windowWidth / 2, _windowHeight / 2));
  _currentState = State::Idle;
}

void Ball::Deflect() {
  if (_currentState == State::MovingLeft) {
    _currentState = State::MovingRight;
    _elevation -= _elevation * 2;
  }
  else if (_currentState == State::MovingRight) {
    _currentState = State::MovingLeft;
    _elevation += _elevation * 2;
  }
}

float Ball::getSpeed(State s) {
  float _speed;
  switch (s) {
    case State::Idle:
      _speed = 0;
      break;
    case State::MovingLeft:
      _speed = 0.2;
      break;
    case State::MovingRight:
      _speed = -0.2;
      break;
  }
  return _speed;
}
