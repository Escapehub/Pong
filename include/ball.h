#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#ifndef __BALL__
#define __BALL__

class Ball : public sf::CircleShape
{
public:
  enum State {
    Idle, MovingLeft, MovingRight
  };

private:
  State m_currentState;
  float m_windowWidth;
  float m_windowHeight;
  float m_elevation;

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

#endif // !__BALL__
