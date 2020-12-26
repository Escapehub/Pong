#include <SFML/Graphics.hpp>

#ifndef BALL
#define BALL

class Ball : public sf::CircleShape
{
public:
  enum State {
    idle,
    moving
  };
private:
  float _speed = 0.2;
public:
  Ball(float, float);
  virtual ~Ball();
  void Update(sf::RenderWindow&);
};

#endif
