#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#ifndef BALL
#define BALL

class Ball : public sf::CircleShape
{
public:
  enum State {
    Idle, MovingLeft, MovingRight
  };
private:
  State _currentState = State::Idle;
  float _windowWidth, _windowHeight, _elevation;
public:
  Ball(float, float);
  virtual ~Ball();
  void Update(sf::RenderWindow&);
  void Deflect();
  void Start();
  void Reset();
private:
  float getSpeed(State);
};

#endif
