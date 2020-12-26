#include <SFML/Graphics.hpp>

#ifndef PADDLE
#define PADDLE

class Paddle : public sf::RectangleShape
{
public:
    enum Player {
        Player1, Player2
    };
private:
    float _x = 20;
    float _y = 100;
    float _speed = 0.2;
public:
    Paddle(Player);
    virtual ~Paddle();
    float getSpeed() { return _speed; }
};

#endif
